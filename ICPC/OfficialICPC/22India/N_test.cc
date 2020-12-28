#include <bits/stdc++.h>
using namespace std;
int mp[3][3];
int main() {
  set<int> st;
  for (int i = 0; i < (1 << 9); ++i) {
    for (int j = 0; j < 9; ++j) {
      mp[j / 3][j % 3] = (i >> j) & 1;
    }
    // check how many neighbour grid are different
    int cnt = 0;
    for (int j = 0; j < 9; ++j) {
      int x = j / 3, y = j % 3;
      if (x > 0)
        cnt += mp[x][y] != mp[x - 1][y];
      if (x < 2)
        cnt += mp[x][y] != mp[x + 1][y];
      if (y > 0)
        cnt += mp[x][y] != mp[x][y - 1];
      if (y < 2)
        cnt += mp[x][y] != mp[x][y + 1];
    }
    if (!st.contains(cnt / 2)) {
      st.emplace(cnt / 2);
      cout << cnt / 2 << "\n";
      for (int j = 0; j < 9; ++j) {
        cout << mp[j / 3][j % 3] << " ";
        if (j % 3 == 2)
          cout << "\n";
      }
      cout << "\n";
    }
  }
  for (auto i : st) {
    cout << i << " ";
  }
  cout << "\n";
}