#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m;
vector<vector<pair<int, ll>>> E;
vector<ll> dis;
bool Bellman_Ford() {
  for (int i = 0; i < n; ++i) {
    bool jud = false;
    for (int j = 1; j <= n; ++j) {
      for (auto [v, w] : E[j]) {
        if (dis[j] > dis[v] + w) {
          dis[j] = dis[v] + w;
          jud = true;
        }
      }
    }
    if (!jud)
      break;
  }
  for (int i = 1; i <= n; ++i) {
    for (auto [v, w] : E[i]) {
      if (dis[i] > dis[v] + w) {
        return false;
      }
    }
  }
  return true;
}
void spfa() {
  fill(dis.begin(), dis.end(), 1e16);
  vector<int> vis(n + 1), cnt(n + 1);
  dis[0] = 0, vis[0] = 1;
  queue<int> Q;
  Q.emplace(0);
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    vis[u] = 0;
    for (auto [v, w] : E[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        if (cnt[v] >= n + 1) {
          assert(false);
          return;
        }
        cnt[v] = cnt[u] + 1;
        if (!vis[v]) {
          Q.emplace(v);
          vis[v] = 1;
        }
      }
    }
  }
}
auto solve() {
  cin >> n >> m;
  ll x;
  cin >> x;
  E = vector<vector<pair<int, ll>>>(n + 1);
  dis = vector<ll>(n + 1);
  for (int i = 2; i <= n; ++i) {
    // i - (i-1) >= 1
    E[i].emplace_back(i - 1, -1);
  }
  for (int i = 1; i <= n; ++i) {
    E[0].emplace_back(i, 0);
  }
  // A > A-1
  while (m--) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    // A--, B--, C--, D--;
    if (A == B && C == D) {
      // C- A == x
      // C - A >= x
      E[C].emplace_back(A, -x);
      // C - A <= x
      E[A].emplace_back(C, x);
    } else if (A == B) {
      // C - A < x => C - A <= x - 1
      E[A].emplace_back(C, x - 1);
      // D - A > x => D - A >= x+1
      E[D].emplace_back(A, -(x + 1));
    } else if (C == D) {
      // C - A > x => C - A >= x+1
      E[C].emplace_back(A, -(x + 1));
      // C - B < x => C - B <= x-1
      E[B].emplace_back(C, (x - 1));
    } else {
      // D - A > x => D - A >= x+1
      E[D].emplace_back(A, -(x + 1));
      // C - B < x => C - B <= x-1
      E[B].emplace_back(C, x - 1);
    }
  }
  // for (int i = 0; i <= n; ++i) {
  //   for (auto [v, w] : E[i]) {
  //     cout << i << " " << v << ' ' << w << "\n";
  //   }
  // }

  if (!Bellman_Ford()) {
    cout << "IMPOSSIBLE\n";
    return;
  } else {
    // for (int i = 0; i <= n; ++i) {
    //   cout << dis[i] << " ";
    // }
    // cout << "\n";
    dis = vector<ll>(n + 1);
    spfa();
    // for (int i = 0; i <= n; ++i) {
    //   cout << dis[i] << " ";
    // }
    // cout << "\n";
    for (int i = 2; i <= n; ++i) {
      cout << dis[i] - dis[i - 1] << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  for (int i = 1; i <= _; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}