#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using namespace std;
using ll = long long;
ll n;
vector<ll> a;
auto solve() {
    cin >> n;
    a.resize(n);
    priority_queue<ll, vector<ll>, greater<>> Q;
    for (auto &i : a) {
        cin >> i;
        Q.emplace(i);
    }
    ll ans = 0;
    if (n % 2 == 0) {
        auto t = Q.top();
        Q.pop();
        auto u = Q.top();
        Q.pop();
        ans = t + u;
        Q.emplace(t + u);
        n--;
    }
    while (n != 1) {
        auto f = Q.top();
        Q.pop();
        auto s = Q.top();
        Q.pop();
        auto t = Q.top();
        Q.pop();
        ans += f + s + t;
        Q.emplace(f + s + t);
        n -= 2;
    }
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}