#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, a[200010], sum, average, num;
int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        average = sum / n;
        num = sum - average * n;
        printf("%lld\n", (n - num) * num);
    }
}