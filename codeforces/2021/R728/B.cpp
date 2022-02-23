#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int _, n, a[maxn];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        unordered_map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            mp[a[i]] = i;
        }
        int tmp, res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = a[i]; j <= 2 * n; j += a[i]) {
                tmp = mp[j / a[i]];
                if (tmp >= 1 && tmp != i && tmp + i == j) {
                    res++;
                }
            }
        }
        cout << res / 2 << "\n";
    }
}