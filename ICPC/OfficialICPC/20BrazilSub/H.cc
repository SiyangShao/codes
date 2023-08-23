#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
ll c[52][52];
#define M(x) (((x) % p + p) % p)

void preprocess() {
  c[0][0] = 1;
  FOR(i, 1, 50) FOR(j, 0, i) c[i][j] = c[i - 1][j] + (j != 0 ? c[i - 1][j - 1] : 0);
}
vector<ll> a;
ll n;
ll dfs(ll x, ll k, ll N) { 
  // n select k
  assert(x>=0);
  if (k == 0) return 1;
  auto pos = upper_bound(a.begin(), a.begin() + N, x);
  if (pos == a.begin()) return 0;
  else {
    ll loc = prev(pos) - a.begin();
    // 1. choose a[loc]
    ll ans = dfs(x - a[loc], k - 1, loc + 1 - 1);
    // 2. don't choose
    ans += c[loc][k];
    return ans;
  } 
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  preprocess();
  ll k;
  cin >> n >> k;
  a.resize(n);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  ll A, B;
  cin >> A >> B;
  cout << dfs(B, k, n)- dfs(A - 1, k, n) << "\n";
}