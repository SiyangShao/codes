#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1e9;

void solve() {
    ll n;
    cin >> n;
    if (n > 19) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ll cnt = 1;
    for (int i = 1; i <= n; ++i) {
        cout << cnt << " ";
        cnt = cnt * 3;
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