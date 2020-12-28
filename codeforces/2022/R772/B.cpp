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
    int cnt = 0;
    for (int i = 1; i + 1 < n; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            if (i + 1 == n - 1) {
                a[i + 1] = a[i];
            } else {
                a[i + 1] = max(a[i], a[i + 2]);
            }
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (auto i: a) {
        cout << i << " ";
    }
    cout << "\n";
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