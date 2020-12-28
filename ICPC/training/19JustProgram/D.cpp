#include <bits/stdc++.h>
#include <functional>
using namespace std;
using ll = long long;
auto solve() {
    string a, b, c;
    cin >> a >> b >> c;
    array<pair<ll, ll>, 3> sum;
    sum[0].first = accumulate(a.begin(), a.end(), 0) - '0' * 10;
    sum[1].first = accumulate(b.begin(), b.end(), 0) - '0' * 10;
    sum[2].first = accumulate(c.begin(), c.end(), 0) - '0' * 10;
    for (ll i = 0; i < 3; ++i) {
        sum[i].second = 10 - sum[i].first;
    }
    for (ll i = 0; i < 10; ++i) {
        sort(sum.begin(), sum.end(), greater<>());
        if (sum[0].first && sum[1].second && sum[2].second) {
            sum[0].first--;
            sum[1].second--;
            sum[2].second--;
            cout << "1";
        } else if (sum[0].first && sum[1].first && sum[2].first) {
            sum[0].first--;
            sum[1].first--;
            sum[2].first--;
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout<<"\n";
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