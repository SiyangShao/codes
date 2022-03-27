#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve(ll l, ll r, vector<ll> &tmp) {
    if (r == 0) {
        return tmp[0];
    }
    ll bs = 1;
    while (bs <= r) {
        bs <<= 1;
    }
    if (bs == r + 1) {
        ll MIN = INT_MAX;
        for (ll i = 0; i <= r; ++i) {
            MIN = min(MIN, tmp[i]);
        }
        return MIN;
    }
    vector<ll> L, R;
    bs /= 2;
    for (ll i = 0; i <= r; ++i) {
        if ((tmp[i] / bs) & 1) {
            L.emplace_back(tmp[i]);
        } else {
            R.emplace_back(tmp[i]);
        }
    }
    if (L.size() < R.size()) {
        swap(L, R);
    }
    // for (auto i : L) {
    //     cout << i << " ";
    // }
    // cout << "...";
    // for (auto i : R) {
    //     cout << i << " ";
    // }
    sort(R.begin(), R.end());
    // cout << R[0] << " " << bs << " ";
    return bs + solve(0, r - bs, R);
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        ll l, r;
        cin >> l >> r;
        vector<ll> a(r - l + 1);
        for (auto &i : a) {
            cin >> i;
        }
        cout << solve(l, r, a) << "\n";
    }
}