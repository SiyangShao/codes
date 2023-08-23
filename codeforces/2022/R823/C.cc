#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  vector<ll> mp(10, 0);
  for (auto &i : s) {
    mp[i - '0']++;
  }
  vector<ll> output;
  priority_queue<ll, vector<ll>, greater<>> insert;
  auto judge = [&](ll cur) {
    bool mi = true;
    for (ll i = 0; i < cur; ++i) {
      if (mp[i]) {
        mi = false;
        break;
      }
    }
    return mi;
  };
  for (auto &i : s) {
    ll cur = i - '0';
    mp[cur]--;
    if (judge(cur)) {
      assert(insert.empty() || cur <= insert.top());
      output.emplace_back(cur);
    } else {
      insert.emplace(min(cur + 1, 9LL));
    }
    while (!insert.empty() && judge(insert.top())) {
      output.emplace_back(insert.top());
      insert.pop();
    }
  }
  while (!insert.empty()) {
    output.emplace_back(insert.top());
    insert.pop();
  }
  assert(is_sorted(output.begin(), output.end()));
  for (auto &i : output) {
    cout << i;
  }
  cout << "\n";
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