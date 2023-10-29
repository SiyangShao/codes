#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
template <typename T> class FenwickTree {
public:
  FenwickTree(int n) : bits(n + 1, 0) {}
  void update(int i, T delta) {
    while (i < static_cast<int>(bits.size())) {
      bits[i] += delta;
      i += i & -i;
    }
  }
  [[nodiscard]] T query(int i) const {
    T sum = 0;
    while (i > 0) {
      sum += bits[i];
      i -= i & -i;
    }
    return sum;
  }
  [[nodiscard]] T query(int l, int r) const { return query(r) - query(l - 1); }

private:
  std::vector<T> bits;
};
constexpr int N = 1e6 + 7;
array<set<int>, N> st;
auto solve() {
  int q;
  cin >> q;
  vector<int> a(q + 10, 0), b(q + 10, 0);
  FenwickTree<int> fw(q + 10);
  int cur = 0;
  stack<vector<int>> roll;
  while (q--) {
    string op;
    cin >> op;
    if (op == "!") {
      assert(!st.empty());
      auto vec = std::move(roll.top());
      roll.pop();
      if (vec[0] == 1) {
        cur += vec[1];
        continue;
      } else {
        int x = vec[1], val = vec[2], pre = vec[3], curb = vec[4];
        fw.update(cur, pre - curb);
        b[cur] = pre;
        st[x].erase(cur);
        a[cur] = val;
        st[val].emplace(cur);
        cur--;
      }
    } else if (op == "+") {
      cur++;
      int x;
      cin >> x;
      int val = a[cur];
      st[val].erase(cur);
      a[cur] = x;
      st[x].emplace(cur);
      int pre = b[cur];
      if (*st[x].begin() == cur) {
        b[cur] = 1;
      } else {
        b[cur] = 0;
      }
      fw.update(cur, b[cur] - pre);
      roll.emplace(vector{0, x, val, pre, b[cur]});
    } else if (op == "-") {
      int k;
      cin >> k;
      cur -= k;
      roll.emplace(vector{1, k});
    } else {
      assert(op == "?");
      cout << fw.query(cur) << endl;
    }
  }
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