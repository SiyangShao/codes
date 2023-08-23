#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    queue<ll> odd, even;
    for (auto i : s) {
        if ((i - '0') % 2 == 0) {
            even.emplace(i - '0');
        } else {
            odd.emplace(i - '0');
        }
    }
    while (!even.empty() && !odd.empty()) {
        if (even.front() < odd.front()) {
            cout << even.front();
            even.pop();
        } else {
            cout << odd.front();
            odd.pop();
        }
    }
    while (!even.empty()) {
        cout << even.front();
        even.pop();
    }
    while (!odd.empty()) {
        cout << odd.front();
        odd.pop();
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