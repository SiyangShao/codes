#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    auto n = s.length();
    vector<int> num(26);
    ll cnt = 0;
    for (auto i : s) {
        num[i - 'a']++;
        if (num[i - 'a'] == 2) {
            cnt += 2;
            num.assign(26, 0);
        }
    }
    cout << n - cnt << "\n";
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