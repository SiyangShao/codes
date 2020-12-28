#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<string> tmp(n);
    for (auto &i : tmp) {
        cin >> i;
    }
    vector<vector<ll>> mp(n, vector<ll>(n, 0));
    vector<ll> col(n, 0), row(n, 0);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            mp[i][j] = tmp[i][j] == '1';
            col[i] += mp[i][j];
            row[j] += mp[i][j];
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += (col[i] == n) + (row[i] == n);
    }
    ll add = 0;
    while (q--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll i, j, b;
            cin >> i >> j >> b;
            i--, j--;
            j = (j + add) % n;

            if (mp[i][j] == b) {
                cout << ans << "\n";
                continue;
            } else {
                if (mp[i][j] == 1) {
                    if (col[i] == n) {
                        ans--;
                    }
                    col[i]--;
                    if (row[j] == n) {
                        ans--;
                    }
                    row[j]--;
                    mp[i][j] = 0;
                } else {
                    mp[i][j] = 1;
                    col[i]++, row[j]++;
                    ans += (col[i] == n) + (row[j] == n);
                }
                cout << ans << "\n";
            }
        } else {
            ll b;
            cin >> b;
            ll end = add + n - 1;
            end %= n;
            for (ll i = n - 1; i > 0; --i) {
                if (mp[i][end] == mp[i - 1][end]) {
                    continue;
                }
                if (mp[i][end] == 0) {
                    col[i]++;
                    if (col[i] == n) {
                        ans++;
                    }
                } else {
                    col[i]--;
                    if (col[i] == n - 1) {
                        ans--;
                    }
                }
                mp[i][end] = mp[i - 1][end];
            }
            if (mp[0][end] == 0 && b == 1) {
                col[0]++;
                if (col[0] == n) {
                    ans++;
                }
            } else if (mp[0][end] == 1 && b == 0) {
                col[0]--;
                if (col[0] == n - 1) {
                    ans--;
                }
            }
            mp[0][end] = b;
            if (row[end] == n) {
                ans--;
            }
            row[end] = 0;
            for (ll i = 0; i < n; ++i) {
                row[end] += mp[i][end];
            }
            ans += (row[end] == n);
            // for(ll i = 0 ; i < n; ++i){
            //     cout<<col[i]<<" ";
            // }
            cout << ans << "\n";
            add = end;
        }
        // for (ll i = 0; i < n; ++i) {
        //     for (ll j = 0; j < n; ++j) {
        //         cout << mp[i][(j ) % n] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";
    }
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