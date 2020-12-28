#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
vector<string> a(18);
auto output(ll n) {
    if (a[n] != "") {
        return a[n];
    }
    output(n - 1);
    a[n] = a[n - 1] + to_string(n) + " " + a[n - 1];
    return a[n];
}
auto solve() {
    ll n;
    cin >> n;
    a[1] = "1 ";
    cout << output(n);
}
auto main() -> int {
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}