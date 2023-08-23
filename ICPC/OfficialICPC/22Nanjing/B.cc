#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  s = "1" + s + "1";
  int q;
  cin >> q;
  vector<pair<int, ll>> Query(q);
  for (auto &[p, v] : Query) {
    cin >> p >> v;
  }
  vector<ll> pre(n + 2), back(n + 2);
  pre[0] = 0;
  deque<int> Q;
  Q.emplace_back(0);
  for (int i = 1; i <= n + 1; ++i) {
    while (Q.front() < i - k)
      Q.pop_front();

    pre[i] = pre[Q.front()] + a[i];
    if (s[i] == '1')
      Q.clear();
    while (!Q.empty() && pre[Q.back()] >= pre[i])
      Q.pop_back();
    Q.emplace_back(i);
  }
  Q.clear();
  Q.emplace_back(n + 1);
  back[n + 1] = 0;
  for (int i = n; i >= 0; --i) {
    while (Q.front() > i + k)
      Q.pop_front();
    back[i] = back[Q.front()] + a[i];
    if (s[i] == '1')
      Q.clear();
    while (!Q.empty() && back[Q.back()] >= back[i])
      Q.pop_back();
    Q.emplace_back(i);
  }
  for (auto [p, v] : Query) {
    ll ans = 1e16;
    swap(a[p], v);
    Q.clear();
    for (int i = max(p - k, 0); i < p; ++i) {
      if (s[i] == '1')
        Q.clear();
      while (!Q.empty() && pre[Q.back()] >= pre[i]) {
        Q.pop_back();
      }
      Q.emplace_back(i);
    }
    vector<ll> record;
    for (int i = p; i <= min(p + k, n + 1); ++i) {
      while (Q.front() < i - k)
        Q.pop_front();
      record.emplace_back(pre[i]);
      pre[i] = pre[Q.front()] + a[i];
      if (s[i] == '1')
        Q.clear();
      while (!Q.empty() && pre[Q.back()] >= pre[i])
        Q.pop_back();
      Q.emplace_back(i);
      if (i == p) {
        ans = min(ans, pre[i] + back[i] - v);
      } else
        ans = min(ans, pre[i] + back[i] - a[i]);
    }
    for (int i = p; i <= min(p + k, n); ++i) {
      pre[i] = record[i - p];
    }
    record.clear();
    Q.clear();
    for (int i = min(p + k, n + 1); i > p; --i) {
      if (s[i] == '1')
        Q.clear();
      while (!Q.empty() && pre[Q.back()] >= pre[i]) {
        Q.pop_back();
      }
      Q.emplace_back(i);
    }
    for (int i = p; i >= max(p - k, 0); --i) {
      while (Q.front() > i + k)
        Q.pop_front();
      record.emplace_back(back[i]);
      back[i] = back[Q.front()] + a[i];
      if (s[i] == '1')
        Q.clear();
      while (!Q.empty() && back[Q.back()] >= back[i])
        Q.pop_back();
      Q.emplace_back(i);
      if (i == p) {
        ans = min(ans, pre[i] + back[i] - v);
      } else
        ans = min(ans, pre[i] + back[i] - a[i]);
    }
    for (int i = p; i >= max(p - k, 1); --i) {
      back[i] = record[p - i];
    }
    swap(a[p], v);
    cout << ans << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}