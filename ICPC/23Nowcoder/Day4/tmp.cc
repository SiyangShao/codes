#include <bits/stdc++.h>
using namespace std;
int mp[1010][1010];
int main() {
  for (int n = 1; n <= 1000; ++n) {
    cout << "Start " << n << endl;
    int m;
    cin >> m;
    for (int i = 1; i <= 1000; ++i) {
      for (int j = 1; j <= 1000; ++j) {
        mp[i][j] = i * 1000 + j;
      }
    }
    while (m--) {
      int x, y, z;
      cin >> x >> y >> z;
      if (mp[x][y] == mp[x - 1][y] || mp[x][y] == mp[x][y - 1]) {
        cout << n << " same \n";
        return 0;
      }
      set<int> st;
      if (x < 1 || x > n || x + z - 1 > n || y < 1 || y > n || y + z - 1 > n) {
        cout << x << " " << y << " " << z << "\n";
        cout << n << " out \n";
        return 0;
      }
      for (int i = x; i < x + z; ++i) {
        for (int j = y; j < y + z; ++j) {
          st.emplace(mp[i][j]);
        }
      }
      if (st.size() == 1 && z != 1) {
        cout << x << " " << y << " " << z << "\n";
        cout << n << " only!\n";
        return 0;
      }
      if (st.size() > 50) {
        cout << n << " size \n";
        return 0;
      }
      for (int i = x; i < x + z; ++i) {
        for (int j = y; j < y + z; ++j) {
          mp[i][j] = mp[x][y];
        }
      }
    }
    set<int> st;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        st.emplace(mp[i][j]);
      }
    }
    if (st.size() != 1) {
      cout << n << " not finish\n";
      return 0;
    }
  }
}