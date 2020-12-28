#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    int g = 0;
    string pre = "";
    while (n--) {
        string tmp;
        cin >> tmp;
        if (tmp != pre) {
            g++;
        }
        pre = tmp;
    }
    cout << g << "\n";
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
