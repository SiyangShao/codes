#include <bits/stdc++.h>
using namespace std;

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
  dsu DSU(n);
  vector<string> mp(n);
  vector<int> deg(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '1') {
        DSU.merge(i, j);
        deg[i]++;
      }
    }
    mp[i] = move(s);
  }
  auto grp = DSU.groups();
  if (grp.size() == 1) {
    cout << "0\n";
    return;
  }
  for (auto &j : grp) {
    if (j.size() == 1) {
      cout << "1\n";
      cout << j[0] + 1 << "\n";
      return;
    }
    sort(j.begin(), j.end(), [&](auto x, auto y) { return deg[x] < deg[y]; });
    if (deg[j[0]] == DSU.size(j[0]) - 1)
      continue;
    cout << "1\n";
    cout << j[0] + 1 << "\n";
    return;
  }
  if (grp.size() == 2) {
    if (grp[0].size() > grp[1].size()) {
      swap(grp[0], grp[1]);
    }
    cout << grp[0].size() << "\n";
    for (auto i : grp[0]) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  } else {
    cout << "2\n";
    cout << "1 ";
    bool flag = true;
    for (int i = 1; i < n; ++i) {
      if (!DSU.same(i, 0)) {
        flag = false;
        cout << i + 1 << "\n";
        return;
      }
    }
    assert(!flag);
  }
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
