#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, x;
int a[200010];
int ans = 1;
priority_queue<int, vector<int>, greater<int>> q;
signed main() {
    scanf("%lld%lld%lld", &n, &k, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; ++i) {
        if (a[i] - a[i - 1] > x) {
            ans++;
            q.push(a[i] - a[i - 1]);
        }
    }
    while (q.size()) {
        int t = q.top();
        q.pop();
        if (k - (ceil((double)t / x) - 1ll) >= 0)
            k -= ceil((double)t / x) - 1ll, ans--;
        else
            break;
    }
    printf("%lld\n",ans);
}