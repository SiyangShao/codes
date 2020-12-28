#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
int query(int i) {
  cout << "? " << i + 1 << "\n";
  cout.flush();
  char s;
  cin >> s;
  if (s == '=')
    return 0;
  else if (s == '<')
    return -1;
  else
    return 1;
}
void cal(vector<int> &a, vector<int> &ord) {
  if (a.empty())
    return;
  int mid = (int)rand() % (int)a.size();
  while (query(a[mid]) != 0)
    ;
  vector<int> l, r;
  for (auto i : a) {
    if (i == a[mid])
      continue;
    int val = query(i);
    if (val == -1) {
      l.emplace_back(i);
    } else {
      assert(val == 1);
      r.emplace_back(i);
    }
    query(a[mid]);
  }
  vector<int> l_ord, r_ord;
  cal(l, l_ord);
  cal(r, r_ord);
  for (auto i : l_ord)
    ord.emplace_back(i);
  ord.emplace_back(a[mid]);
  for (auto i : r_ord)
    ord.emplace_back(i);
}
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n), ord, ans(n);
  iota(a.begin(), a.end(), 0);
  cal(a, ord);
  for (int i = 0; i < n; ++i)
    ans[ord[i]] = i;
  cout << "! ";
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
  cout << "\n";
  cout.flush();
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  srand(time(nullptr));
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}