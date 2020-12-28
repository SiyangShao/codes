#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector mp(n, vector<ll>(n, 0));
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    for (auto &i : b) {
        cin >> i;
        i--;
    }
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    }
    /**
     * @brief
     * Observation 1: adj point won't be changed
     */
    for (ll i = 0; i + 1 < n; ++i) {
        mp[a[i]][a[i + 1]]++;
        mp[a[i + 1]][a[i]]++;
    }
    for (ll i = 0; i + 1 < n; ++i) {
        mp[b[i]][b[i + 1]]--;
        mp[b[i + 1]][b[i]]--;
        if (mp[b[i]][b[i + 1]] < 0 || mp[b[i + 1]][b[i]] < 0) {
            cout << "NO\n";
            return;
        }
    }
    vector<pair<ll, ll>> ans;
    ans.clear();
    for (ll i = 1; i + 1 < n; ++i) {
        if (a[i] != b[i]) {
            for (ll j = i + 1; j < n; ++j) {
                if (a[j] == a[i - 1] && a[j - 1] == b[i]) {
                    ans.emplace_back(i - 1, j);
                    reverse(a.begin() + i - 1, a.begin() + j + 1);
                }
            }
        }
        if (a[i] != b[i]) {
            for (ll j = i; j + 1 < n; ++j) {
                if (a[j] == b[i - 1] && a[j + 1] == b[i]) {
                    for (ll p = i - 1; p <= j; ++p) {
                        for (ll q = n - 1; q >= j + 1; q--) {
                            if (a[p] == a[q]) {
                                ans.emplace_back(p, q);
                                reverse(a.begin() + p, a.begin() + q + 1);
                                i--;
                                goto label;
                            }
                        }
                    }
                }
            }
        }
    label:
        continue;
    }
    if (a != b) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto &[l, r] : ans) {
        cout << l + 1 << " " << r + 1 << "\n";
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