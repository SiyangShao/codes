#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    ll n = s.length();
    s = "_" + s;
    vector<ll> one, zero, que;
    one.assign(n+1, 0);
    zero.assign(n+1, 0);
    que.assign(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        one[i] = one[i - 1], zero[i] = zero[i - 1], que[i] = que[i - 1];
        if (s[i] == '1') {
            one[i]++;
        } else if (s[i] == '0') {
            zero[i]++;
        } else {
            que[i]++;
        }
    }
    auto judge = [&](int pos) {
        if (que[pos - 1] - que[0] + one[pos - 1] - one[0] == pos - 1 &&
            que[n] - que[pos] + zero[n] - zero[pos] == n - pos) {
            return true;
        }
        return false;
    };
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (judge(i)) {
            cnt++;
        }
    }
    cout << cnt << "\n";
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