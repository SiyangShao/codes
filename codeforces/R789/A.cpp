#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    mp.clear();
    int flag = 0;
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
        if (mp[i] >= 2) {
            flag = max(flag, 1);
        } else if (i == 0) {
            flag = max(flag, 2);
        }
    }
    if (flag == 0) {
        cout << n + 1 << "\n";
    } else if (flag == 1) {
        cout << n << "\n";
    } else {
        cout << n - mp[0] << "\n";
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