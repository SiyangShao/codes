#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<tuple<ll, ll, ll, ll>> rec(n);
  vector<vector<tuple<ll, ll, ll>>> a(3);
  int tmp_id = 0;
  for (auto &[u, l, d, r] : rec) {
    cin >> u >> l >> d >> r;
    if (u == d) {
      a[u].emplace_back(l, r, tmp_id);
    } else {
      a[0].emplace_back(l, r, tmp_id);
    }
    tmp_id++;
  }
  for (int i = 0; i < 3; ++i) {
    if (a[i].empty())
      continue;
    sort(a[i].begin(), a[i].end());
    auto [l, r, _] = a[i][0];
    for (int j = 1; j < (int)a[i].size(); ++j) {
      auto [cur_l, cur_r, _] = a[i][j];
      if (cur_r <= r) {
        cur_l = cur_r = 0;
      } else {
        cur_l = max(cur_l, r + 1);
        r = cur_r;
      }
      a[i][j] = {cur_l, cur_r, _};
      assert(cur_l <= cur_r);
    }
  }
  int up_id = 0, low_id = 0, up_siz = (int)a[1].size(),
      low_siz = (int)a[2].size();
  auto square = &a[0], up = &a[1], low = &a[2];
  vector<int> status(square->size(), 0);
  for (int i = 0; i < (int)square->size(); ++i) {
    auto [l, r, id] = (*square)[i];
    while (up_id < up_siz) {
      assert(up_id < up_siz);
      auto [up_l, up_r, u_id] = (*up)[up_id];
      if (up_l == 0) {
        (*up)[up_id] = {up_l, up_r, u_id};
        up_id++;
        continue;
      }
      if (up_r < l) {
        (*up)[up_id] = {up_l, up_r, u_id};
        up_id++;
        continue;
      }
      if (up_l > r)
        break;
      if (up_l < l && up_r > r) {
        status[i] = 1;
        assert(up_id < up_siz);
        (*up)[up_id] = {up_l, up_r, u_id};
        break;
      }
      if (up_l >= l && up_r <= r) {
        up_l = up_r = 0;
        (*up)[up_id] = {up_l, up_r, u_id};
        up_id++;
        continue;
      }
      if (up_l < l) {
        assert(up_r >= l && up_r <= r);
        up_r = min(up_r, l - 1);
        assert(up_r >= up_l);
        (*up)[up_id] = {up_l, up_r, u_id};
        up_id++;
        continue;
      } else {
        assert(up_l >= l && up_l <= r);
        assert(up_r > r);
        up_l = max(up_l, r + 1);
        assert(up_r >= up_l);
        (*up)[up_id] = {up_l, up_r, u_id};
        break;
      }
    }
    while (low_id < low_siz) {
      auto [low_l, low_r, l_id] = (*low)[low_id];
      if (low_l == 0) {
        (*low)[low_id] = {low_l, low_r, l_id};
        low_id++;
        continue;
      }
      if (low_r < l) {
        (*low)[low_id] = {low_l, low_r, l_id};
        low_id++;
        continue;
      }
      if (low_l > r)
        break;
      if (low_l < l && low_r > r) {
        if (status[i] == 1)
          status[i] = 3;
        else
          status[i] = 2;
        (*low)[low_id] = {low_l, low_r, l_id};
        break;
      }
      if (low_l >= l && low_r <= r) {
        low_l = low_r = 0;
        (*low)[low_id] = {low_l, low_r, l_id};
        low_id++;
        continue;
      }
      if (low_l < l) {
        assert(low_r >= l && low_r <= r);
        low_r = min(low_r, l - 1);
        assert(low_r >= low_l);
        (*low)[low_id] = {low_l, low_r, l_id};
        low_id++;
        continue;
      } else {
        assert(low_r > r && low_l >= l && low_l <= r);
        low_l = max(low_l, r + 1);
        assert(low_l <= low_r);
        (*low)[low_id] = {low_l, low_r, l_id};
        break;
      }
    }
  }
  vector<array<ll, 4>> ans(n);
  for (int i = 0; i < (int)a[0].size(); ++i) {
    auto [l, r, id] = a[0][i];
    if (l > r || l == 0) {
      ans[id][0] = ans[id][1] = ans[id][2] = ans[id][3] = 0;
      continue;
    }
    if (status[i] == 0) {
      ans[id][0] = 1, ans[id][1] = l, ans[id][2] = 2, ans[id][3] = r;
    } else if (status[i] == 3) {
      ans[id][0] = ans[id][1] = ans[id][2] = ans[id][3] = 0;
    } else
      ans[id][0] = 3 - status[i], ans[id][1] = l, ans[id][2] = 3 - status[i],
      ans[id][3] = r;
  }
  for (int i = 0; i < (int)a[1].size(); ++i) {
    auto [l, r, id] = a[1][i];
    if (l > r || l == 0) {
      ans[id][0] = ans[id][1] = ans[id][2] = ans[id][3] = 0;
      continue;
    }
    if (l == 0) {
      ans[id][0] = ans[id][1] = ans[id][2] = ans[id][3] = 0;
      continue;
    }
    ans[id][0] = ans[id][2] = 1;
    ans[id][1] = l, ans[id][3] = r;
  }
  for (int i = 0; i < (int)a[2].size(); ++i) {
    auto [l, r, id] = a[2][i];
    if (l > r || l == 0) {
      ans[id][0] = ans[id][1] = ans[id][2] = ans[id][3] = 0;
      continue;
    }
    if (l == 0) {
      ans[id][0] = ans[id][1] = ans[id][2] = ans[id][3] = 0;
      continue;
    }
    ans[id][0] = ans[id][2] = 2;
    ans[id][1] = l, ans[id][3] = r;
  }
  ll sum = 0;
  for (auto &vec : ans) {
    ll l = vec[1], r = vec[3];
    if (l == 0)
      continue;
    if (vec[0] == vec[2]) {
      sum += (r - l + 1);
    } else {
      sum += (r - l + 1) * 2;
    }
  }
  cout << sum << "\n";
  for (auto &vec : ans) {
    cout << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << "\n";
  }
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