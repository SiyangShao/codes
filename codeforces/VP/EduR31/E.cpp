#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
constexpr ll M = 1LL << 16;
bitset<M> pre, cnt;
auto solve() {
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<ll> fa(m * 2);
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](auto self, auto x) -> ll {
        if (x != fa[x]) {
            fa[x] = self(self, fa[x]);
        }
        return fa[x];
    };
    auto merge = [&](auto x, auto y) {
        x = find(find, x);
        y = find(find, y);
        if (x == y)
            return;
        if (x < y) {
            swap(x, y);
        }
        fa[y] = x;
        ans--;
    };
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        cnt = 0;
        for (ll j = 0; j < m / 4; ++j) {
            if (s[j] <= '9' && s[j] >= '0') {
                auto tmp = s[j] - '0';
                cnt[j * 4] = (tmp / 8) % 2;
                cnt[j * 4 + 1] = (tmp / 4) % 2;
                cnt[j * 4 + 2] = (tmp / 2) % 2;
                cnt[j * 4 + 3] = tmp % 2;
            } else {
                auto tmp = s[j] - 'A' + 10;
                cnt[j * 4] = (tmp / 8) % 2;
                cnt[j * 4 + 1] = (tmp / 4) % 2;
                cnt[j * 4 + 2] = (tmp / 2) % 2;
                cnt[j * 4 + 3] = tmp % 2;
            }
        }
        for (ll j = m - 1; j >= 0; --j) {
            ans += cnt[j];
            // cout << (cnt >> j) % 2;
        }
        // cout << "\n";
        for (ll j = m - 1; j >= 0; --j) {
            if (cnt[j]) {
                if (pre[j]) {
                    merge(j + m, j);
                    // cout << i << " " << j << "\n";
                }
                if (j + 1 != m && cnt[j + 1]) {
                    merge(j + m + 1, j + m);
                    // cout << i << " " << j << "\n";
                }
            }
        }
        for (ll j = m - 1; j >= 0; --j) {
            fa[j] = find(find, j + m) - m;
            // cout << fa[j] << " ";
            assert(fa[j] >= 0 && fa[j] < m);
        }
        // cout << "\n";
        iota(fa.begin() + m, fa.end(), m);
        pre = cnt;
    }
    cout << ans << "\n";
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