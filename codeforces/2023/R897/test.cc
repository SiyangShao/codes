#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int k = 8;
  int len = 14;
  vector<int> a(len);
  int res = len % k;
  iota(a.begin(), a.end(), 1);
  for (int i = 0; i + k - 1 < len; i += res / 2) {
    cout << "Ask: ";
    for (int j = i; j < i + k; ++j) {
      cout << a[j] << " ";
    }
    cout << "\n";
    reverse(a.begin() + i, a.begin() + i + k);
  }
}