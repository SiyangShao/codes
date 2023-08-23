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
ll ask(ll n) {
  cout << "? " << n << endl;
  ll tmp;
  cin >> tmp;
  return tmp;
}
auto solve() {
  ll n;
  cin >> n;
  vector<ll> d(n);
  dsu DSU(n);
  for (auto &i : d) {
    cin >> i;
  }
  vector<ll> vis(n, 0);
  vector<ll> label(n, 0);
  iota(label.begin(), label.end(), 0);
  sort(label.begin(), label.end(), [&](auto x, auto y) { return d[x] > d[y]; });
  for (ll idx = 0; idx < n; ++idx) {
    ll i = label[idx];
    if (vis[i])
      continue;
    vis[i] = 1;
    for (ll j = 0; j < d[i]; ++j) {
      ll t = ask(i + 1);
      t--;
      DSU.merge(t, i);
      if (vis[t]) {
        break;
      }
      vis[t] = 1;
    }
  }
  vector<ll> ans(n);
  auto c = DSU.groups();
  for (ll i = 0; i < c.size(); ++i) {
    for (auto &j : c[i]) {
      ans[j] = i + 1;
    }
  }
  cout << "! ";
  for (auto &i : ans) {
    cout << i << " ";
  }
  cout << endl;
}
auto main() -> int {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}