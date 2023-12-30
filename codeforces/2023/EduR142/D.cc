#include <bits/stdc++.h>
using namespace std;
struct Trie {
  int tot{0};
  int n;
  vector<vector<int>> ch;
  vector<int> base;
  Trie(int _) : n(_), base(_) { ch.push_back(base); };
  void add(vector<int> &x) {
    for (int i = 0, u = 0; i < n; ++i) {
      int c = x[i];
      if (!ch[u][c])
        ch[u][c] = ++tot, ch.push_back(base);
      u = ch[u][c];
    }
  }
  int ask(vector<int> &x) {
    int res = 0;
    for (int i = 0, u = 0; i < n; ++i) {
      int c = x[i];
      if (ch[u][c]) {
        u = ch[u][c];
        res++;
      } else {
        u = ch[u][c];
        return res;
      }
    }
    return res;
  }
};
auto solve() {
  int n, m;
  cin >> n >> m;
  Trie t(m);
  vector mp(n, vector<int>(m));
  for (auto &i : mp) {
    for (auto &j : i) {
      cin >> j;
      j--;
    }
  }
  for (int i = 0; i < n; ++i) {
    vector<int> pos(m);
    for (int j = 0; j < m; ++j) {
      pos[mp[i][j]] = j;
    }
    t.add(pos);
    // for(auto j : pos){
    //   cout << j + 1 << " ";
    // }
    // cout << "\n";
  }
  for (int i = 0; i < n; ++i) {
    cout << t.ask(mp[i]) << " ";
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}