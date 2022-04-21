#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll, ll> mp;
    bool flag = false;
    mp.clear();
    for (auto &i : a) {
        cin >> i;
        mp[i]++;
        if (!flag && mp[i] == 3) {
            cout << i << "\n";
            flag = true;
        }
    }
    if (!flag) {
        cout << -1 << "\n";
    }
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