#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct DSU {
  int n;
  ll sum{};
  vector<int> fa, size;
  DSU(int _) : n(_), fa(_), size(_, 1) { iota(fa.begin(), fa.end(), 0); }
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return;
    fa[x] = y;
    sum -= (ll)size[x] * (size[x] - 1) / 2 + (ll)size[y] * (size[y] - 1) / 2;
    size[y] += size[x];
    sum += (ll)size[y] * (size[y] - 1) / 2;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int>> edg;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edg.emplace_back(w, u, v);
  }
  int Q;
  cin >> Q;
  vector<int> D(Q);
  for (auto &i : D) {
    cin >> i;
    i ^= k;
  }
  vector<ll> ans(Q);
  vector<int> id(Q);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) { return D[i] < D[j]; });
  sort(edg.begin(), edg.end());
  auto it = edg.begin();
  DSU dsu(n);
  for(auto i : id){
    int val = D[i];
    while(it != edg.end() && get<0>(*it) <= val){
      dsu.merge(get<1>(*it), get<2>(*it));
      ++it;
    }
    ans[i] = dsu.sum;
  }
  for(auto i : ans){
    cout << i << "\n";
  }
}