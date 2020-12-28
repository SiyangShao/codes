#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
  }
  a[1] = 1;
  int one = -1;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == 1) {
      one = i;
      break;
    }
  }
  int aftOne = n - 1 - one;
  if (one != 0)
    aftOne++;
  if (aftOne >= 2) {
    cout << aftOne << "\n";
    return 0;
  }
  // check if 1
  int zeroNum = 0;
  for (int i = 1; i < one; ++i) {
    if (a[i] == 0)
      zeroNum++;
  }
  if (zeroNum == 0) {
    cout << "1\n";
  } else {
    cout << "2\n";
  }
}