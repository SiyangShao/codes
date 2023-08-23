#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> ini;
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;
        v--;
        ini.emplace_back(v);
    }
    sort(ini.begin(), ini.end());
    ini.emplace_back(n + ini[0]);
    vector<ll> range(m);
    for (int i = 1; i <= m; ++i) {
        range[i - 1] = ini[i] - ini[i - 1] - 1;
    }
    ll t = 0, infected = m;
    sort(range.begin(), range.end(), greater<>());
    // for(auto i : range){
    //     cout<<i<<" ";
    // }
    for (auto i : range) {
        if (i > 2 * t) {
            if (i == 2 * t + 1) {
                infected += 2 * t;
                t++;
            } else {
                infected += 2 * t + 1;
                t += 2;
            }
        } else {
            infected += i;
        }
    }
    cout << infected << "\n";
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