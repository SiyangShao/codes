#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110], b[110];
priority_queue<int, vector<int>, greater<int>> q1, q2;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            q1.push(a[i]);
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        if (b[i] != 0) {
            q2.push(b[i]);
        }
    }
    if (q1.size() == 0) {
        q1.push(0);
    }
    if (q2.size() == 0) {
        q2.push(0);
    }
    int x = 1, y = 1;
    for (int i = 1; i <= n + m; i++) {
        if (i == q1.top()) {
            q1.pop();
            x++;
            if (q1.size() == 0)
                q1.push(0);
            continue;
        }
        if (i == q2.top()) {
            q2.pop();
            y++;
            if (q2.size() == 0) {
                q2.push(0);
            }
            continue;
        }
        if (q1.top() > q2.top()) {
            if (b[y] == 0) {
                b[y] = i;
                y++;
                if (y > m) {
                    q2.pop();
                    q2.push(0x3f3f3f3f);
                }
            } else {
                a[x] = i;
                x++;
                if (x > n) {
                    q1.pop();
                    q1.push(0x3f3f3f3f);
                }
            }
        } else {
            if (a[x] == 0) {
                a[x] = i;
                x++;
                if (x > n) {
                    q1.pop();
                    q1.push(0x3f3f3f3f);
                }
            } else {
                b[y] = i;
                y++;
                if (y > m) {
                    q2.pop();
                    q2.push(0x3f3f3f3f);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= m; i++) {
        cout << b[i] << " ";
    }
}