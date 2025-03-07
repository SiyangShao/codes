#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  int sum = a * 4;
  if (a == b) {
    cout << "1\n";
    cout << a << "\n";
  } else if (a < b) {
    cout << "4\n";
    cout << sum - (b * 3 + 1) << " " << b - 1 << " " << b + 1 << " " << b + 1
         << "\n";
  } else {
    cout << "4\n";
    cout << b - 1 << " " << b - 1 << " " << b + 1 << " " << sum - (b * 3 - 1)
         << "\n";
  }
}
