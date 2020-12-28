#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    string s;
    cin >> s;
    char c;
    cin >> c;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == c && i % 2 == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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