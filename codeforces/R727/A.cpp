#include <bits/stdc++.h>
#define int long long
using namespace std;
int _, n, x, t;
signed main() {
    scanf("%lld", &_);
    while (_--) {
        scanf("%lld%lld%lld", &n, &x, &t);
        int ans = t / x;
        if (ans > n - 1)
            printf("%lld\n", n * (n - 1) / 2);
        else
            printf("%lld\n", ans * (ans - 1) / 2 + ans * (n - ans));
    }
}