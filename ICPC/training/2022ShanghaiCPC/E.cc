#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string S, F;
  cin >> S >> F;
  vector<vector<ll>> E(26 + 10);
  auto change = [&](ll x) {
    if (x >= '0' && x <= '9') {
      return x - '0';
    } else {
      return x - 'a' + 10;
    }
  };
  for (ll i = 0; i < S.length(); ++i) {
    ll x = change(S[i]);
    E[x].emplace_back(i);
  }
  for (ll i = 0; i < 36; ++i) {
    E[i].emplace_back(S.length());
  }
  vector<ll> pos(F.length(), 0);
  ll L = 0, R = S.length() - 1;
  auto check = [&]() {
    for (ll i = 1; i < F.length(); ++i) {
      ll pre_pos = E[change(F[i - 1])][pos[i - 1]];
      while (E[change(F[i])][pos[i]] <= pre_pos) {
        pos[i]++;
      }
      if (E[change(F[i])][pos[i]] == S.length()) {
        return false;
      }
    }
    return true;
  };
  for (ll i = 0; i + 1 < E[change(F[0])].size(); ++i) {
    pos[0] = i;
    if (check()) {
      ll nL = E[change(F[0])][pos[0]],
         nR = E[change(F.back())][pos[F.length() - 1]];
      if (nR - nL < R - L) {
        L = nL;
        R = nR;
      }
    } else {
      break;
    }
  }
  for (ll i = L; i <= R; ++i) {
    cout << S[i];
  }
  cout << "\n";
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