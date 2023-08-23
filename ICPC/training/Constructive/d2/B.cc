#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int dif = (a[i] - i * i % n + n) % n;
    for (int j = 0; j < n; ++j) {
      cout << (i * j + dif) % n << " ";
    }
    cout << "\n";
  }
}