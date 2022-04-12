#include <bits/stdc++.h>
using namespace std;
constexpr int N = 4e5 + 7;
int n, t;
array<char, N> s;
array<int, N> f;
struct BIT {
    array<int, N> t;
    auto lowbit(int x) { return x & -x; }
    void clear() {
        for (int i = 1; i <= 2 * n + 1; i++)
            t[i] = 0;
    }
    auto query(int x) {
        int res = 0;
        while (x <= 2 * n + 1) {
            res += t[x];
            x += lowbit(x);
        }
        return res;
    }
    auto update(int x, int l = 1) {
        while (x) {
            t[x] += l;
            x -= lowbit(x);
        }
    }
};
array<BIT, 3> tree;
auto main() -> int {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", s.data() + 1);
        for (int i = 0; i <= 2; i++)
            tree[i].clear();
        int sum = 0;
        tree[0].update(n + 1);
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '+')
                sum++;
            else
                sum--;
            ans += tree[(sum % 3 + 3) % 3].query(sum + n + 1);
            tree[(sum % 3 + 3) % 3].update(sum + n + 1);
        }
        printf("%lld\n", ans);
    }
}