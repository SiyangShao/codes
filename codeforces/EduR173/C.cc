#include <bits/stdc++.h>
using namespace std;
using ll = long long;
pair<ll, ll> get_free_range(int l, int r, vector<ll> &a) {
  // get the free range of l - r (inclusive)
  vector<ll> prefix(r - l + 2, 0);
  ll mi = 0, mx = 0;
  ll miPref = 0, mxPref = 0;
  for (ll i = l; i <= r; i++) {
    prefix[i - l + 1] = a[i];
    prefix[i - l + 1] += prefix[i - l];
  }
  for (ll i = 1; i < r - l + 2; i++) {
    mi = min(mi, prefix[i] - miPref);
    mx = max(mx, prefix[i] - mxPref);
    mi = min(mi, prefix[i] - mxPref);
    mx = max(mx, prefix[i] - miPref);
    miPref = min(miPref, prefix[i]);
    mxPref = max(mxPref, prefix[i]);
  }
  return {mi, mx};
}
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &i : a)
    cin >> i;
  int m = n;
  for (int i = 0; i < n; i++) {
    if (a[i] != 1 && a[i] != -1) {
      m = i;
      break;
    }
  }
  set<ll> st;
  if (m == 0) {
    auto [l, r] = get_free_range(1, n - 1, a);
    for (ll i = l; i <= r; i++) {
      st.emplace(i);
    }
    ll cur = a[0];
    st.emplace(cur);
    for (int i = 1; i < n; i++) {
      cur += a[i];
      st.emplace(cur);
    }
  } else if (m == n - 1) {
    auto [l, r] = get_free_range(0, n - 2, a);
    for (ll i = l; i <= r; i++) {
      st.emplace(i);
    }
    ll cur = a[n - 1];
    st.emplace(cur);
    for (int i = n - 2; i >= 0; --i) {
      cur += a[i];
      st.emplace(cur);
    }
  } else if (m == n) {
    auto [l, r] = get_free_range(0, n - 1, a);
    for (ll i = l; i <= r; i++) {
      st.emplace(i);
    }
  } else {
    auto [lefl, lefr] = get_free_range(0, m - 1, a);
    for (ll i = lefl; i <= lefr; i++) {
      st.emplace(i);
    }
    auto [rigl, rigr] = get_free_range(m + 1, n - 1, a);
    for (ll i = rigl; i <= rigr; i++) {
      st.emplace(i);
    }
    // cerr<<lefl<<" "<<lefr<<" "<<rigl<<" "<<rigr<<endl;
    ll lMx = 0, lMi = 0, rMx = 0, rMi = 0;
    ll cur = 0;
    for (ll i = m - 1; i >= 0; i--) {
      cur += a[i];
      lMx = max(lMx, cur);
      lMi = min(lMi, cur);
    }
    cur = 0;
    for (ll i = m + 1; i < n; i++) {
      cur += a[i];
      rMx = max(rMx, cur);
      rMi = min(rMi, cur);
    }
    st.emplace(a[m]);
    for (ll i = lMi + rMi; i <= lMx + rMx; i++) {
      st.emplace(a[m] + i);
    }
  }
  cout << st.size() << "\n";
  for (auto i : st) {
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
