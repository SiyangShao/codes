#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> mp(31);
    mp.assign(31, 0);
    for (auto &i : a) {
        cin >> i;
        auto tmp = i, cnt = 0LL;
        while (tmp) {
            if (tmp % 2 == 1) {
                mp[cnt]++;
            }
            cnt++;
            tmp /= 2;
        }
    }
    auto res = 1LL << 30, cnt = 0LL;
    for (ll i = 30; i >= 0; --i) {
        if (k >= n - mp[i]) {
            k -= n - mp[i];
            cnt += res;
        }
        res >>= 1;
    }
    cout << cnt << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}