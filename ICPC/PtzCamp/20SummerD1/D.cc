#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll>> pre(n);
  vector<tuple<ll, ll, ll>> vec;
  {
    vector<pair<ll, ll>> x, y;
    for (auto &[l, a, b] : pre) {
      cin >> l >> a >> b;
      x.emplace_back(a, l);
      y.emplace_back(b, l);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0; i < n; ++i) {
      // cout << x[i].first << " " << x[i].second << " " << y[i].first << " "
      //  << y[i].second << endl;
    }
    int i = 0, j = 0;
    while (i < n && j < n) {
      auto [a, l] = x[i];
      auto [b, m] = y[j];
      // cout<<i<<" "<<j<<" "<<l<<" "<<m<<endl;
      if (l <= m) {
        vec.emplace_back(l, a, b);
        i++;
        y[j].second -= l;
        if (y[j].second == 0) {
          j++;
        }
      } else {
        vec.emplace_back(m, a, b);
        j++;
        x[i].second -= m;
        if (x[i].second == 0) {
          i++;
        }
      }
    }
  }
  // cout << vec.size() << "\n";
  multiset<pair<ll, ll>> hot, cold;
  ll sum = 0;
  for (auto &[a, b, c] : vec) {
    // cin >> a >> b >> c;
    // cout << a << " " << b << " " << c << endl;
    if (b > c) {
      hot.emplace(b, (b - c) * a);
    } else if (b < c) {
      cold.emplace(c, (c - b) * a);
    }
    sum += a * b;
    sum -= a * c;
  }
  if (sum != 0) {
    cout << "NIE\n";
    return;
  }
  while (!cold.empty()) {
    auto [temp, eng] = *prev(cold.end());
    while (eng != 0) {
      auto it = hot.lower_bound({temp, 0});
      if (it == hot.end()) {
        cout << "NIE\n";
        return;
      }
      auto [htemp, heng] = *it;
      hot.erase(it);
      if (heng <= eng) {
        eng -= heng;
      } else {
        hot.emplace(htemp, heng - eng);
        eng = 0;
      }
    }
    cold.erase(prev(cold.end()));
  }
  if (!hot.empty()) {
    cout << "NIE\n";
    return;
  }
  cout << "TAK\n";
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