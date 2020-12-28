#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    string s1, s2;
    cin >> s1 >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    ll A = 0, B = 0, lenA = 0, lenB = 0;
    while (A < a && B < b) {
        if (lenA == c) {
            lenA = 0;
            lenB = 1;
            cout << s2[B++];
        } else if (lenB == c) {
            lenB = 0;
            lenA = 1;
            cout << s1[A++];
        } else if (s1[A] < s2[B]) {
            lenB = 0;
            lenA++;
            cout << s1[A++];
        } else {
            lenA = 0;
            lenB++;
            cout << s2[B++];
        }
    }
    cout << "\n";
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