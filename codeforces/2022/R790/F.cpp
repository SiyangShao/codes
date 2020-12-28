#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
// 我走在每天必须面对的分岔路
// 我怀念过去单纯美好的小幸福
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    mp.clear();
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
    }
    vector<ll> res;
    for (auto &[i, j] : mp) {
        if (j >= k) {
            res.emplace_back(i);
        }
    }
    if (res.empty()) {
        cout << "-1\n";
        return;
    }
    sort(res.begin(), res.end());
    ll ans = 1, cnt = 1, l = *res.begin(), r = *res.begin(),
       nowl = *res.begin(), nowr = *res.begin();
    for (int i = 1; i < res.size(); ++i) {
        if (res[i] - res[i - 1] == 1) {
            cnt++;
            nowr = res[i];
            if (cnt > ans) {
                ans = cnt;
                l = nowl, r = nowr;
            }
        } else {
            nowl = res[i], nowr = res[i];
            cnt = 1;
        }
    }
    cout << l << " " << r << "\n";
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