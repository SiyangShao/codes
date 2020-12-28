#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i: a) {
        cin >> i;
    }
    if (a[n - 2] > a[n - 1]) {
        cout << "-1\n";
        return;
    }
    auto res = a[n - 2] - a[n - 1];
    if (res <= a[n - 2]) {
        cout << n - 2 << "\n";
        for (int i = 1; i <= n - 2; ++i) {
            cout << i << " " << n - 1 << " " << n << "\n";
        }
        return;
    } else {
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                cout << "-1\n";
                return;
            }
        }
        cout << "0\n";
        return;
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