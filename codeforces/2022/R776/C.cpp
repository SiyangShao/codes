#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(m, vector<ll>(3));
    for (int i = 0; i < m; ++i) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i + 1;
    }
    sort(a.begin(), a.end(), [](auto x, auto y) { return x[1] < y[1]; });
    vector<vector<ll>> b(n * 2, vector<ll>(2));
    ll sum = 0;
    for (int i = 0; i < n * 2; ++i) {
        b[i][0] = a[i][0], b[i][1] = a[i][2];
        sum += a[i][1];
    }
    sort(b.begin(), b.end(), [](auto x, auto y) { return x[0] < y[0]; });
    cout << sum << "\n";
    for (int i = 0; i < n; ++i) {
        cout << b[i][1] << " " << b[n * 2 - 1 - i][1] << "\n";
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