#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    ll T;
    ll n, a, b, base;
    bool flag;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &a, &b);
        base = 1;
        flag = false;
        for (ll i = 1; i <= 30 && base <= n; i++, base *= a) {
            if ((n - base) % b == 0) {
                flag = true;
                break;
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}