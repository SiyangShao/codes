#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, d[100010];
signed main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &d[i]);
        }
        sort(d + 1, d + 1 + n);
        int ans = d[n], sum = 0;
        for (int i = 2; i <= n; i++) {
            ans += sum - (i - 1) * d[i];
            sum += d[i];
        }
        printf("%lld\n", ans);
    }
}