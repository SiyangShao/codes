#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  if (*max_element(s.begin(), s.end()) == '0') {
    cout << "0\n";
    return;
  }
  ll beg = 0;
  while (s[beg] == '0') {
    beg++;
  }
  vector<ll> pos;
  for (ll i = beg; i < n; ++i) {
    if (s[i] == '0') {
      break;
    }
    pos.emplace_back(i);
  }
  string nxt = s;
  ll pre_pos = -1;
  for (ll i = beg; i < n; ++i) {
    if (s[i] == '1') {
      continue;
    }
    if (pre_pos == -1) {
      nxt[i] = '1';
      pre_pos = i;
      continue;
    }
    ll delta = i - pre_pos;
    pre_pos = i;
    vector<ll> nxtpos;
    for (auto &j : pos) {
      j += delta;
      if (s[j] == '1') {
        nxtpos.emplace_back(j);
      }
    }
    if (nxtpos.empty()) {
      continue;
    } else {
      nxt[i] = '1';
      pos = move(nxtpos);
    }
  }
  for (ll i = beg; i < n; ++i) {
    cout << nxt[i];
  }
  cout << "\n";
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