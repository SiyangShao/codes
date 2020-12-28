#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<ll> A(n), B(n);
    unordered_map<ll, ll> vis;
    for (auto &i : A) {
        cin >> i;
        vis[i]++;
    }
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
        if (vis[B[i]]) {
            if (A[i] == B[i])
                cnt1++;
            else
                cnt2++;
        }
    }
    cout << cnt1 << "\n" << cnt2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}