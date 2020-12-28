#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    string s;
    int r = 0, g = 0, b = 0;
    cin >> s;
    for (auto i : s) {
        if (i == 'r')
            r++;
        else if (i == 'g')
            g++;
        else if (i == 'b')
            b++;
        else if (i == 'R') {
            if (r)
                r--;
            else {
                cout << "NO\n";
                return;
            }
        } else if (i == 'G') {
            if (g)
                g--;
            else {
                cout << "NO\n";
                return;
            }
        } else if (i == 'B') {
            if (b)
                b--;
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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