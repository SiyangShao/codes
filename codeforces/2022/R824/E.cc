#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  vector<ll> __d1(n), __d2(n);
  for (auto &i : __d1) {
    cin >> i;
  }
  for (auto &i : __d2) {
    cin >> i;
  }
  function<bool(ll)> cal = [&](ll l) {
    // l is the distance between p1 and p2
    ll p1 = 0, p2 = l;
    multiset<ll> d1, d2;
    d1.clear(), d2.clear();
    for (ll i = 0; i < n; ++i) {
      d1.emplace(__d1[i]);
      d2.emplace(__d2[i]);
    }
    vector<ll> ans;
    while (!d1.empty() && !d2.empty()) {
      auto left = d1.rbegin();
      auto right = d2.rbegin();
      if (*left >= *right) {
        if (*left < l) {
          break;
        }
        ll res = *left - l;
        auto ll = d1.lower_bound(res + l);
        auto rr = d2.lower_bound(res);
        if (rr == d2.end() || *rr != res) {
          return false;
        }
        d1.erase(ll);
        d2.erase(rr);
        ans.emplace_back(res + l);
      } else {
        if (*right < l) {
          break;
        }
        ll res = *right - l;
        auto ll = d1.lower_bound(res);
        auto rr = d2.lower_bound(res + l);
        if (ll == d1.end() || *ll != res) {
          return false;
        }
        d1.erase(ll);
        d2.erase(rr);
        ans.emplace_back(-res);
      }
    }
    if (!d1.empty() && !d2.empty()) {
      vector<ll> L, R;
      for (auto &i : d1) {
        L.emplace_back(i);
      }
      for (auto &i : d2) {
        R.emplace_back(l - i);
      }
      reverse(R.begin(), R.end());
      if (L != R) {
        return false;
      }
      for (auto &i : L) {
        ans.emplace_back(i);
      }
    }
    ll mi = *min_element(ans.begin(), ans.end());
    if (mi < 0) {
      mi = abs(mi);
      p1 += abs(mi);
      p2 += mi;
      for (auto &i : ans) {
        i += mi;
      }
    }
    cout << "YES\n";
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
    cout << p1 << " " << p2 << "\n";
    return true;
  };
  for (ll i = 0; i < n; ++i) {
    if (cal(__d1[0] + __d2[i])) {
      return;
    }
    if (cal(abs(__d1[0] - __d2[i]))) {
      return;
    }
  }
  cout << "NO\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}