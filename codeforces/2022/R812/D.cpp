#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto ask(ll u, ll v) {
    cout << "? " << u + 1 << " " << v + 1 << endl;
    ll cur;
    cin >> cur;
    return cur;
}
auto sol(vector<ll> &pos) {
    if (pos.size() == 1) {
        cout << "! " << pos[0] + 1 << endl;
        return;
    }
    if (pos.size() == 2) {
        auto ans = ask(pos[0], pos[1]);
        assert(ans != 0);
        if (ans == 1) {
            cout << "! " << pos[0] + 1 << endl;
        } else {
            cout << "! " << pos[1] + 1 << endl;
        }
        return;
    }
    assert(pos.size() % 4 == 0);
    vector<ll> nxt_pos;
    for (ll i = 0; i < pos.size(); i += 4) {
        ll a = pos[i], b = pos[i + 1], c = pos[i + 2], d = pos[i + 3];
        ll tmp = ask(a, c);
        if (tmp == 1) {
            // a > c
            if (ask(a, d) == 1) {
                nxt_pos.emplace_back(a);
            } else {
                nxt_pos.emplace_back(d);
            }
        } else if (tmp == 2) {
            if (ask(b, c) == 1) {
                nxt_pos.emplace_back(b);
            } else {
                nxt_pos.emplace_back(c);
            }
        } else {
            if (ask(b, d) == 1) {
                nxt_pos.emplace_back(b);
            } else {
                nxt_pos.emplace_back(d);
            }
        }
    }
    sol(nxt_pos);
};
auto solve() {
    ll n;
    cin >> n;
    ll N = 1LL << n;
    vector<ll> pos(N);
    iota(pos.begin(), pos.end(), 0);
    sol(pos);
}
auto main() -> int {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}