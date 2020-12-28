#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll cnt = 0;
    for (auto &i : a) {
        cin >> i;
        cnt += (i - 1);
    }
    if (cnt % 2 == 1) {
        cout << "errorgorn\n";
    } else {
        cout << "maomao90\n";
    }
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