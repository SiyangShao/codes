#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 110;
array<array<ll, N>, N> dp_l,
    dp_r; // dp_l: take odd at last, dp_r: take even at last
auto init() {
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < N; ++j) {
      dp_l[i][j] = dp_r[i][j] = -1;
    }
  }
  for (ll i = 0; i < N; ++i) {
    dp_r[0][i] = 1;
    dp_r[i][0] = ((i + 1) / 2) % 2 == 0;
    dp_l[0][i] = 0;
    dp_l[i][0] = ((i + 1) / 2) % 2 == 1;
  }
}
void dfsR(ll odd, ll even);
void dfsL(ll odd, ll even) {
  if (dp_l[odd][even] != -1)
    return;
  ll ans = 0;
  if (odd % 2 == 1) {
    // sum is odd
    dfsL(odd - 1, even);
    if (dp_l[odd - 1][even]) {
      ans = max(ans, 0LL);
    } else {
      ans = max(ans, 1LL);
    }
    if (even >= 1) {
      dfsL(odd, even - 1);
      if (dp_l[odd][even - 1]) {
        ans = max(ans, 0LL);
      } else {
        ans = max(ans, 1LL);
      }
    }
  } else {
    // sum is even
    if (odd >= 1) {
      // if i take odd. I don't want he ensure to take even
      dfsR(odd - 1, even);
      if (dp_r[odd - 1][even]) {
        ans = max(ans, 0LL);
      } else {
        ans = max(ans, 1LL);
      }
    }
    if (even >= 1) {
      // if I take even. I don't want he ensure to take even
      dfsR(odd, even - 1);
      if (dp_r[odd][even - 1]) {
        ans = max(ans, 0LL);
      } else {
        ans = max(ans, 1LL);
      }
    }
  }
  dp_l[odd][even] = ans;
}
void dfsR(ll odd, ll even) {
  if (dp_r[odd][even] != -1)
    return;
  ll ans = 0;
  if (odd % 2 == 1) {
    // sum is odd
    // I don't want he ensure to take even
    dfsR(odd - 1, even);
    if (dp_r[odd - 1][even]) {

    } else {
      ans = 1;
    }
    if (even >= 1) {
      dfsR(odd, even - 1);
      if (dp_r[odd][even - 1]) {

      } else {
        ans = 1;
      }
    }
  } else {
    // sum is even
    // i don't want he ensure to take odd
    if (odd >= 0) {
      dfsL(odd - 1, even);
      if (dp_l[odd - 1][even]) {

      } else {
        ans = 1;
      }
    }
    if (even >= 0) {
      dfsL(odd, even - 1);
      if (dp_l[odd][even - 1]) {

      } else {
        ans = 1;
      }
    }
  }
  dp_r[odd][even] = ans;
}
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll odd = 0, even = 0;
  for (auto &i : a) {
    cin >> i;
    if (i % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }
  dfsR(odd, even);
  if (dp_r[odd][even]) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  init();
  cin >> _;
  while (_--) {
    solve();
  }
}