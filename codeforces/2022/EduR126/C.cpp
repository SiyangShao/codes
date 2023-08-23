#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
auto cal(vector<ll> &h, ll height) {
    priority_queue<ll> Q;
    for (auto &i : h) {
        Q.push(height - i);
    }
    ll one = 0, two = 0;
    while (!Q.empty()) {
        auto res = Q.top();
        Q.pop();
        if (res % 2 == 0) {
            two += res / 2;
        } else {
            two += res / 2;
            one++;
        }
    }
    // cout << one << " " << two << " ";
    if (two - one > 1) {
        auto tmp = (two - one - 1) / 3;
        two -= tmp;
        one += tmp * 2;
    }
    while (two - one > 1) {
        two--;
        one += 2;
    }
    // cout << "Final" << one << " " << two << " ";
    if (one > two) {
        return one * 2 - 1;
    } else if (one == two) {
        return one * 2;
    } else {
        return two * 2;
    }
}
auto solve() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    ll height = 0;
    for (auto &i : h) {
        cin >> i;
        height = max(height, i);
    }
    auto c1 = cal(h, height);
    auto c2 = cal(h, height + 1);
    auto c3 = cal(h, height + 2);
    cout << min(c1, min(c2, c3)) << "\n";
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