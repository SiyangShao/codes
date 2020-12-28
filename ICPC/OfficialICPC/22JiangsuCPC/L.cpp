#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    ll ans = 0;
    // Observation: delete AC won't change it's whether odd or even, but delete
    // B would. After delete B, we can't do any more operation on the rest
    // ("AC")
    // ABC is 012
    vector<ll> res;
    for (auto &i : s) {
        res.emplace_back(i - 'A');
    }
    ll change = 0;
    ll n = res.size();
    auto check = [&](auto mid) {
        ll L = mid - 1, R = mid + 1;
        ll cnt = 0;
        while (L >= 0 && R < n) {
            if (res[L] == 0 && res[R] == 2) {
                L--, R++;
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    };
    for (ll i = 1; i + 1 < n; ++i) {
        if (res[i] == 1 && res[i - 1] == 0 && res[i + 1] == 2) {
            auto tmp = check(i);
            // cout<<i<<" "<<tmp<<"\n";
            if (change == 0) {
                if (i % 2 == 1) {
                    if (tmp == 1) {
                        // only can delete 1 AC
                        ans++;
                    } else {
                        // delete AC, then delte B
                        ans += 2;
                        change++;
                    }
                } else {
                    // delete B
                    ans++;
                    change++;
                }
            } else {
                change++;
                ans += min(tmp, (i % 2 == 1) + change);
            }
        }
    }
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    while (_--) {
        solve();
    }
}