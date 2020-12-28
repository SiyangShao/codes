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
  dsu G(n);
  vector<int> deg(n, 1);
  vector<string> mp(n);
  for (auto &i : mp) {
    cin >> i;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mp[i][j] == '1') {
        deg[i]++;
        G.merge(i, j);
      }
    }
  }
  auto grp = G.groups();
  for (auto &i : grp) {
    sort(i.begin(), i.end(), [&](int x, int y) { return deg[x] < deg[y]; });
  }
  if ((int)grp.size() == 1) {
    cout << "0\n";
  } else {
    for (auto i : grp) {
      if (deg[i[0]] != (int)i.size() || (int)i.size() == 1) {
        cout << "1\n";
        cout << i[0] + 1 << "\n";
        return;
      }
    }
    if ((int)grp.size() == 2) {
      if (grp[0].size() > grp[1].size()) {
        swap(grp[0], grp[1]);
      }
      cout << grp[0].size() << "\n";
      for (auto &i : grp[0]) {
        cout << i + 1 << " ";
      }
      cout << "\n";
    } else {
      cout << "2\n";
      cout << grp[0][0] + 1 << " " << grp[1][0] + 1 << "\n";
    }
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