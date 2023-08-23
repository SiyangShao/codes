#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * @brief
 * Observation: Each card must has a value in [1,n] and a value in [n+1, 2n]
 * Let f(k) denote the number matched with k
 * Suppose for some set A, there smaller number (1 - n) showed on the front
 * For set B, smaller (1-n) showed on the back
 * If we could divide [f(1), f(2), f(3) ... f(n)] into 2 decreasing subsequence,
 * it must be the answer of the question
 * @return auto
 */
auto solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> v(n);
  for (auto &[a, c] : v) {
    cin >> a >> c;
    a--, c--;
  }
  vector<ll> f(n), cst(n);
  for (auto &[a, c] : v) {
    if ((a < n) == (c < n)) {
      cout << "-1\n";
      return;
    }
    if (a > c) {
      swap(a, c);
      cst[a] = 1;
    }
    f[a] = c;
  }
  vector<ll> suf = f;
  for (ll i = n - 2; i >= 0; --i) {
    suf[i] = max(suf[i], suf[i + 1]);
  }
  ll pref = n * 2;
  ll cost0 = 0, cost1 = 0, ans = 0;
  vector<ll> seq0, seq1;
  // greedy to get the 2 sequence
  for (ll i = 0; i < n; ++i) {
    pref = min(pref, f[i]);
    if (seq0.empty() || f[seq0.back()] > f[i]) {
      seq0.emplace_back(i);
      cost0 += cst[i];
    } else if (seq1.empty() || f[seq1.back()] > f[i]) {
      seq1.emplace_back(i);
      cost1 += cst[i];
    } else {
      cout << "-1\n";
      return;
    }
    if (i + 1 == n || pref > suf[i + 1]) {
      ans += min(cost0 + ((ll)seq1.size() - cost1),
                 cost1 + ((ll)seq0.size() - cost0));
      cost0 = cost1 = 0;
      seq0.clear();
      seq1.clear();
    }
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}