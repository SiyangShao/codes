#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<string> s(n);
  stack<pair<ll, ll>> st;
  for (auto &i : s) {
    cin >> i;
  }
  ll k = -1;
  for (auto &i : s) {
    ll l = 0, r = 0;
    for (auto &j : i) {
      if (j == 's') {
        l++;
      } else if (j == 't') {
        r++;
      } else {
        if (j == '{') {
          st.emplace(l, r);
        } else {
          auto [x, y] = st.top();
          st.pop();
          if (y == 0 && r == 0) {
            if (x != l) {
              cout << "-1\n";
              return 0;
            }
          } else {
            if (k != -1) {
              if (x + k * y != l + k * r) {
                cout << "-1\n";
                return 0;
              }
            } else {
              k = (l - x) / (y - r);
              if (k < 0) {
                cout << "-1\n";
                return 0;
              }
            }
          }
        }
      }
    }
  }
  if (k == -1)
    cout << "1\n";
  else
    cout << k << "\n";
}