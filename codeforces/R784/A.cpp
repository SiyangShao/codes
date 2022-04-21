#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    cout << "Division ";
    if (n >= 1900) {
        cout << 1 << "\n";
    } else if (n >= 1600) {
        cout << 2 << "\n";
    } else if (n >= 1400) {
        cout << 3 << "\n";
    } else {
        cout << 4 << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}