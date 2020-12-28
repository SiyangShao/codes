#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    set<ll> st;
    for (ll i = 0; i < n; ++i) {
        if (st.empty() || a[*st.rbegin()] > a[i]) {
            st.insert(i);
        }
    }
    while (m--) {
        ll k, d;
        cin >> k >> d;
        k--;
        a[k] -= d;
        auto it = st.lower_bound(k);
        if (it == st.end() || *it > k) {
            it--;
            if (a[k] < a[*it]) {
                st.insert(k);
            } else {
                cout << st.size() << " ";
                continue;
            }
        }
        it = st.upper_bound(k);
        for (auto i = it; i != st.end();) {
            if (a[*i] >= a[k]) {
                i = st.erase(i);
            } else {
                break;
            }
        }
        cout << st.size() << " ";
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