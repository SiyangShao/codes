#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    bool allzero = true;
    for (auto &i : a) {
        cin >> i;
        if (i != 0) {
            allzero = false;
        }
    }
    if (allzero) {
        cout << "0\n";
        return;
    }
    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i = 0; i + 1 < n; ++i) {
        sum += a[i];
    }
    ll ma = a[n - 1];
    if (ma >= sum * 2) {
        cout << sum + (ma - sum * 2) << "\n";
    } else {
        if (sum + 1 >= ma) {
            cout << "1\n";
        } else {
            cout << ma - sum << "\n";
        }
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