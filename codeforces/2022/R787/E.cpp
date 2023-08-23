#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char high = 'a', low = 'a', ans = 'z';
    for (auto i : s) {
        if (k <= 0) {
            if (i <= low) {
                cout << "a";
            } else if (i <= high) {
                cout << min(i, ans);
            } else {
                cout << i;
            }
            continue;
        }
        if (i <= low) {
            cout << "a";
        } else if (i - low <= k) {
            k -= i - low;
            low = i;
            cout << "a";
        } else {
            high = i;
            ans = high - k;
            k = 0;
            cout << ans;
        }
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