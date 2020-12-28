#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == '0')
                continue;
            if (a[i] == '0') {
                ans++;
            } else {
                if (i > 0 && a[i - 1] == '1')
                    ans++ , a[i-1] = '2';
                else if (i < n - 1 && a[i + 1] == '1')
                    ans++ , a[i+1] = '2';
            }
        }
        cout << ans << "\n";
    }
}