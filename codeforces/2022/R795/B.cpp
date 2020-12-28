#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    map<ll, vector<ll>> mp;
    mp.clear();
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].emplace_back(i);
    }
    vector<ll> p(n);
    for (auto &[siz, vec] : mp) {
        if (vec.size() == 1) {
            cout << "-1\n";
            return;
        }
        ll N = vec.size();
        for (ll i = 0; i < N; ++i) {
            p[vec[i]] = vec[(i + 1) % N];
        }
    }
    for (auto i : p) {
        cout << i + 1 << " ";
    }
    cout << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}