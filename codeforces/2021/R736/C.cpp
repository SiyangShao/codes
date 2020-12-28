#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, q, t;
int cnt[200010], ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (u > v) {
            cnt[v]++;
            if (cnt[v] == 1)
                ans++;
        } else {
            cnt[u]++;
            if (cnt[u] == 1)
                ans++;
        }
    }
    cin>>q;
    while (q--) {
        cin >> t;
        if (t == 3) {
            cout << n - ans << "\n";
        } else if (t == 1) {
            cin >> u >> v;
            if (u > v) {
                cnt[v]++;
                if (cnt[v] == 1)
                    ans++;
            } else {
                cnt[u]++;
                if (cnt[u] == 1)
                    ans++;
            }
        } else {
            cin >> u >> v;
            if (u > v) {
                cnt[v]--;
                if (cnt[v] == 0)
                    ans--;
            } else {
                cnt[u]--;
                if (cnt[u] == 0)
                    ans--;
            }
        }
    }
}