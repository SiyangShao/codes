#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(3 * n), b(3 * n);
  for (int i = 0; i < 3 * n; i++) {
    cin >> a[i] >> b[i];
  }
  vector<int> id(3 * n), id2(3 * n), vis(3 * n, 0);
  iota(id.begin(), id.end(), 0);
  iota(id2.begin(), id2.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) { return b[i] < b[j]; });
  sort(id2.begin(), id2.end(), [&](int i, int j) { return a[i] < a[j]; });
  // b from small to large
  // all numbers whose a is less than b and b is smaller
  vector<tuple<ll, ll, ll>> ans;
  auto it = id2.begin();
  priority_queue<pair<ll, ll>> pq;
  for (auto i : id) {
    if (vis[i])
      continue;
    vis[i] = 1;
    while (it != id2.end() && a[*it] <= b[i]) {
      pq.emplace(-b[*it], *it);
      it++;
    }
    ll x = -1, y = -1;
    while (!pq.empty()) {
      auto [_, j] = pq.top();
      pq.pop();
      if (vis[j]) {
        continue;
      }
      if (x == -1) {
        x = j;
      } else if (y == -1) {
        y = j;
        break;
      }
    }
    if (y == -1) {
      cout << "No\n";
      return;
    }
    vis[x] = 1;
    vis[y] = 1;
    ans.emplace_back(i, x, y);
  }
  cout << "Yes\n";
  for (auto [i, x, y] : ans) {
    cout << i + 1 << " " << x + 1 << " " << y + 1 << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
}
