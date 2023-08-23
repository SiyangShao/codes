#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "U\n";
    return;
  }
  vector mp(n, vector<int>(n, -1));
  auto dis = [&](int i, int j) {
    return min(min(i, n - 1 - i), min(j, n - 1 - j));
  };
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dis(i, j) % 2 == 0) {
        int v = dis(i, j);
        if (j == v && n - 1 - i != v) {
          mp[i][j] = 0;
        } else if (i == v) {
          mp[i][j] = 1;
        } else if (n - 1 - j == v) {
          mp[i][j] = 2;
        } else {
          mp[i][j] = 3;
        }
      }
    }
  }
  int mid = n / 2;
  if (n % 2 == 1 && dis(mid, mid) % 2 == 0) {
    mp[mid][mid] = -1;
    mp[mid][mid - 1] = 1;
    mp[mid][mid + 1] = 3;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mp[i][j] == -1) {
        cout << ".";
      } else if (mp[i][j] == 0) {
        cout << "U";
      } else if (mp[i][j] == 1) {
        cout << "R";
      } else if (mp[i][j] == 2) {
        cout << "D";
      } else if (mp[i][j] == 3) {
        cout << "L";
      }
    }
    cout << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}