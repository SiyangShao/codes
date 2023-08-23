#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
void solve() {
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    vector<ll> a;
    for (auto i : s) {
        if (i == 'U' && !a.empty() && (*(a.end()-1) != 1)) {
            a.pop_back();
        } else if (i == 'U') {
            a.emplace_back(1);
        } else if (i == 'L') {
            a.emplace_back(2);
        } else {
            a.emplace_back(3);
        }
    }
    for (auto i : a) {
        if (i == 1) {
            x = x / 2;
        } else if (i == 2) {
            x = x * 2;
        } else {
            x = x * 2 + 1;
        }
    }
    cout << x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}