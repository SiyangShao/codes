#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    vector<pair<ll, ll>> point(3);
    for (auto &[x, y] : point) {
        cin >> x >> y;
    }
    sort(point.begin(), point.end(), [](auto x, auto y) {
        if (x.first == y.first)
            return x.second < y.second;
        return x.first < y.first;
    });
    ll ans = 0;
    if (point[0].second == point[1].second &&
        point[2].second < point[1].second) {
        ans += point[1].first - point[0].first;
    }
    if (point[1].second == point[2].second &&
        point[0].second < point[1].second) {
        ans += point[2].first - point[1].first;
    }
    if (point[0].second == point[2].second &&
        point[1].second < point[0].second) {
        ans += point[2].first - point[0].first;
    }
    cout << ans << "\n";
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