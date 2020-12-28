#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  ll tot = 0;
  for (ll i = 1; i <= n; ++i) {
    tot += a[i];
    if (tot > m) {
      n = i - 1;
      break;
    }
  }
  auto suf = b;
  for (ll i = n - 1; i >= 1; --i) {
    suf[i] = max(suf[i + 1], suf[i]);
  }
  ll t = 0;
  vector<ll> ans;
  auto output = [&]() {
    cout << ans.size() << "\n";
    for (auto &i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  };
  ll cur = 0, balloon = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    t += b[i];
    if (t > m) {
      output();
      return 0;
    }
    while (j <= n && cur + a[j] <= t) {
      cur += a[j];
      j++;
      balloon++;
    }
    if (suf[i] == b[i] && balloon > 0) {
      balloon--;
      i--;
      ans.emplace_back(t);
    }
  }
  cout << "-1\n";
}