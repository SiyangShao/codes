#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<array<ll, 3>> E(n);
    ll id = 0;
    for (auto &[t, d, idx] : E) {
        cin >> t >> d;
        idx = ++id;
    }
    sort(E.begin(), E.end(), [&](auto x, auto y) {
        if (x[1] != y[1]) {
            return x[1] < y[1];
        } else {
            if (x[0] != y[0]) {
                return x[0] < y[0];
            } else {
                return x[2] < y[2];
            }
        }
    });
    ll sum = 0;
    for (auto &[t, d, idx] : E) {
        sum += t;
        if (sum > d) {
            cout << "*\n";
            return;
        }
    }
    sum = 0;
    vector<ll> ans;
    while (id) {
        ll del = -1, MIN = 1e16;
        ll presum = sum;
        for (ll i = 0; i < n; ++i) {
            if (E[i][2] == -1)
                continue;
            if (MIN >= E[i][0] && (del == -1 || E[i][2] < E[del][2])) {
                del = i;
            }
            presum += E[i][0];
            MIN = min(MIN, E[i][1] - presum);
        }
        if (del == -1) {
            cout << "*\n";
            return;
        }
        id--;
        sum += E[del][0];
        ans.emplace_back(E[del][2]);
        E[del][2] = -1;
    }
    assert(ans.size() == n);
    for (auto i : ans) {
        cout << i << " ";
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