#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = (1 << 18) + 7;
array<ll, N> a, pre;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
auto solve() {
  int k;
  cin >> k;
  const int n = 1 << (k + 1);
  map<ll, int> pos;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pre[i] = pre[i - 1] ^ a[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (pos.contains(a[i])) {
      cout << pos[a[i]] << " " << pos[a[i]] << " " << i << " " << i << "\n";
      return;
    }
    pos[a[i]] = i;
  }
  if (k == 0) {
    cout << "1 1 2 2\n";
    return;
  }
  map<ll, pair<int, int>> mp;
  while (true) {
  restart:
    int x = (int)(rnd() % (n + 1));
    int y = (int)(rnd() % (n + 1));
    while (y == x)
      y = (int)(rnd() % (n + 1));
    if (x > y) {
      swap(x, y);
    }
    if (mp.contains(pre[x] ^ pre[y])) {
      auto [l, r] = mp[pre[x] ^ pre[y]];
      if (l == x && r == y) {
        // cnt++;
        // if (cnt == 64)
        //   break;
        goto restart;
      }
      if (l != x && r != y) {
        vector vec = {l, r, x, y};
        sort(vec.begin(), vec.end());
        cout << vec[0] + 1 << " " << vec[1] << " " << vec[2] + 1 << " "
             << vec[3] << "\n";
        return;
      } else {
        int u, v;
        if (x == l) {
          u = min(y, r);
          v = max(y, r);
        } else {
          assert(y == r);
          u = min(x, l);
          v = max(x, l);
        }
        if (mp.contains(0)) {
          auto [dx, dy] = mp[0];
          if (dx == u && dy == v) {
            goto restart;
          }
          vector<int> vec;
          if (dx != u && dy != v) {
            vec = {dx, dy, u, v};
          } else if (dx == u) {
            vec = {u, v, dy, min(v, dy)};
          } else if (dy == v) {
            vec = {u, v, dx, max(u, dx)};
          }
          assert(!vec.empty());
          sort(vec.begin(), vec.end());
          cout << vec[0] + 1 << " " << vec[1] << " " << vec[2] + 1 << " "
               << vec[3] << "\n";
          return;
        } else {
          mp[0] = {u, v};
        }
      }
    } else {
      mp[pre[x] ^ pre[y]] = {x, y};
    }
  }
  cout << "-1\n";
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