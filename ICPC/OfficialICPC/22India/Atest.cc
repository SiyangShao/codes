#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void process(ll &x, ll res) {
  for (ll i = res - 1; i >= 0; --i) {
    if ((x >> i) & 1) {
      for (int j = 0; j < i; ++j) {
        x |= (1LL << j);
      }
      break;
    }
  }
}
int main() {
  ll x, res, zero;
  cin >> x >> res >> zero;
  process(x, res);
  cout << x << "\n";
}