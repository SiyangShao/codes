#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, m; 
    while (cin >> n >> m) {
        int ans = 1;
        for (ll i = 1; i <= m; i++) {
            ll u, v, w; cin >> w >> u >> v;
            if (w % 2) ans *= w;
        }
        cout << ans << endl;
    }
}