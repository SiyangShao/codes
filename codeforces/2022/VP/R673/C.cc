#pragma GCC optimize("Ofast", "unroll-loops", "O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

void solve() {
  int n;
  cin >> n;
  bool arr[n][32];
  int left[n];
  memset(left, 0, sizeof left);
  bool op[n];
  ll x = 0;
  ll k = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j <= 31; j++) {
      arr[i][j] = x % 2;
      x /= 2;
    }
  }

  unordered_map<ll, ll, custom_hash> n0, n1;
  for (int bit = 30; bit >= 0; bit--) {
    ll tick = 0, nottick = 0;
    ll pos = (1 << bit);
    for (ll i = 0; i < n; i++) {
      ll a = left[i];
      if (arr[i][bit]) {
        tick += n0[a];
        n1[a] += 1;
        op[i] = true;
      } else {
        nottick += n1[a];
        n0[a] += 1;
        op[i] = false;
      }
    }
    if (tick < nottick) {
      x += pos;
      k += tick;

      for (int i = 0; i < n; i++) {
        left[i] = left[i] * 2 + !op[i];
      }
    } else {
      k += nottick;

      for (int i = 0; i < n; i++) {
        left[i] = left[i] * 2 + op[i];
      }
    }
    n0.clear();
    n1.clear();
  }
  cout << k << " " << x << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}

/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/
