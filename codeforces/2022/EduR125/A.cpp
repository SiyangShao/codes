#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x;
    int y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << "0\n";
    } else if (sqrt(x * x + y * y) == int(sqrt(x * x + y * y))) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--!= 0) {
        solve();
    }
}