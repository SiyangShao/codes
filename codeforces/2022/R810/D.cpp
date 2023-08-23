#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 7;
ll x[N], p[N];
void solve() {
  int n, m;
  cin >> n >> m;
  map<ll, ll> sk;
  for (int i = 1; i <= n; i++)
    cin >> x[i] >> p[i], sk[x[i] - p[i]]++, sk[x[i]] -= 2, sk[x[i] + p[i]]++;
  ll k = 0, lst = 0, val = 0, lim1 = -9e18, lim2 = -9e18;
  for (auto &[pos, v] : sk) {
    val += k * (pos - lst), k += v, lst = pos;
    if (val > m)
      lim1 = max(lim1, val + lst - m), lim2 = max(lim2, val - lst - m);
  }
  for (int i = 1; i <= n; i++)
    cout << (p[i] + x[i] >= lim1 && p[i] - x[i] >= lim2);
  cout << '\n';
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
}
