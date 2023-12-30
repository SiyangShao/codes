#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
auto topo(const vector<vector<int>> &E, vector<int> in, int n, auto &Q) {
  for (int i = 0; i < n; ++i) {
    if (in[i] == 0)
      Q.emplace(i);
  }
  vector<int> ans;
  while (!Q.empty()) {
    auto u = Q.top();
    Q.pop();
    ans.emplace_back(u);
    for (auto v : E[u]) {
      in[v]--;
      if (in[v] == 0)
        Q.emplace(v);
    }
  }
  return ans;
}
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<vector<int>> E(n);
  for (auto &i : a) {
    cin >> i;
    i--;
  }
  for (auto &i : b) {
    cin >> i;
    i--;
  }
  stack<int> st;
  vector<int> in(n);
  vector<pair<int, int>> edg;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] < a[i]) {
      st.pop();
    }
    if (!st.empty()) {
      E[a[st.top()]].emplace_back(a[i]);
      edg.emplace_back(a[st.top()], a[i]);
      in[a[i]]++;
    }
    st.emplace(i);
  }
  while (!st.empty())
    st.pop();
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && b[st.top()] > b[i]) {
      st.pop();
    }
    if (!st.empty()) {
      E[b[st.top()]].emplace_back(b[i]);
      edg.emplace_back(b[st.top()], b[i]);
      in[b[i]]++;
    }
    st.emplace(i);
  }
  priority_queue<int> Q;
  auto y = topo(E, in, n, Q);
  priority_queue<int, vector<int>, greater<>> pQ;
  auto x = topo(E, in, n, pQ);
  dbg(x, a, y, b);
  if (x != a || y != b) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << edg.size() << "\n";
    for (auto [u, v] : edg) {
      cout << u + 1 << " " << v + 1 << "\n";
    }
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}