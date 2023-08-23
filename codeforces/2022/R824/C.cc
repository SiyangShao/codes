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
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> pre(26), nxt(26);
  dsu DSU(26);
  for (ll i = 0; i < 26; ++i) {
    pre[i] = nxt[i] = -1;
  }
  for (auto cur : s) {
    ll i = cur - 'a';
    if (nxt[i] != -1) {
      cout << char(nxt[i] + 'a');
      continue;
    }
    bool flg = false;
    for (ll j = 0; j < 26; ++j) {
      if (j != i && pre[j] == -1 && !DSU.same(i, j)) {
        nxt[i] = j;
        pre[j] = i;
        DSU.merge(i, j);
        flg = true;
        break;
      }
    }
    if (!flg) {
      for (ll j = 0; j < 26; ++j) {
        if (pre[j] == -1) {
          assert(i != j);
          pre[j] = i;
          nxt[i] = j;
        }
      }
    }
    cout << char(nxt[i] + 'a');
  }
  cout << "\n";
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