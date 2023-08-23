#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  string A, B;
  cin >> A >> B;
  ll base = 1;
  ll large = 0, small = 0;
  for (ll i = n - 1; i >= 0; --i) {
    if (A[i] >= B[i]) {
      large = large + base * (A[i] - '0');
      small = small + base * (B[i] - '0');
      large %= MOD, small %= MOD;
    } else {
      swap(A[i], B[i]);
      large = large + base * (A[i] - '0');
      small = small + base * (B[i] - '0');
      large %= MOD, small %= MOD;
    }
    base *= 10;
    base %= MOD;
  }
  cout << large * small % MOD << "\n";
}