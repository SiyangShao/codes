#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    for (auto &x : a) {
        cin >> x;
        s.insert(x);
    }
    int ans = s.size();
    for (int i = 1; i <= n; ++i) {
        cout << max(ans, i) << " ";
    }
    cout << "\n";
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