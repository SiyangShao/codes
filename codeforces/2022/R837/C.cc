#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (auto(i) = a; (i) < n; ++(i))
constexpr ll N = 31625;
bitset<N> vis;
vector<ll> pri;
auto init() {
  for (ll i = 2; i < N; ++i) {
    if (!vis[i]) {
      pri.emplace_back(i);
    }
    for (auto j : pri) {
      if (i * j >= N) {
        break;
      }
      vis[i * j] = true;
      if (i % j == 0)
        break;
    }
  }
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto i : pri) {
    int cnt = 0;
    for (auto &j : a) {
      if (j % i == 0) {
        cnt++;
        while (j % i == 0) {
          j /= i;
        }
      }
    }
    if (cnt >= 2) {
      cout << "YES\n";
      return;
    }
  }
  sort(a.begin(), a.end());
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i - 1] && a[i] != 1) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  // cout<<pri.size()<<"\n";
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}