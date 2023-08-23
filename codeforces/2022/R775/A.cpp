#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            r = i;
            break;
        }
    }
    if (l == -1) {
        cout << "0\n";
    } else {
        cout << r - l + 2 << "\n";
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