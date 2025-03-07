#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int L, n;
  cin >> L >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  auto check = [&](int m) {
    vector<int> l(n), r(n);
    l[0] = m;
    for (int i = 1; i < n; i++) {
      if (l[i - 1] == -1) {
        l[i] = -1;
        continue;
      }
      if (a[i] <= l[i - 1]) {
        l[i] = a[i] + m;
      } else {
        auto res = a[i] - l[i - 1];
        if (m < res) {
          l[i] = -1;
        } else {
          l[i] = a[i] + m - res * 2;
        }
      }
    }
    r[n - 1] = a[n - 1] - m;
    for (int i = n - 2; i >= 0; i--) {
      if (r[i + 1] == L + 1) {
        r[i] = L + 1;
        continue;
      }
      if (a[i] >= r[i + 1]) {
        r[i] = a[i] - m;
      } else {
        auto res = r[i + 1] - a[i];
        if (m < res) {
          r[i] = L + 1;
        } else {
          r[i] = a[i] - m + res * 2;
        }
      }
    }
    for (int i = 1; i < n; i++) {
      if (l[i - 1] >= r[i]) {
        return true;
      }
    }
    return false;
  };
  int l = 1, r = L;
  int ans = r;
  while (l <= r) {
    auto mid = (l + r) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans << "\n";
}
