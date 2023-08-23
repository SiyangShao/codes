#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T> class SparseTable {
  using VT = vector<T>;
  using VVT = vector<VT>;
  using func_type = function<T(const T &, const T &)>;

  VVT ST;

  static T default_func(const T &t1, const T &t2) { return max(t1, t2); }

  func_type op;

public:
  SparseTable(const vector<T> &v, func_type _func = default_func) {
    op = _func;
    int len = v.size(), l1 = (int)ceil(log2(len)) + 1;
    ST.assign(len, VT(l1, 0));
    for (int i = 0; i < len; ++i) {
      ST[i][0] = v[i];
    }
    for (int j = 1; j < l1; ++j) {
      int pj = (1 << (j - 1));
      for (int i = 0; i + pj < len; ++i) {
        ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  T query(int l, int r) {
    if (l == r) {
      return ST[l][0];
    }
    int lt = r - l + 1;
    int q = (int)ceil(log2(lt)) - 1;
    return op(ST[l][q], ST[r - (1 << q) + 1][q]);
  }
};
/**
 * @brief
 * Observation: Getting a DAG, each node is connected to it's left_side highest
 * (but lower than itself) and right_side highest (but lower than itself) point.
 * Easy to think of maximum number of jumps. But how about A to B? Fisrtly,
 * special judge if there exist. If there exist, we choose the highest as
 * level[0] and do top-down dp, thus, there distance is level[A] - level[B].
 * Why? As there is path between A & B (denoted by special check), assume A is
 * higher one, A must be on the path from root to B. Each node has as much 2
 * fathers. If the first father is larger, but A is on the second father, it
 * seems that our answer would be smaller than before (as using second father,
 * level[B] would be smaller), but that is wrong. Because as there exist path
 * between A and B, and first father and B, we could know that there must exist
 * path between first father and A. Thus, level[A] - level[B] is the answer
 * @return auto
 */
auto solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  SparseTable<ll> st(a);
  vector<vector<ll>> E(n + 1);
  vector<vector<ll>> L(n), R(n);
  vector<ll> lev(n + 1, 0), ans(n + 1, 0);
  ll mx = *max_element(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    if (a[i] == mx) {
      E[n].emplace_back(i);
    }
    if (i < n - 1 && st.query(i, n - 1) > a[i]) {
      int l = i + 1, r = n - 1, ans = r;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (st.query(l, mid) > a[i]) {
          r = mid - 1;
          ans = min(ans, mid);
        } else {
          l = mid + 1;
        }
      }
      if (L[ans].empty() || a[i] == a[L[ans][0]]) {
        L[ans].emplace_back(i);
      } else if (a[i] > a[L[ans][0]]) {
        L[ans] = {i};
      }
    }
    if (i > 0 && st.query(0, i) > a[i]) {
      int l = 0, r = i - 1, ans = l;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (st.query(mid, r) > a[i]) {
          l = mid + 1;
          ans = max(ans, mid);
        } else {
          r = mid - 1;
        }
      }
      if (R[ans].empty() || a[R[ans][0]] == a[i]) {
        R[ans].emplace_back(i);
      } else if (a[i] > a[R[ans][0]]) {
        R[ans][0] = {i};
      }
    }
  }
  for (ll i = 0; i < n; ++i) {
    for (auto &j : L[i]) {
      E[i].emplace_back(j);
    }
    for (auto &j : R[i]) {
      E[i].emplace_back(j);
    }
  }
  // for (ll i = 0; i < n; ++i) {
  //   cout << i << ": ";
  //   for (auto &j : E[i]) {
  //     cout << j << " ";
  //   }
  //   cout << "\n";
  // }
  function<void(ll)> dfs = [&](ll u) {
    ans[u] = 0;
    for (auto v : E[u]) {
      if (lev[v] == 0 && v != n) {
        lev[v] = lev[u] + 1;
        dfs(v);
      }
      if (lev[v] > lev[u]) {
        ans[u] = max(ans[u], ans[v] + 1);
      }
    }
  };
  dfs(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (v == -1) {
      cout << ans[u] << "\n";
    } else {
      if (u > v) {
        swap(u, v);
      }
      // cout<<u<<" "<<v<<" "<<a[u]<<" "<<a[v]<<" ";
      // cout<<st.query(u+1,v-1)<<" ";
      if (a[u] == a[v] ||
          (u < v - 1 && st.query(u + 1, v - 1) >= max(a[u], a[v])))
        cout << "0\n";
      else
        cout << abs(lev[u] - lev[v]) << "\n";
    }
  }
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