#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; i--) {
        if (i == 1) {
            cout << "1 ";
        }
        for (int j = n; j >= 2; --j) {
            cout << j << " ";
            if (i == j) {
                cout << "1 ";
            }
        }
        cout << "\n";
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