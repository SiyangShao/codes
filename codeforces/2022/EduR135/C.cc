#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto f(ll a) {
  ll cnt = 0;
  assert(a != 0);
  while (a) {
    cnt++;
    a /= 10;
  }
  return cnt;
}
auto solve() {
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  multiset<ll> A, B;
  for (auto &i : a) {
    cin >> i;
    A.emplace(i);
  }
  ll ans = 0;
  for (auto &i : b) {
    cin >> i;
    auto ptrA = A.find(i);
    if (ptrA == A.end()) {
      if (i >= 10) {
        B.emplace(f(i));
        ans++;
      } else {
        B.emplace(i);
      }
      continue;
    }
    A.erase(ptrA);
  }
  multiset<ll> nxtA;
  for (auto i : A) {
    if (i >= 10) {
      nxtA.emplace(f(i));
      ans++;
    } else {
      nxtA.emplace(i);
    }
  }
  A = move(nxtA);
  auto cur = A.begin();
  while (cur != A.end()) {
    auto ptrB = B.find(*cur);
    if (ptrB == B.end()) {
      cur++;
      continue;
    }
    auto the = cur;
    cur++;
    A.erase(the);
    B.erase(ptrB);
  }
  for (auto i : A) {
    if (i != 1) {
      ans++;
    }
  }
  for (auto i : B) {
    if (i != 1) {
      ans++;
    }
  }
  cout << ans << "\n";
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