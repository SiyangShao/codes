#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto cal(vector<pair<ll, ll>> &num) -> pair<ll, pair<ll, ll>> {
    ll res = 0, neg = 0;
    auto n = num.size();
    for (auto &&[i, pos] : num) {
        if (abs(i) == 2) {
            res++;
        }
        if (i < 0) {
            neg++;
        }
    }
    // cout << res << " " << neg << "\n";
    if (neg % 2 == 0) {
        return {res, {num[0].second, num[n - 1].second}};
    }
    ll L = -1, R = n, LL = 0, RR = 0;
    for (ll i = 0; i < n; ++i) {
        if (abs(num[i].first) == 2) {
            LL++;
        }
        if (num[i].first < 0) {
            L = i;
            break;
        }
    }
    for (ll i = n - 1; i >= 0; --i) {
        if (abs(num[i].first) == 2) {
            RR++;
        }
        if (num[i].first < 0) {
            R = i;
            break;
        }
    }
    // cout << LL << " " << RR << "\n";
    // cout << res << ", " << LL << ", " << L << ":" << RR << ", " << R << "...
    // "; if (res / LL > res / RR) {
    //     return {res / LL, {num[L].second, num[n - 1].second}};
    // } else {
    //     return {res / RR, {num[0].second, num[R].second}};
    // }
    if ((L + 1 >= n || L + 1 < 0) && (R - 1 < 0 || R - 1 >= n)) {
        return {0, {num[0].second, num[n - 1].second}};
    } else if (L + 1 >= n || L + 1 < 0) {
        return {res - RR, {num[0].second, num[R - 1].second}};
    } else if (R - 1 < 0 || R - 1 >= n) {
        return {res - LL, {num[L + 1].second, num[n - 1].second}};
    } else {
        if (res - LL > res - RR) {
            return {res - LL, {num[L + 1].second, num[n - 1].second}};
        } else {
            return {res - RR, {num[0].second, num[R - 1].second}};
        }
    }
}
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<pair<ll, ll>> b;
    vector<vector<pair<ll, ll>>> c;
    b.clear(), c.clear();
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            if (!b.empty())
                c.emplace_back(b);
            b.clear();
        } else {
            b.emplace_back(a[i], i);
        }
    }
    if (!b.empty())
        c.emplace_back(b);
    ll res = 0, L = 0, R = -1;
    for (auto i : c) {
        auto [tmp, range] = cal(i);
        // cout << tmp << " " << range.first << " " << range.second << "\n";
        // cout << tmp << "??? ";
        if (tmp > res) {
            res = tmp;
            L = range.first, R = range.second;
            // cout << L << " " << R << "?";
        }
    }
    cout << L << " " << n - 1 - R << "\n";
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