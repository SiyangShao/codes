#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> E(40);
  for (auto &i : a) {
    cin >> i;
    int cnt = 0;
    while (i) {
      cnt++;
      i /= 2;
    }
    E[cnt]++;
  }
  cout << *max_element(E.begin(), E.end()) << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}