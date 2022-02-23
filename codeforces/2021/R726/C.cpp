#include <bits/stdc++.h>
using namespace std;
int t, n, h[200010];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        sort(h + 1, h + 1 + n);

        int dif = 0x3f3f3f3f, cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (dif > h[i] - h[i - 1]) {
                dif = h[i] - h[i - 1];
                cnt = i;
            }
        }
        cout << h[cnt - 1];
        for (int i = cnt + 1; i <= n; i++) {
            cout << " " << h[i];
        }
        for (int i = 1; i < cnt - 1; i++) {
            cout << " " << h[i];
        }
        cout << " " << h[cnt];
        cout << "\n";
    }
}