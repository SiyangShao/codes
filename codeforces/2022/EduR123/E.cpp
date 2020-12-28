#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n;
    string s;
    cin >> n >> s;
    ll ans = n * n;
    ll R = 0, D = 0;
    auto N = s.length();
    for (auto i : s) {
        if (i == 'R')
            R++;
        else
            D++;
    }
    if (!R || !D) {
        cout << n << "\n";
        return;
    }
    auto begin = 0ll;
    while (s[begin] == 'R') {
        ans -= (n - 1);
        begin++;
    }
    while (begin < N) {
        if (s[begin] == 'R')
            ans -= D;
        else
            D--;
        begin++;
    }
    begin = 0;
    while (begin < N && s[begin] == 'D') {
        ans -= (n - 1);
        begin++;
    }
    while (begin < N) {
        if (s[begin] == 'D')
            ans -= R;
        else
            R--;
        begin++;
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
    return 0;
}