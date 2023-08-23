#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dsu {
public:
  dsu() : _n(0) {}
  explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y)
      return x;
    if (-parent_or_size[x] < -parent_or_size[y])
      std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0)
      return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
        std::remove_if(result.begin(), result.end(),
                       [&](const std::vector<int> &v) { return v.empty(); }),
        result.end());
    return result;
  }

private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
};
auto solve() {
  int n;
  cin >> n;
  dsu d(n);
  vector mp(n, vector<ll>(n, 0));
  vector<tuple<ll, int, int>> vec;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      cin >> mp[i][j];
    }
    for (int j = 0; j < i; ++j) {
      mp[i][j] = mp[i][i] + mp[j][j] - 2 * mp[i][j];
      assert(mp[i][j] % n == 0);
      mp[i][j] /= n; // distance between i and j
      /**
       * @brief Obviously, the added edge will not count in the distance. For
       * points outside the loop, dis[i] + dis[j] - dis_loop * 2 equals to the
       * length of the loop. As we suppose the point where it meets the loop
       * (actually is the chain) is u, then dis[i] - dis_loop equals to u-i and
       * dis[j] - dis_loop equals to u-j. Thus, the distance sum is i-j * n.
       *
       */
      vec.emplace_back(mp[i][j], i, j);
    }
  }
  sort(vec.begin(), vec.end());
  for (auto &[v, x, y] : vec) {
    if (!d.same(x, y)) {
      d.merge(x, y);
      cout << x + 1 << " " << y + 1 << " " << v << "\n";
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
