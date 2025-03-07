#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> E(n), revE(n);
  vector<int> in(n), dep(n);
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    E[i].resize(c);
    for (int j = 0; j < c; j++) {
      cin >> E[i][j];
      E[i][j]--;
      revE[E[i][j]].emplace_back(i);
      in[E[i][j]]++;
    }
  }
  queue<int> Q;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0) {
      Q.push(i);
    }
  }
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    dep[u] = 1;
    for (auto v : revE[u]) {
      dep[u] = max(dep[u], dep[v] + 1);
    }
    for (auto v : E[u]) {
      in[v]--;
      if (in[v] == 0) {
        Q.emplace(v);
      }
    }
  }
  if (*max_element(dep.begin(), dep.end()) == n) {
    cout << "1\n";
  } else {
    cout << "0\n";
  }
}
