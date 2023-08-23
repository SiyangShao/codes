#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin >> s;
    ll cnt = 0;
    for (ll i = 0; i + 3 < s.length(); ++i) {
        if (s[i] == 'h' && s[i + 1] == 'z' && s[i + 2] == 'n' &&
            s[i + 3] == 'u') {
            cnt++;
        }
    }
    cout << cnt << "\n";
}