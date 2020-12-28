#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1LL << 20;
array<ll, N> b, ans;
auto solve() {
    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    ans.fill(0);
    for (int l = 0; l < n; ++l) {
        ll res = 1;
        for (ll r = l; r < n; ++r) {
            if (r == l) {
                res *= b[r];
            } else {
                if (b[r] >= 20)
                    break;
                res *= (1LL << b[r]);
            }
            if (res >= N)
                break;
            auto m = n - r + l - 3;
            auto q = k - 2;
            if (l == 0)
                m++, q++;
            if (r == n - 1)
                m++, q++;
            if (m >= q && (m == 0 || (q > 0 && ((m - 1) | (q - 1)) == (m - 1))))
                ans[res] ^= 1;
        }
    }
    bool start = false;
    for (auto i = ans.rbegin(); i < ans.rend(); ++i) {
        if (*i == 1) {
            cout << *i;
            start = true;
        } else if (start) {
            cout << *i;
        }
    }
    if (!start) {
        cout << 0;
    }
    cout << "\n";
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