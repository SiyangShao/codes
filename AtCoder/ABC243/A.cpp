#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll V, A, B, C;
    cin >> V >> A >> B >> C;
    V = V % (A + B + C);
    if (V < A) {
        cout << "F";
    } else if (V < A + B) {
        cout << "M";
    } else {
        cout << "T";
    }
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