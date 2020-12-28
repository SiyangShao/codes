#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<ll> rep;
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            if (!rep.empty() && i - 1 != rep.back()) {
                flag = true;
            }
            rep.emplace_back(i);
        }
    }
    if (flag) {
        cout << rep.back() - rep.front() - 1 << "\n";
    } else {
        if (rep.size() <= 1) {
            cout << "0\n";
        } else if (rep.size() == 2) {
            cout << "1\n";
        } else {
            cout << rep.size() - 2 << "\n";
        }
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