#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n;
  cin >> n;
  vector<ll> m(n), p(n);
  ll bs = 0;
  for (auto &i : m) {
    cin >> i;
    bs += i;
  }
  for (auto &i : p) {
    cin >> i;
  }
  for (ll i = 0; i < n; ++i) {
    p[i] += m[i];
  }
  vector<ll> help(n);
  iota(help.begin(), help.end(), 0);
  sort(help.begin(), help.end(), [&](auto l, auto r) { return p[l] > p[r]; });
  vector<ll> pre(n + 1), suf(n + 1);
  function<bool(ll)> check = [&](ll x) {
    priority_queue<ll, vector<ll>, greater<>> largeQ;
    priority_queue<ll> smallQ;
    ll cnt = 0;
    for (ll id = 0; id < x; ++id) {
      auto i = help[id];
      largeQ.emplace(m[i]);
      cnt += m[i];
      pre[id] = cnt;
    }
    for (ll id = x; id < n; ++id) {
      auto i = help[id];
      if (largeQ.top() < m[i]) {
        cnt += m[i] - largeQ.top();
        largeQ.pop();
        largeQ.emplace(m[i]);
      }
      pre[id] = cnt;
    }
    cnt = 0;
    for (ll id = n - 1; id >= (n - x); --id) {
      auto i = help[id];
      smallQ.emplace(p[i] - m[i]);
      cnt += p[i] - m[i];
      suf[id] = cnt;
    }
    for (ll id = (n - x - 1); id >= 0; --id) {
      auto i = help[id];
      if (smallQ.top() > p[i] - m[i]) {
        cnt += p[i] - m[i] - smallQ.top();
        smallQ.pop();
        smallQ.emplace(p[i] - m[i]);
      }
      suf[id] = cnt;
    }
    for (ll i = x - 1; i < n - x; ++i) {
      if (pre[i] >= suf[i + 1])
        return true;
    }
    return false;
  };
  ll L = 1, R = n / 2;
  ll ans = 0;
  while (L <= R) {
    ll mid = (L + R) / 2;
    if (check(mid)) {
      ans = max(ans, mid);
      L = mid + 1;
    } else {
      R = mid - 1;
    }
  }
  cout << ans << "\n";
}