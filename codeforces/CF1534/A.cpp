#include <bits/stdc++.h>
using namespace std;
int t, n, m;
string x[60], y[60], ans[60];
inline void init() {
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            if ((i + j) % 2 == 0) {
                x[i] += 'W';
            } else {
                x[i] += 'R';
            }
        }
    }
    for (int i = 0; i <= 50; i++) {
        for (int j = 0; j <= 50; j++) {
            if ((i + j) % 2 == 0) {
                y[i] += 'R';
            } else {
                y[i] += 'W';
            }
        }
    }
}
inline bool cmp(string a[], string b[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                continue;
            } else if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}
inline void output(string s[]) {
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << s[i][j];
        }
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    init();
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> ans[i];
        }
        if (cmp(ans, x)) {
            output(x);
        } else if (cmp(ans, y)) {
            output(y);
        } else {
            cout << "NO\n";
        }
    }
}