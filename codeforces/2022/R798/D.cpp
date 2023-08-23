#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (auto &i : mp) {
        cin >> i;
    }
    array<pair<ll, ll>, 4> corner;
    for (auto &[l, r] : corner) {
        l = -1, r = -1;
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (mp[i][j] == 'B') {
                if (corner[0].first == -1) {
                    for (auto &[l, r] : corner) {
                        l = i;
                        r = j;
                    }
                }
                if (i + j > corner[0].first + corner[0].second) {
                    corner[0] = {i, j};
                }
                if (i + j < corner[1].first + corner[1].second) {
                    corner[1] = {i, j};
                }
                if (i - j > corner[2].first - corner[2].second) {
                    corner[2] = {i, j};
                }
                if (i - j < corner[3].first - corner[3].second) {
                    corner[3] = {i, j};
                }
            }
        }
    }
    if (corner[0].first == -1) {
        cout << "1 1\n";
    } else {
        ll ans = 1e9 + 7, LL = 1, RR = 1;
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                ll tmp = 0;
                for (auto &[l, r] : corner) {
                    tmp = max(tmp, abs(i - l) + abs(j - r));
                }
                if (tmp < ans) {
                    ans = tmp;
                    LL = i + 1;
                    RR = j + 1;
                }
            }
        }
        cout << LL << " " << RR << "\n";
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