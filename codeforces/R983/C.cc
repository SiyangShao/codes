#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
void debug_out() { cerr << endl; }
template <typename T, typename... Args> void debug_out(T first, Args... rest) {
  std::cout << first << " ";
  debug_out(rest...);
}
#else
#define dbg(...) {};
#endif
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  sort(a.begin(), a.end());
  // smallest 2's sum is larger than the largest
  ll ans = n;
  for (ll i = 1; i < n; ++i) {
    auto sum = a[i - 1] + a[i];
    auto it = lower_bound(a.begin(), a.end(), sum);
    auto nd = a.end() - it;
    dbg(sum, nd, i);
    ans = min(ans, i - 1 + nd);
    sum = a[i] * 2;
    it = lower_bound(a.begin(), a.end(), sum);
    nd = a.end() - it;
    ans = min(ans, i + nd);
    dbg(sum, nd, i);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
