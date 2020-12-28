#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, W, k;
  cin >> n >> W >> k;
  vector<pair<int, ll>> node(n);
  for (auto &[u, v] : node)
    cin >> u >> v;
  vector<ll> choose(n + 1, 0);
  sort(node.begin(), node.end(),
       [](auto x, auto y) { return x.first < y.first; });
  multiset<ll> st;
  ll sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    st.emplace(node[i].second);
    sum += node[i].second;
    if ((int)st.size() > k) {
      sum -= *st.begin();
      st.erase(st.begin());
    }
    choose[i] = sum;
  }
  ll ans = choose[0];
  vector<ll> dp(W + 1, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = W; j >= node[i - 1].first; --j) {
      dp[j] = max(dp[j], dp[j - node[i - 1].first] + node[i - 1].second);
    }
    ll cur = *max_element(dp.begin(), dp.end());
    ans = max(ans, cur + choose[i]);
  }
  cout << ans << "\n";
}