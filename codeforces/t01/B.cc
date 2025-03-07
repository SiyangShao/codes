#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 800000;
struct Trie {
  std::vector<std::array<int, 26>> nxt;
  std::vector<std::set<int>> exist;
  std::vector<std::set<int>> exist2;
  map<int, pair<int, int>> mp;
  int cnt;
  Trie() : nxt(N, std::array<int, 26>{}), exist(N), exist2(N), cnt(0) {}
  void insert(string &s, int id) {
    int p = 0;
    for (auto i : s) {
      int c = i - 'a';
      if (!nxt[p][c]) {
        nxt[p][c] = ++cnt;
      }
      exist[p].emplace(id);
      p = nxt[p][c];
    }
    exist[p].emplace(id);
  }
  void erase(string &s, int id, set<pair<int, int>> &st, int nid) {
    int p = 0;
    stack<int> stk;
    stk.emplace(p);
    for (auto i : s) {
      int c = i - 'a';
      if (!nxt[p][c]) {
        assert(false);
      }
      p = nxt[p][c];
      stk.emplace(p);
    }
    vector<int> del;
    bool flag = false;
    while (!stk.empty()) {
      p = stk.top();
      if (p == mp[nid].first) {
        // cout << "at " << p << " with " << nid << endl;
        flag = true;
      }
      stk.pop();
      exist[p].erase(id);
      exist2[p].erase(nid);
      if (exist[p].empty()) {
        for (auto it : exist2[p]) {
          // cout << "del " << it + 1 << " from " << p << endl;
          del.emplace_back(it);
        }
        exist2[p].clear();
      } else {
        for (auto it : del) {
          if (it == nid)
            continue;
          // cout << "add back " << it + 1 << " at " << p << endl;
          exist2[p].emplace(it);
          st.erase({-mp[it].second, it});
          mp[it] = {p, (int)stk.size()};
          st.emplace(-mp[it].second, it);
        }
        del.clear();
      }
    }
    assert(flag);
  }
  int query_match(int id) {
    auto [p, len] = mp[id];
    assert(!exist[p].empty());
    return *exist[p].begin();
  }
  int insert2(string &s, int id) {
    int p = 0;
    int len = 0;
    for (auto i : s) {
      int c = i - 'a';
      if (!nxt[p][c]) {
        break;
      }
      len++;
      p = nxt[p][c];
      mp[id] = {p, len};
    }
    exist2[p].emplace(id);
    return len;
  }
};
auto solve() {
  Trie trie;
  int n;
  cin >> n;
  vector<string> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    trie.insert(a[i], i);
  }
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    int len = trie.insert2(b[i], i);
    st.emplace(-len, i);
  }
  vector<pair<int, int>> ans;
  int tot = 0;
  while (!st.empty()) {
    // for (auto [neglen, id] : st) {
    //   cout << -neglen << " " << id + 1 << " *** ";
    // }
    // cout << endl;
    auto [neglen, id] = *st.begin();
    st.erase({neglen, id});
    int len = -neglen;
    tot += len;
    int match = trie.query_match(id);
    // cout << "Find " << match + 1 << " and " << id + 1 << endl;
    ans.emplace_back(match, id);
    trie.erase(a[match], match, st, id);
  }
  cout << tot << "\n";
  for (auto [u, v] : ans) {
    cout << u + 1 << " " << v + 1 << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
