#include <bits/stdc++.h>
using namespace std;
void get(int x, int y, int t, int now, std::vector<std::pair<int, int>> &ans) {
  if (t < 0) {
    return;
  }
  if (y & (1 << t)) {
    if ((x & (1 << t)) == (y & (1 << t))) {
      ans.emplace_back(now | (1 << t), now | ((1 << (t + 1)) - 1));
      get(x, y, t - 1, now, ans);
    } else {
      ans.emplace_back(now, now | ((1 << t) - 1));
      get(x, y, t - 1, now | (1 << t), ans);
    }
  } else {
    if ((x & (1 << t)) == (y & (1 << t))) {
      get(x, y, t - 1, now, ans);
    } else {
      get(x, y, t - 1, now | (1 << t), ans);
    }
  }
}

std::vector<std::pair<int, int>> get(int x, int y) {
  std::vector<std::pair<int, int>> ans;
  get(x, y, 30, 0, ans);
  return ans;
}
using ll = long long;
struct DSU {
  int n;
  ll sum{};
  vector<int> fa, size;
  DSU(int _) : n(_), fa(_), size(_, 1) { iota(fa.begin(), fa.end(), 0); }
  stack<pair<int, int>> st;
  int find(int u) {
    if (u == fa[u])
      return u;
    return find(fa[u]);
  }
  void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) {
      st.emplace(-1, -1);
      return;
    }
    if (size[u] > size[v]) {
      swap(u, v);
    }
    fa[u] = v;
    st.emplace(u, v);
    sum -= (ll)size[u] * (size[u] - 1) / 2 + (ll)size[v] * (size[v] - 1) / 2;
    size[v] += size[u];
    sum += (ll)size[v] * (size[v] - 1) / 2;
  }
  void reverse() {
    if (st.empty()) {
      assert(false);
    }
    auto [u, v] = st.top();
    if (u == -1 && v == -1) {
      st.pop();
      return;
    }
    st.pop();
    sum -= (ll)size[v] * (size[v] - 1) / 2;
    size[v] -= size[u];
    sum += (ll)size[v] * (size[v] - 1) / 2 + (ll)size[u] * (size[u] - 1) / 2;
    fa[u] = u;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int, int, int>> edg;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    auto ans = get(w, k);
    sort(ans.begin(), ans.end());
    // cout << i << ": \n";
    for (auto [a, b] : ans) {
      edg.emplace_back(a, u, v, i, b);
      edg.emplace_back(-(b + 1), u, v, i, a);
      // cout << a << " " << b << "\n";
    }
    // cout << "\n";
  }
  sort(edg.begin(), edg.end(), [&](auto a, auto b) {
    if (abs(get<0>(a)) != abs(get<0>(b))) {
      return abs(get<0>(a)) < abs(get<0>(b));
    } else {
      if (get<0>(a) >= 0 && get<0>(b) >= 0) {
        if (get<4>(a) != get<4>(b)) {
          return get<4>(a) > get<4>(b);
        } else {
          return get<3>(a) > get<3>(b);
        }
      } else if (get<0>(a) < 0 && get<0>(b) < 0) {
        if (get<4>(a) != get<4>(b)) {
          return get<4>(a) > get<4>(b);
        } else {
          return get<3>(a) < get<3>(b);
        }
      } else {
        return get<0>(a) < 0 ? true : false;
      }
    }
  });
  // stack<int> st;
  // for (auto [a, b, c, d, e] : edg) {
  //   if (a >= 0) {
  //     st.emplace(d);
  //   } else {

  //     // cout<<a<<" "<<e<<" ";
  //     // cout << "-" << d << "\n";
  //     if(st.top()!=d){
  //       assert(false);
  //       return 0;
  //     }
  //     st.pop();
  //   }
  // }
  // return 0;
  int Q;
  cin >> Q;
  vector<int> D(Q), id(Q);
  for (auto &i : D) {
    cin >> i;
  }
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](auto a, auto b) { return D[a] < D[b]; });
  vector<ll> ans(Q);
  auto it = edg.begin();
  DSU dsu(n);
  for (auto i : id) {
    while (it != edg.end() && abs(get<0>(*it)) <= D[i]) {
      if (get<0>(*it) >= 0) {
        dsu.merge(get<1>(*it), get<2>(*it));
      } else {
        dsu.reverse();
      }
      ++it;
    }
    ans[i] = dsu.sum;
  }
  for (auto i : ans) {
    cout << i << '\n';
  }
}