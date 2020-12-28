#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), num;
    num.assign(n + 1, 0);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    auto pos = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != b[pos]) {
            if (num[a[i]] == 0) {
                cout << "NO\n";
                return;
            } else {
                num[a[i]]--;
            }
        } else {
            auto cnt = b[pos];
            pos--;
            while (pos >= 0 && b[pos] == cnt) {
                pos--;
                num[cnt]++;
            }
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