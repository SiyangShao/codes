#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> E(n);
  vector<int> nxt(n);
  for (int i = 0; i < n; ++i) {
    int v;
    cin >> v;
    v--;
    nxt[i] = v;
    E[v].push_back(i);
  }
  vector<int> vis(n);
  for (int u = 0; u < n; ++u) {
    if (vis[u])
      continue;
    int slow = u, fast = nxt[u];
    do {
      slow = nxt[slow];
      fast = nxt[nxt[fast]];
    } while (slow != fast && slow != nxt[fast]);
    vector<int> cycle = {slow};
    for (int v = nxt[slow]; v != slow; v = nxt[v]) {
      cycle.emplace_back(v);
    }
  }
}