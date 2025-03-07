#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
auto solve() {
  int n, m;
  cin >> n >> m;
  vector A(n, vector<ll>(m));
  for (auto &a : A) {
    for (auto &x : a) {
      cin >> x;
    }
  }
  vector dp(n, vector<ll>(m, -inf));

}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
