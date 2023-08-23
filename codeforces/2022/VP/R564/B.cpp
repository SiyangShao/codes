#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array<ll, 2> dx = {0, 1}, dy = {1, 0};
auto solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> ans(n);
    ans[0] = {1, 1};
    ll m = 1;
    for (ll i = 1; i < n; ++i) {
        ans[i].first = ans[i - 1].first + dx[i % 2];
        ans[i].second = ans[i - 1].second + dy[i % 2];
        m = max(m, max(ans[i].first, ans[i].second));
    }
    cout<<m<<"\n";
    for(auto [l,r] :ans){
        cout<<l<<" "<<r<<"\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}