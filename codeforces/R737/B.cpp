#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[100010];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            mp[a[i]] = i;
        }
        sort(a + 1, a + 1 + n);
        int tmp = 1;
        for (int i = 2; i <= n; ++i) {
            if (mp[a[i]] - mp[a[i - 1]] != 1) {
                tmp++;
            }
        }
        if (tmp > k) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
}