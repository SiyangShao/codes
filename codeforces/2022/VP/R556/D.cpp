#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 100010;
array<array<ll, 26>, N> mp;
array<array<array<ll, 255>, 255>, 255> dp;
string a, b, c;
auto init(ll n, string &s) {
    for (ll i = 0; i < N; ++i) {
        mp[i].fill(N - 1);
    }
    for (ll i = n - 1; i >= 0; --i) {
        for (ll j = 0; j < 26; ++j) {
            mp[i][j] = mp[i + 1][j];
        }
        mp[i][s[i] - 'a'] = i + 1;
    }
    a = "_", b = "_", c = "_";
}
auto solve() {
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    init(n, s);
    dp[0][0][0] = 0;
    while (q--) {
        string op;
        cin >> op;
        if (op[0] == '+') {
            ll a_i;
            string add;
            cin >> a_i >> add;
            ll begin_a = 0, begin_b = 0, begin_c = 0;
            if (a_i == 1) {
                begin_a = a.length();
                a += add;
            } else if (a_i == 2) {
                begin_b = b.length();
                b += add;
            } else {
                begin_c = c.length();
                c += add;
            }
            for (ll i = begin_a; i < a.length(); ++i) {
                for (ll j = begin_b; j < b.length(); ++j) {
                    for (ll k = begin_c; k < c.length(); ++k) {
                        ll tmp = N - 1;
                        if (i > 0) {
                            tmp = min(tmp, mp[dp[i - 1][j][k]][a[i] - 'a']);
                        }
                        if (j > 0) {
                            tmp = min(tmp, mp[dp[i][j - 1][k]][b[j] - 'a']);
                        }
                        if (k > 0) {
                            tmp = min(tmp, mp[dp[i][j][k - 1]][c[k] - 'a']);
                        }
                        dp[i][j][k] = tmp;
                    }
                }
            }
            if (dp[a.length() - 1][b.length() - 1][c.length() - 1] <= n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            ll a_i;
            cin >> a_i;
            if (a_i == 1) {
                a.pop_back();
            } else if (a_i == 2) {
                b.pop_back();
            } else {
                c.pop_back();
            }
            if (dp[a.length() - 1][b.length() - 1][c.length() - 1] <= n) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
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