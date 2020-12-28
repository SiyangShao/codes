#include <bits/stdc++.h>
using namespace std;
auto solve() {
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> b(n);
  for (auto &i : b) {
    cin >> i;
  }
  vector<int> ans(q, 0);
  vector<pair<int, int>> query(q);
  for (auto &[l, r] : query) {
    cin >> l >> r;
  }
  const int blk = (int)sqrt(k);
  vector<int> less(n + 1), more(n + 1);
  for (int num = 1; num <= blk; num++) {
    for (int i = 0; i < n; ++i) {
      less[i + 1] = less[i] + (b[i] <= num ? 1 : 0);
      more[i + 1] = more[i] + (b[i] >= k / (num + 1) + 1);
    }
    for (int i = 0; i < q; ++i) {
      auto [l, r] = query[i];
      int len = r - l + 1;
      int cntx = less[r] - less[l - 1];
      int cnty = more[r] - more[l - 1];
      if (min(cntx, len / 2) >= min(cnty, len / 2))
        continue;
      ans[i] = max(ans[i], min((cnty - cntx + 1) / 2, len / 2 - cntx));
    }
  }
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}
