#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, d;
vector<ll> a;
ll cnt(ll min_pos) {
    if (min_pos <= 0) {
        return 0;
    }
    vector<ll> schedule;
    for (int i = 0; i <= n; ++i) {
        if (i != min_pos) {
            schedule.emplace_back(a[i]);
        }
    }
    ll mx = 0, mn = INT_MAX;
    for (int i = 1; i < n; ++i) {
        mx = max(mx, schedule[i] - schedule[i - 1] - 1);
        mn = min(mn, schedule[i] - schedule[i - 1] - 1);
    }
    return min(mn, max(d - schedule.back() - 1, (mx - 1) / 2));
}

void solve() {
    cin >> n >> d;
    a.assign(n + 1, 0);
    ll mn = d, min_pos = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] - a[i - 1] - 1 < mn) {
            mn = a[i] - a[i - 1] - 1;
            min_pos = i;
        }
    }
    cout << max(cnt(min_pos), cnt(min_pos - 1)) << "\n";
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