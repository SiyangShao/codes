#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  vector<ll> magic = {1, 6, 3, 8, 5, 2, 7, 4};
  vector<vector<ll>> wtf = {{},
                            {1},
                            {1, 2},
                            {1, 2, 3},
                            {1, 4, 3, 2},
                            {1, 4, 3, 2, 5},
                            {1, 2, 5, 6, 3, 4},
                            {1, 2, 3, 4, 7, 6, 5}};
  ll T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    ll res = n % 8;
    for (auto i : wtf[res])
      cout << i << " ";
    ll offset = res;
    for (ll t = 1; t <= n / 8; ++t) {
      for (auto e : magic)
        cout << e + offset << " ";
      offset += 8;
    }
    cout << "\n";
  }
}