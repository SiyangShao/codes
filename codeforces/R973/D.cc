#include "dbg.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  ll sum = a[n - 1], num = 1;
  priority_queue<ll, vector<ll>, greater<>> Q;
  for (int i = n - 2; i >= 0; --i) {
    auto avg = sum / num;
    if (a[i] >= avg) {
      ll res = a[i] - avg;
      sum += avg;
      num++;
      while (!Q.empty() && res > 0) {
        auto x = Q.top();
        Q.pop();
        ll x_need = avg - x;
        if (x_need > res) {
          Q.emplace(x + res);
          break;
        } else {
          res -= x_need;
          sum += avg;
          num++;
        }
      }
      if (res > 0) {
        sum += res;
      }
    } else {
      while (!Q.empty()) {
        auto x = Q.top();
        if (a[i] <= x) {
          Q.emplace(a[i]);
          break;
        }
        // a[i] > x
        Q.pop();
        // choose avg 
      }
    }
  }
  ll mx = sum / num + (sum % num == 0 ? 0 : 1);
  ll mi = (!Q.empty() ? Q.top() : sum / num);
  cout << mx - mi << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
