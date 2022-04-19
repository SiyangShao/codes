#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
auto get(ll l, ll r, vector<ll> &a) -> ll {
    if (l > r)
        return 0;
    else if (l == r) {
        auto tmp = a[l] - a[l - 1];
        if (tmp < 0) {
            return -1;
        } else if (tmp == 0) {
            return 0;
        } else {
            return 1;
        }
    }
    ll res = 0;
    ll LL = 0, RR = 0;
    vector<ll> b;
    unordered_map<ll, ll> mp;
    for (ll i = l; i <= r; ++i) {
        if (b.empty() || a[i] < -b.back()) {
            b.push_back(-a[i]);
            mp[b.size() - 1] = i;
        } else if (a[i] == -b.back()) {
            continue;
        } else {
            auto pos = upper_bound(b.begin(), b.end(), -a[i]) - b.begin();
            pos = mp[pos];
            if (a[i] - a[pos - 1] == 0) {
                pos++;
            }
            if (a[i] - a[pos - 1] < 0) {
                continue;
            }
            auto tmp = i - pos + 1;
            cout << i << " " << pos << "\n";
            if (res <= tmp) {
                res = tmp;
                LL = pos;
                RR = i;
            }
        }
    }
    cout << "GET " << res << " " << LL << " " << RR << "\n";
    if (res == 0 && LL == 0 && RR == 0) {
        return -(l - r + 1);
    } else {
        // cout << l << " " << r << " ";
        // cout << get(l, LL - 1, a) << " " << get(RR + 1, r, a) << "\n";
        if (a[RR] - a[LL - 1] == 0) {
            return get(l, LL - 1, a) + get(RR + 1, r, a) + 1;
        } else
            return res + get(l, LL - 1, a) + get(RR + 1, r, a);
    }
}
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    a[0] = 0;
    for (auto i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    auto res = get(1, n, a);
    cout << res << "\n";
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