#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, t;
vector<ll> a;
inline bool reassign(int x, ll d) {
    if (x == 0)
        return false;
    for (int i = 1; i <= n; ++i) {
        if (i == x)
            continue;
        if (i - 1 == x) {
            if (a[i] - a[i - 2] - 1 < d) {
                return false;
            }
            continue;
        }
        if (a[i] - a[i - 1] - 1 < d) {
            return false;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (i == x)
            continue;
        if (i == n) {
            if (t - a[i] - 1 >= d) {
                return true;
            }
        }
        if (i + 1 != x) {
            if (a[i + 1] - a[i] - 1 >= d + d + 1) {
                return true;
            }
        } else {
            if (i + 1 == n) {
                if (t - a[i] - 1 >= d + d + 1) {
                    return true;
                }
            } else {
                if (a[i + 2] - a[i] - 1 >= d + d + 1) {
                    return true;
                }
            }
        }
    }
    return false;
}
inline bool check(ll x) {
    int cnt = -1;
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (a[i] - a[i - 1] - 1 < x) {
            cnt = i;
            flag = false;
            break;
        }
    }
    if (flag) {
        return true;
    }
    return reassign(cnt - 1, x) || reassign(cnt, x);
}
void solve() {
    cin >> n >> t;
    a.assign(n + 2, 0);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll l = 0, r = t;
    ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        // cout << mid << " ";
        if (check(mid)) {
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }
    if (check(ans + 1)) {
        ans = ans + 1;
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