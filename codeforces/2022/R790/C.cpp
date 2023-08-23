#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;
// 我走在每天必须面对的分岔路
// 我怀念过去单纯美好的小幸福
auto judge(string &a, string &b) {
    ll cnt = 0;
    for (int i = 0; i < a.length(); ++i) {
        cnt += abs(a[i] - b[i]);
    }
    return cnt;
}
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &i : s) {
        cin >> i;
    }
    ll cnt = LONG_LONG_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cnt = min(cnt, judge(s[i], s[j]));
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