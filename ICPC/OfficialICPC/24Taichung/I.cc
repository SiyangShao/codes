#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e6 + 5;
array<map<char, int>, N> nxt;
array<set<int>, N> endpoint;
array<set<tuple<int, char, int>>, N> effective_nxt;
array<int, N> dp;
map<int, string> pattern;
int tot;
struct target {
  vector<int> s;
  void append(string &t) {
    int pos = (s.empty() ? 0 : s.back());
    for (auto i : t) {
      if (nxt[pos].contains(i)) {
        pos = nxt[pos][i];
      } else {
        nxt[pos][i] = ++tot;
        pos = tot;
      }
      s.emplace_back(pos);
    }
  }
  int get() {
    if (s.empty())
      return 0;
    return s.back();
  }
  void backspace(int len) {
    if (len >= s.size()) {
      s.clear();
      return;
    }
    while (len--) {
      s.pop_back();
    }
  }
} t;
auto upd(int id) {
  if (endpoint[id].empty() && effective_nxt[id].empty()) {
    dp[id] = -1;
    return;
  }
  if (!effective_nxt[id].empty()) {
    auto [len, val, i] = *effective_nxt[id].begin();
    dp[id] = dp[nxt[id][val]];
    return;
  }
  if (!endpoint[id].empty()) {
    dp[id] = *endpoint[id].begin();
  }
}
void add(int id, string &s) {
  pattern[id] = s;
  int cur = 0;
  vector<int> cur_list;
  for (auto i : s) {
    cur_list.emplace_back(cur);
    effective_nxt[cur].emplace(-s.length(), i, id);
    if (nxt[cur].contains(i)) {
      cur = nxt[cur][i];
    } else {
      nxt[cur][i] = ++tot;
      cur = tot;
    }
  }
  cur_list.emplace_back(cur);
  endpoint[cur].emplace(id);
  reverse(cur_list.begin(), cur_list.end());
  for (auto i : cur_list) {
    upd(i);
  }
}
void del(int id) {
  string s = pattern[id];
  int cur = 0;
  vector<int> cur_list;
  for (auto i : s) {
    cur_list.emplace_back(cur);
    cur = nxt[cur][i];
  }
  cur_list.emplace_back(cur);
  cur = 0;
  for (auto i : s) {
    int j = nxt[cur][i];
    effective_nxt[cur].erase({-s.length(), i, id});
    cur = j;
  }
  reverse(cur_list.begin(), cur_list.end());
  endpoint[cur].erase(id);
  for (auto i : cur_list) {
    upd(i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  tot = 0;
  fill(dp.begin(), dp.end(), -1);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s == "add") {
      int id;
      string pat;
      cin >> id >> pat;
      add(id, pat);
    } else if (s == "append") {
      string pat;
      cin >> pat;
      t.append(pat);
    } else if (s == "backspace") {
      int i;
      cin >> i;
      t.backspace(i);
    } else {
      int id;
      cin >> id;
      del(id);
    }
    cout << dp[t.get()] << "\n";
  }
}
