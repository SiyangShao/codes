#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    stack<char> st;
    for (auto i : s) {
        if (!st.empty() && st.top() == i) {
            st.pop();
        } else {
            st.emplace(i);
        }
    }
    if (st.empty()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
