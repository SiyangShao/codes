#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> ans;
vector<array<int, 2>> arr;
void swp(int i, int pos1, int pos2, bool force = false) {
  if (force) {
    if (arr[i][pos1] == arr[i + 1][pos2])
      return;
  }
  if (arr[i][pos1] == arr[i + 1][pos2]) {
    pos2 ^= 1;
  }
  ans.emplace_back(i, arr[i][pos1], arr[i + 1][pos2]);
  swap(arr[i][pos1], arr[i + 1][pos2]);
}
void debug(int l, int r, int state) {
  cout << "=======================\n";
  cout << "From " << l << " to " << r << " and is " << state << "\n";
  for (auto &i : arr) {
    cout << i[0] << " ";
  }
  cout << "\n";
  for (auto &i : arr) {
    cout << i[1] << " ";
  }
  cout << "\n";
  cout << "=======================\n";
}
void reverse(int l, int r) {
  if (l == r) {
    return;
  }
  if (r == l + 1) {
    return;
  }
  if (r == l + 2) {
    swp(l, 0, 0, true);
    swp(l, 1, 1, true);
    return;
  }
  debug(l, r, 0);
  int mid = (l + r) / 2;
  // for l to mid-1, move it to right side
  for (int i = l; i < mid; i++) {
    int target_pos = r - (i - l) - 1;
    swp(i, 1, 0);
    for (int j = i + 1; j < target_pos; j++) {
      swp(j, 0, 0);
    }
  }
  int res = (r - l) - (mid - l);
  debug(l, r, 1);
  reverse(l, l + res);
  debug(l, r, 2);
  for (int i = l + res - 1; i >= l; i--) {
    for (int j = 0; j < 2; j++) {
      int target_pos = arr[i][j];
      if (target_pos == i)
        continue;
      swp(i, j, 1);
      for (int k = i + 1; k < target_pos; k++) {
        swp(k, 1, 1);
      }
    }
  }
  debug(l, r, 3);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    arr[i][0] = arr[i][1] = n - i - 1;
  }
  reverse(0, n);
  cout << ans.size() << endl;
  assert(ans.size() <= n * n * 0.7);
  for (auto [x, y, z] : ans) {
    cout << x + 1 << " " << y + 1 << " " << z + 1 << "\n";
  }
}
