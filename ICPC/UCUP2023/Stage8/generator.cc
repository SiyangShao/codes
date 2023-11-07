#include <bits/stdc++.h>
#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
int n = 8;
constexpr int N = 1e9;
auto solve() {
  cout << n << "\n";
  for (int i = 0; i < n; ++i) {
    int rd = rand() % N;
    cout << rd + 1 << " ";
  }
  cout << "\n";
}
auto main(int argc, char *argv[]) -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  srand(time(nullptr));
  int _ = std::stoi(argv[1]);
  n = stoi(argv[2]);
  cout << _ << "\n";
  while (_--) {
    solve();
  }
}