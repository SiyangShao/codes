#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  array<vector<int>, 2> a;
  a[0].resize(n), a[1].resize(n);
  iota(a[0].begin(), a[0].end(), 0);
  iota(a[1].begin(), a[1].end(), n);
  int step;
  cin >> step;
  while (step--) {
    int x;
    cin >> x;
    pair<int, int> fi, se;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        if (a[i][j] == x) {
          fi = {i, j};
        }
        if (a[i][j] == 0) {
          se = {i, j};
        }
      }
    }
    swap(a[fi.first][fi.second], a[se.first][se.second]);
  }
  for(int i = 0 ;i < 2; ++i) {
    for(int j = 0; j < n; ++j) {
      cout << a[i][j] << " \n"[j + 1 == n];
    }
  }
}