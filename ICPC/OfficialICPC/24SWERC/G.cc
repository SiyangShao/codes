#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  ll r;
  cin >> r;
  int n;
  cin >> n;
  vector<ll> pre(n + 1);
  ll mx = 0, mi = 0;
  ll dif = 0;
  for (int i = 1; i <= n; i++) {
    cin >> pre[i];
    pre[i] += pre[i - 1];
    dif = max(dif, abs(pre[i] - mx));
    dif = max(dif, abs(pre[i] - mi));
    mx = max(mx, pre[i]);
    mi = min(mi, pre[i]);
  }
  if (dif < r) {
    cout << "uncertain\n";
    return 0;
  }
  ll pos = 0;
  for (int i = 1; i <= n; i++) {
    ll d = pre[i] - pre[i - 1];
    pos += d;
    pos = max(pos, 0LL);
    pos = min(pos, r);
  }
  cout << pos << "\n";
}
