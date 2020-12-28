#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// ll ex_gcd(ll a, ll b, ll &x, ll &y) {
//   if (b == 0) {
//     x = 1;
//     y = 0;
//     return a;
//   }
//   ll d = ex_gcd(b, a % b, x, y);
//   ll temp = x;
//   x = y;
//   y = temp - a / b * y;
//   return d;
// }
void exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
ll CRT(ll k, vector<ll> &a, vector<ll> &r) {
  ll n = 1, ans = 0;
  for (ll i = 0; i < k; ++i) {
    n *= r[i];
  }
  for (ll i = 0; i < k; ++i) {
    ll m = n / r[i], b, y;
    exgcd(m, r[i], b, y);
    ans = (ans + a[i] * m * b % n) % n;
  }
  return (ans % n + n) % n;
}
vector<ll> a = {4, 5, 7, 9, 11, 13, 17, 19, 23};
// vector<ll> a = {4};
int main() {
  assert(accumulate(a.begin(), a.end(), 0LL) <= 110);
  ll n = (ll)a.size();
  ll m = accumulate(a.begin(), a.end(), 0LL);
  cout << m << endl;
  ll cur = 0;
  vector<ll> ask;
  for (ll i = 0; i < n; ++i) {
    for (ll j = 0; j + 1 < a[i]; j++) {
      ask.emplace_back(cur + j + 1);
    }
    ask.emplace_back(cur);
    cur += a[i];
  }
  for (auto &i : ask) {
    cout << i + 1 << " ";
  }
  cout << endl;
  vector<ll> b(m + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
  }
  cur = 1;
  ll t = 0;
  vector<ll> r(n);
  for (ll i = 1; i <= m; ++i) {
    if (i == cur) {
      ll res = b[i] - i;
      cur += a[t];
      r[t] = res;
      t++;
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << a[i] << " " << r[i] << endl;
  // }
  cout << CRT(n, r, a) << endl;
}