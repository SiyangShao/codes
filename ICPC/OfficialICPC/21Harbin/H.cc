#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
ll mergeAndCount(vector<int> &arr, int left, int mid, int right) {
  ll count = 0;
  int i = left, j = mid, k = 0;
  vector<int> temp(right - left);
  while (i < mid && j < right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      // Count the number of inversions
      count += (ll)(mid - i);
    }
  }
  // Copy remaining elements from left subarray, if any
  while (i < mid) {
    temp[k++] = arr[i++];
  }
  // Copy remaining elements from right subarray, if any
  while (j < right) {
    temp[k++] = arr[j++];
  }
  // Copy back the sorted elements to original array
  for (i = left, k = 0; i < right; ++i, ++k) {
    arr[i] = temp[k];
  }
  return count;
}

// Modified merge sort algorithm to count inversions
ll mergeSortAndCount(vector<int> &arr, int left, int right) {
  ll count = 0;
  if (right - left > 1) {
    int mid = (left + right) / 2;
    // Count inversions in left and right subarrays
    count += mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid, right);
    // Count inversions between left and right subarrays
    count += mergeAndCount(arr, left, mid, right);
  }
  return count;
}
auto solve() {
  int s, t;
  cin >> s;
  vector<int> a(s);
  for (auto &i : a)
    cin >> i;
  cin >> t;
  vector<int> b(t);
  for (auto &i : b)
    cin >> i;
  int k;
  cin >> k;
  vector<vector<int>> x(k), y(k);
  for (int i = 0; i < s; ++i) {
    x[i % k].emplace_back(a[i]);
  }
  for (int i = 0; i < t; ++i) {
    y[i % k].emplace_back(b[i]);
  }
  vector<int> num;
  for (int i = 0; i < k; ++i) {
    ll cntx = mergeSortAndCount(x[i], 0, (int)x[i].size());
    ll cnty = mergeSortAndCount(y[i], 0, (int)y[i].size());
    if (x[i] != y[i]) {
      cout << "NIE\n";
      return;
    }
    num.emplace_back((cntx % 2) == (cnty % 2));
    for (int j = 1; j < (int)x[i].size(); ++j) {
      if (x[i][j] == x[i][j - 1]) {
        num.pop_back();
        break;
      }
    }
  }
  if (num.empty()) {
    cout << "TAK\n";
    return;
  }
  auto result = ranges::minmax(num);
  if (result.max != result.min) {
    cout << "NIE\n";
  } else {
    cout << "TAK\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}