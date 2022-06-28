#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> positive, negative;
    positive.clear(), negative.clear();
    ll zero = 0;
    for (auto &i : a) {
        cin >> i;
        if (i == 0) {
            zero++;
        } else if (i > 0) {
            positive.emplace_back(i);
        } else {
            negative.emplace_back(i);
        }
    }
    if (positive.empty() && negative.empty()) {
        cout << "YES\n";
    } else if (positive.size() >= 3 || negative.size() >= 3) {
        cout << "NO\n";
    } else {
        vector<ll> sel;
        sel.clear();
        set<ll> st;
        st.clear();
        for (auto i : positive) {
            sel.emplace_back(i);
            st.insert(i);
        }
        for (auto i : negative) {
            sel.emplace_back(i);
            st.insert(i);
        }
        if (zero) {
            st.insert(0);
            for (ll i = 0; i < sel.size(); ++i) {
                for (ll j = i + 1; j < sel.size(); ++j) {
                    auto cur = sel[i] + sel[j];
                    if (st.find(cur) != st.end()) {
                        continue;
                    } else {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
        for (ll i = 0; i < sel.size(); ++i) {
            for (ll j = i + 1; j < sel.size(); ++j) {
                for (ll k = j + 1; k < sel.size(); ++k) {
                    auto cur = sel[i] + sel[j] + sel[k];
                    if (st.find(cur) != st.end()) {
                        continue;
                    } else {
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
        cout << "YES\n";
    }
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
