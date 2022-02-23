#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, x;
signed main() {
    cin >> t;
    while (t--) {
        cin >> x;
        int tmp = x / 11;
        bool flag = true;
        for (int i = 0; i <= tmp; i++) {
            if ((x - i * 11) % 111 == 0) {
                flag = false;
                printf("YES\n");
                break;
            }
        }
        if (flag) {
            printf("NO\n");
        }
    }
}