#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  /**
   * @brief We want to maximize sum(p) + sum(q), which p[i] + q[j] <= c[i][j].
   * (which can be solved in Hungarian in n^3). As here c[i][j] = abs(a[i] -
   * b[j]), one possible way is p[i] = max(a[i], b[i]) and q[i] = -min(a[i],
   * b[i]). Thus, p, q satisfy p[i] + q[j]. As there exists perfect matching and
   * satisfy p[i] + q[j] <= c[i][j] for all i,j, maximum possible sum of
   * potentials is equal to the optimal solution of the assignment problem
   *
   */
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long ans = 0;
  for (auto i : a) {
    ans += i * n;
    ans -= 2 * i * (b.end() - upper_bound(b.begin(), b.end(), i));
  }
  for (auto i : b) {
    ans += i * n;
    ans -= 2 * i * (a.end() - lower_bound(a.begin(), a.end(), i));
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += abs(a[i] - b[i]);
  }
  ans -= (n - 1) * res;
  cout << ans << "\n";
}