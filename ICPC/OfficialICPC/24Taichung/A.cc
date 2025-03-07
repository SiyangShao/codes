#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  vector<int> a(4);
  for (auto &i : a) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < 4; i++) {
    if (i + 1 != a[i]) {
      cout << i + 1 << "\n";
      return 0;
    }
  }
  cout << "5\n";
}
