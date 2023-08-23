#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int m, n, w, h;
  cin >> m >> n >> w >> h;
  vector<int> work(m), d(n);
  for (auto &i : work) {
    cin >> i;
    i /= w;
  }
  for (auto &i : d) {
    cin >> i;
  }
  priority_queue<pair<int, int>> Q;
  for (int i = 0; i < m; ++i) {
    Q.emplace(work[i], i);
  }
  int worker = 0; // current worker
  vector<int> predif(n + 1, 0);
  vector<vector<int>> newWorker(n), ans(m);
  for (int i = 0; i < n; ++i) {
    worker += predif[i];
    if (worker > d[i]) {
      cout << "-1\n";
      return 0;
    }
    while (worker < d[i]) {
      if (Q.empty()) {
        cout << "-1\n";
        return 0;
      }
      auto [_, u] = Q.top();
      Q.pop();
      if (work[u] <= 0) {
        cout << "-1\n";
        return 0;
      }
      work[u]--;
      ans[u].emplace_back(i);
      worker++;
      predif[i + w]--;
      if (work[u] && i + w + h - 1 < n) {
        newWorker[i + w + h - 1].emplace_back(u);
      }
    }
    for (auto u : newWorker[i]) {
      Q.emplace(work[u], u);
    }
  }
  cout << "1\n";
  for (int i = 0; i < m; ++i) {
    for (auto &j : ans[i]) {
      cout << j + 1 << " ";
    }
    cout << "\n";
  }
}