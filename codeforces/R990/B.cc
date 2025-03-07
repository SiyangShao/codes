#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  multiset<ll> b;
  stack<ll> st;
  for (auto &i : a)
    cin >> i;

  for (auto i : a) {
    while (!st.empty() && st.top() > i) {
      auto u = st.top();
      b.emplace(u + 1);
      st.pop();
    }
    if (b.empty() || i <= *b.begin())
      st.emplace(i);
    else
      b.emplace(i + 1);
  }
  vector<int> c;
  while (!st.empty()) {
    c.emplace_back(st.top());
    st.pop();
  }
  reverse(c.begin(), c.end());
  for (auto &i : c)
    cout << i << " ";
  for (auto &i : b)
    cout << i << " ";
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
