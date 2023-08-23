#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    unordered_map<ll, int> look_up;
    unordered_map<ll, vector<int>> lp;
    ll n, k = 0, count = 0;
    string s;
    cin >> n >> k >> s;
    vector<ll> cnt;
    cnt.assign(n + 1, 0);
    if (k % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                s[i] = '1';
                continue;
            }
            if (k < 1) {
                s[i] = '0';
                continue;
            }
            cnt[i] = 1;
            k--;
            count++;
        }
        if (!(count & 1) && k > 0) {
            s[n - 1] = '0';
        }
        cnt[n - 1] += k;
        cout << s << "\n";
    } else {
        for (int i = 0; k > 0 && i < n; i++) {
            if (s[i] == '1') {
                continue;
            }
            s[i] = '1';
            cnt[i] = 1;
            k--;
            count++;
        }

        if (count & 1) {
            if (k & 1)
                s[n - 1] = '0';
            cnt[n - 1] += k;
        } else {
            cnt[n - 1] += k;
        }

        cout << s << "\n";
    }
    for (int i = 0; i < n; i++)
        cout << cnt[i] << " ";

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