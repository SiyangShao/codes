#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mp(n, vector<ll>(m));
    for (auto &i : mp) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    auto sorted = mp;
    for (auto& i : sorted) {
        sort(i.begin(), i.end());
    }
    vector<ll> exchange;
    exchange.clear();
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (mp[i][j] != sorted[i][j]) {
                exchange.emplace_back(j);
            }
        }
        if (exchange.size() > 2) {
            cout << "-1\n";
            return;
        } else if (exchange.size() == 2) {
            break;
        }
    }
    if (exchange.size() == 0) {
        cout << "1 1\n";
        return;
    }
    for (ll i = 0; i < n; ++i) {
        auto L = exchange[0], R = exchange[1];
        swap(mp[i][L], mp[i][R]);
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (mp[i][j] != sorted[i][j]) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << exchange[0] + 1 << " " << exchange[1] + 1 << "\n";
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