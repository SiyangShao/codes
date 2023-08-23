#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll log2(ll x) {
  ll cnt = 0;
  while (x) {
    x /= 2;
    cnt++;
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    ll n, d;
    cin >> n >> d;
    n--;
    ll x = (n + d - 1) / d;
    cout << log2(x) << "\n";
  }
}