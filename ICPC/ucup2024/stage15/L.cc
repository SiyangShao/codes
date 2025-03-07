#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << "100\n";
  for (ll i = 1; i <= 50; i++) {
    cout << a << " ";
  }
  for (ll i = 51; i <= 95; i++) {
    cout << b << " ";
  }
  for (ll i = 96; i <= 99; i++) {
    cout << c << " ";
  }
  cout << c + 1 << "\n";
}
