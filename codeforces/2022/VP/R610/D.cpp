#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 300;
array<ll, N> mp;
ll ak = 0;
auto ask(ll len) {
    for (ll i = 0; i < len; ++i) {
        if (mp[i] == 0) {
            cout << "a";
        } else {
            cout << "b";
        }
    }
    cout << endl;
    ll num;
    cout.flush();
    cin >> num;
    ak++;
    return num;
}
auto solve() {
    mp.fill(0);
    ll bs = ask(N);
    if (N == 0) {
        return;
    }
    mp.fill(1);
    ll bbs = ask(N);
    ll n = 2 * N - bs - bbs;
    mp.fill(0);
    ll A = N - bs;
    ll B = n - A;
    for (ll i = 0; i + 1 < n; ++i) {
        mp[i] = 1;
        ll ans = ask(n);
        if (ans == 0) {
            assert(ak <= n + 2);
            return;
        }
        if (ans > B) {
            mp[i] = 0;
        } else {
            B--;
        }
    }
    if (B) {
        mp[n - 1] = 1;
    }
    ll ans = ask(n);
    assert(ans == 0 && ak <= n + 2);
}
auto main() -> int {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}