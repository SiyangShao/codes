#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  int half = (n + 1) / 2 - 1;
  // 1 __x __x __ x
  int cnt = half / 3;
  cout << cnt * 2 + (n % 2 == 0 ? 2 : 1) << " " << n << "\n";
}