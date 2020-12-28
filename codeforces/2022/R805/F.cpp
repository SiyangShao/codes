#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e9 + 7;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    multiset<ll> st;
    st.clear();
    for (auto &i : a) {
        cin >> i;
        while (i % 2 == 0) {
            i /= 2;
        }
        st.insert(i);
    }
    for (auto &i : b) {
        cin >> i;
    }
    for (auto i : b) {
        bool flag = true;
        while (i) {
            if (st.contains(i)) {
                flag = false;
                st.erase(st.find(i));
                break;
            }
            i /= 2;
        }
        if (flag) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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