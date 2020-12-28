#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1), op(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    ll change = 0;
    for (int i = n; i >= 1; --i) {
        op[i] = pos[i] % i;
        for (int j = 1; j < i; ++j) {
            pos[j] = (pos[j] + i - pos[i]) % i;
            // cout << pos[j] << " ";
        }
        // cout << "\n";
    }
    for (int i = 1; i <= n; ++i) {
        cout << op[i] << " ";
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