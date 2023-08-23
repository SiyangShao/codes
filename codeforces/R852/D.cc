#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> p(n), q(n), in_p(n + 1), in_q(n + 1);
  for (auto &i : p)
    cin >> i, i--;
  for (auto &i : q)
    cin >> i, i--;
  vector<int> pos_p(n), pos_q(n);
  for (int i = 0; i < n; ++i) {
    pos_p[p[i]] = i;
    pos_q[q[i]] = i;
  }
  ll ans = 1;
  int l_p, r_p, l_q, r_q;
  int mx_p = 1, mx_q = 1;
  auto extendP = [&](int x) {
    for (int i = l_p; i >= pos_p[x]; --i) {
      in_p[p[i]] = 1;
    }
    for (int i = r_p; i <= pos_p[x]; ++i) {
      in_p[p[i]] = 1;
    }
    l_p = min(l_p, pos_p[x]);
    r_p = max(r_p, pos_p[x]);
    while (in_p[mx_p]) {
      mx_p++;
    }
  };
  auto extendQ = [&](int x) {
    for (int i = l_q; i >= pos_q[x]; --i) {
      in_q[q[i]] = 1;
    }
    for (int i = r_q; i <= pos_q[x]; ++i) {
      in_q[q[i]] = 1;
    }
    l_q = min(l_q, pos_q[x]);
    r_q = max(r_q, pos_q[x]);
    while (in_q[mx_q]) {
      mx_q++;
    }
  };
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      l_p = r_p = pos_p[0];
      l_q = r_q = pos_q[0];
      int l_len = min(pos_p[0], pos_q[0]);
      int r_len = n - 1 - max(pos_p[0], pos_q[0]);
      int mid_len = max(pos_q[0], pos_p[0]) - min(pos_p[0], pos_q[0]);
      mid_len--;
      if (mid_len > 0) {
        ans += (1LL + mid_len) * mid_len / 2;
      }
      ans += (1LL + l_len) * l_len / 2;
      ans += (1LL + r_len) * r_len / 2;
      in_p[0] = in_q[0] = 1;
    } else {
      if (mx_p > i || mx_q > i) {
        extendP(i);
        extendQ(i);
        continue;
      }
      // cout << mx_p << " " << mx_q << " " << i << "\n";
      assert(mx_p == i && mx_q == i);
      assert(pos_p[i] < l_p || pos_p[i] > r_p);
      assert(pos_q[i] < l_q || pos_q[i] > r_q);
      int c_p_l_l, c_p_l_r, c_p_r_l, c_p_r_r;
      if (pos_p[i] < l_p) {
        c_p_l_l = pos_p[i] + 1;
        c_p_l_r = l_p;
        c_p_r_l = r_p;
        c_p_r_r = n - 1;
      } else {
        c_p_l_l = 0;
        c_p_l_r = l_p;
        c_p_r_l = r_p;
        c_p_r_r = pos_p[i] - 1;
      }
      int c_q_l_l, c_q_l_r, c_q_r_l, c_q_r_r;
      if (pos_q[i] < l_q) {
        c_q_l_l = pos_q[i] + 1;
        c_q_l_r = l_q;
        c_q_r_l = r_q;
        c_q_r_r = n - 1;
      } else {
        c_q_l_l = 0;
        c_q_l_r = l_q;
        c_q_r_l = r_q;
        c_q_r_r = pos_q[i] - 1;
      }
      int L_len = max(0, min(c_q_l_r, c_p_l_r) - max(c_q_l_l, c_p_l_l) + 1);
      int R_len = max(0, min(c_q_r_r, c_p_r_r) - max(c_q_r_l, c_p_r_l) + 1);
      ans += (ll)L_len * R_len;
      extendP(i);
      extendQ(i);
    }
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}