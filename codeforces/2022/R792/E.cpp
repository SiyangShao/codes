#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> mp;
    mp.clear();
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    ll MEX = 0, tmp = k;
    // Obeservation: It's always better to make MEX greater
    // Normal case: MEX++, DIF--/ DIF doesn't change, DIF - MEX --;
    // OR MEX++, DIF++, DIF - MEX doesn't change
    while (mp.count(MEX) || tmp > 0) {
        if (mp.count(MEX)) {
            MEX++;
        } else {
            tmp--;
            MEX++;
        }
    }
    vector<ll> erase;
    for (auto [i, cnt] : mp) {
        if (i <= MEX) {
            continue;
        } else {
            erase.emplace_back(cnt);
        }
    }
    sort(erase.begin(), erase.end());
    ll cnt = 0;
    for (auto i : erase) {
        if (i <= k) {
            k -= i;
        } else {
            cnt++;
        }
    }
    cout << cnt << "\n";
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