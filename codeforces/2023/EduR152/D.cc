#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }
  vector<int> aft;
  bool flag = false, one = false;
  auto solve = [&]() {
    int ans = 0;
    for (auto i : aft) {
      if (i == 1) {
        ans++;
      }
    }
    int zero = (int)aft.size() - ans;
    zero -= min(zero, ans);
    return ans + zero;
  };
  int cnt = 0;
  for (auto i : a) {
    if (i == 0) {
      if (flag) {
        flag = false;
      } else {
        if (one) {
          one = false;
          aft.emplace_back(1);
        }
        aft.emplace_back(0);
      }
    } else if (i == 1) {
      if (flag || one) {
        continue;
      } else {
        one = true;
      }
    } else {
      if (flag) {
        continue;
      }
      cnt++;
      flag = true;
      one = false;
      if (!aft.empty()) {
        assert(aft.back() == 0);
        aft.pop_back();
        cnt += solve();
        aft.clear();
      }
    }
  }
  if (one) {
    aft.emplace_back(1);
  }
  cnt += solve();
  cout << cnt << "\n";
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