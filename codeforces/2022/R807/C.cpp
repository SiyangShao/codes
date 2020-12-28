#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, c, q;
    cin >> n >> c >> q;
    ll N = n;
    string s;
    cin >> s;
    vector<pair<ll, ll>> add(c);
    vector<ll> arr;
    arr.emplace_back(n);
    for (auto &[l, r] : add) {
        cin >> l >> r;
        n += (r - l + 1);
        arr.emplace_back(n);
    }
    map<ll, char> mp;
    mp.clear();
    function<char(ll)> find = [&](ll u) {
        if (u <= N) {
            return s[u - 1];
        }
        if (mp.contains(u)) {
            return mp[u];
        }
        auto pos = lower_bound(arr.begin(), arr.end(), u) - arr.begin();
        assert(pos > 0);
        auto pre = pos - 1;
        ll len = u - arr[pre];
        return mp[u] = find(add[pre].first + len - 1);
    };
    while (q--) {
        ll x;
        cin >> x;
        cout << find(x) << "\n";
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