#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr ll sb = 1e9;
auto checkX(string &s) {
  bool neg = false;
  ll tmp = 0;
  vector<ll> vec;
  for (int i = 6; i < s.length(); ++i) {
    if (s[i] == ',') {
      if (neg) {
        tmp = -tmp;
      }
      vec.emplace_back(tmp);
      tmp = 0;
      neg = false;
      continue;
    }
    if (s[i] == ')') {
      if (neg) {
        tmp = -tmp;
      }
      vec.emplace_back(tmp);
      break;
    }
    if (s[i] == '-') {
      neg = true;
      continue;
    }
    assert(s[i] >= '0' && s[i] <= '9');
    tmp = tmp * 10 + s[i] - '0';
  }
  if (vec.size() == 2) {
    vec.emplace_back(1);
  }
  assert(vec.size() == 3);
  return vec;
}
auto checkY(string &s) {
  bool neg = false, skp = false;
  ll tmp = 0;
  vector<ll> vec;
  for (int i = 6; i < s.length(); ++i) {
    if (s[i] == ',') {
      if (skp) {
        skp = false;
        continue;
      }
      if (neg) {
        tmp = -tmp;
      }
      vec.emplace_back(tmp);
      tmp = 0;
      neg = false;
      continue;
    }
    if (s[i] == ')') {
      if (skp) {
        skp = false;
        break;
      }
      if (neg) {
        tmp = -tmp;
      }
      vec.emplace_back(tmp);
      break;
    }
    if (s[i] >= 'a' && s[i] <= 'z') {
      skp = true;
      vec.emplace_back(sb);
    }
    if (skp) {
      continue;
    }
    if (s[i] == '-') {
      neg = true;
      continue;
    }
    assert(s[i] >= '0' && s[i] <= '9');
    tmp = tmp * 10 + s[i] - '0';
  }
  if (vec.size() == 2) {
    vec.emplace_back(1);
  }
  assert(vec.size() == 3);
  return vec;
}
auto solve() {
  string s;
  cin >> s;
  // for
  cin >> s;
  // a;
  cin >> s;
  // in
  cin >> s;
  // rangex
  string rangex, rangey;
  cin >> rangex;
  // for
  cin >> s;
  // b;
  cin >> s;
  // in
  cin >> s;
  // rangey
  cin >> rangey;
  auto vecx = checkX(rangex);
  auto vecy = checkY(rangey);
  dbg(vecx), dbg(vecy);
  ll ans = 0;
  auto check = [&](ll i) {
    if (vecx[2] > 0) {
      return i < vecx[1];
    } else {
      return i > vecx[1];
    }
  };
  for (ll i = vecx[0]; check(i); i += vecx[2]) {
    auto a = vecy[0], b = vecy[1], c = vecy[2];
    if (a == sb) {
      a = i;
    }
    if (b == sb) {
      b = i;
    }
    if (c == sb) {
      c = i;
    }
    dbg(a, b, c);
    if (c > 0) {
      b--;
      if (a > b) {
        continue;
      }
    } else {
      b++;
      if (a < b) {
        continue;
      }
    }
    ll k = (b - a) / c;
    auto tmp = (a + a + c * k) * (k + 1) / 2;
    dbg(i, a, b, c, k);
    dbg(tmp);
    ans += tmp;
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