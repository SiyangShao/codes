#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e18;
constexpr int N = 6010;
array<array<int, N>, N> idx;
array<int, N> beg, lst;
ll cal(int n, const vector<int> &a, const vector<int> &b) {
  if (a == b)
    return 0;
  fill(beg.begin(), beg.end(), 0);
  fill(lst.begin(), lst.end(), 0);
  vector<int> back(n * 3LL), front(n * 3LL);
  for (int i = n * 3 - 1; i >= 0; --i) {
    int x = i;
    while (x >= n) {
      x -= n;
    }
    back[i] = (i == n * 3 - 1 ? 0 : back[i + 1]);
    if (a[x] == b[x]) {
      back[i]++;
    } else {
      back[i] = 0;
    }
  }
  for (int i = 0; i < n * 3; ++i) {
    int x = i + 1, y = i;
    while (x >= n)
      x -= n;
    while (y >= n)
      y -= n;
    front[i] = (i == 0 ? 0 : front[i - 1]);
    if (a[x] == b[y]) {
      front[i]++;
    } else {
      front[i] = 0;
    }
  }
  // dbg(back, front);
  ll ans = inf;
  for (int i = 1; i + 1 < n * 3; ++i) {
    int x = i;
    while (x >= n)
      x -= n;
    int pre = i - 1;
    int nxt = i + 1;
    if (front[pre] + back[nxt] >= n - 1) {
      int lef_most = i - front[pre];
      int lef_least = i - (n - 1 - back[nxt]);
      // dbg(pre, nxt, front[pre], back[nxt]);
      auto bval = b[x];
      while (beg[bval] < lst[bval] && idx[bval][beg[bval]] < lef_most) {
        beg[bval]++;
      }
      while (beg[bval] + 1 < lst[bval]) {
        if (idx[bval][beg[bval] + 1] > lef_least) {
          break;
        }
        beg[bval]++;
      }
      if (beg[bval] < lst[bval] && idx[bval][beg[bval]] >= lef_least &&
          i - idx[bval][beg[bval]] + back[nxt] >= n - 1) {
        ans = min(ans, (ll)i - idx[bval][beg[bval]]);
      }
    }
    idx[a[x]][lst[a[x]]++] = i;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a)
    cin >> i;
  for (auto &i : b)
    cin >> i;
  ll ans = inf;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, cal(n, a, b) + (ll)i * (n - 1));
    auto x = a[0];
    for (int j = 1; j < n; ++j) {
      a[j - 1] = a[j];
    }
    a[n - 1] = x;
  }
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    ans = min(ans, cal(n, a, b) + (ll)i * (n - 1));
    auto x = a[0];
    for (int j = 1; j < n; ++j) {
      a[j - 1] = a[j];
    }
    a[n - 1] = x;
  }
  if (ans == inf) {
    cout << -1 << "\n";
    return 0;
  }
  cout << ans << "\n";
}
