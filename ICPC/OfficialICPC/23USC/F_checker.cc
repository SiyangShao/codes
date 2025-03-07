#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
array<string, 3> c;
array<char, 3> name;
void central(int p){
  for(int i = 0 ; i < 3; ++i){
    if(p == 1){
      auto tmp = c[0][i];
      c[0][i] = c[1][i];
      c[1][i] = c[2][i];
      c[2][i] = tmp;
    }else{
      assert(p == 2);
    }
  }
}
auto solve() {
  for (auto &i : c)
    cin >> i;
  int op;
  cin >> op;
  while (op--) {
    string s;
    cin >> s;
    if (s[0] == 'c') {
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