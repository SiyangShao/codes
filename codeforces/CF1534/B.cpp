#include <bits/stdc++.h>
#define int long long
using namespace std;
int _, n;
int a[400010];
signed main() {
    scanf("%lld", &_);
    while (_--) {
        scanf("%lld", &n);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            ans += abs(a[i]-a[i-1]);
        }
        a[n + 1] = 0;
        ans += a[n];
        for (int i = 1; i <= n; i++) {
            if (a[i] >= a[i - 1] && a[i] >= a[i + 1]) {
                ans -= a[i] - max(a[i - 1], a[i+1]);
            }
        }
        printf("%lld\n",ans);
    }
}