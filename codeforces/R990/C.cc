#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pll = pair<ll, ll>;
using ordered_multiset = tree<pll, null_type, less<pll>, rb_tree_tag,
                              tree_order_statistics_node_update>;
tuple<bool, ll, ll> find_range(ordered_multiset &st, ll k) {
  if (st.size() < 2 * k) {
    return {false, -1, -1};
  }
  auto litr = st.find_by_order(k - 1);
  if (litr == st.end()) {
    return {false, -1, -1};
  }
  ll lef = litr->first;

  auto ritr = st.find_by_order(st.size() - k);
  if (ritr == st.end()) {
    return {false, -1, -1};
  }
  ll rig = ritr->first - 1;
  if (lef > rig) {
    return {false, -1, -1};
  }
  // cout << "FIND!!!\n";
  // cout << lef << " to " << rig << ", and is " << k << "\n";
  // for (auto it : st) {
  //   cout << it.first << ", " << it.second << "\n";
  // }
  // cout << "=================\n";
  return {true, lef, rig};
}
auto solve() {
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll>> p(n);
  ll cnt = 0;
  map<ll, vector<pair<ll, ll>>> mp;
  for (auto &[x, y, id] : p) {
    cin >> x >> y;
    x = -x;
    y = -y;
    id = cnt++;
    mp[x].emplace_back(y, id);
  }
  sort(p.begin(), p.end());
  auto check = [&](ll k) -> tuple<bool, ll, ll> {
    if (k == 0) {
      return {true, get<0>(p[0]), get<1>(p[0])};
    }
    ordered_multiset lef, rig;
    for (auto &[_, vec] : mp) {
      for (auto i : vec) {
        rig.insert(i);
      }
    }
    for (auto &[x, vec] : mp) {
      for (auto i : vec) {
        lef.insert(i);
        rig.erase(i);
      }
      auto [flagL, lLef, rLef] = find_range(lef, k);
      auto [flagR, lRig, rRig] = find_range(rig, k);
      if (!flagL || !flagR)
        continue;
      if (max(lLef, lRig) > min(rLef, rRig))
        continue;
      return {true, x, max(lLef, lRig)};
    }
    return {false, -1, -1};
  };
  ll l = 0, r = n / 4, ans = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    auto [flag, x, y] = check(mid);
    if (flag) {
      l = mid + 1;
      ans = max(ans, mid);
    } else {
      r = mid - 1;
    }
  }
  auto [_, x, y] = check(ans);
  cout << ans << "\n" << -x << " " << -y << "\n";
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
