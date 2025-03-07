#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  set<ll> st;
  for (ll i = 1; i < n; ++i) {
    st.emplace(a[i - 1]);
    st.emplace(a[i]);
    st.emplace(a[i - 1] & a[i]);
    st.emplace(a[i - 1] ^ a[i]);
    st.emplace(a[i - 1] | a[i]);
    st.emplace(a[i - 1] & (a[i] ^ a[i - 1]));
    st.emplace(a[i] & (a[i] ^ a[i - 1]));
    st.emplace(0);
  }
  cout << st.size() << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
