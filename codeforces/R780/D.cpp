#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
constexpr int N = 2e5 + 10;
array<int, N> a;
int n;
auto get(int &x, int &y, int l, int r) -> int {
    if (l == r) {
        if (a[l] <= 1)
            return 0;
        else {
            x = l - 1, y = r + 1;
            return 1;
        }
    }
    int sum = 0, cnt = 0;
    for (int i = l; i <= r; i++) {
        if (abs(a[i]) == 2)
            sum++;
        if (a[i] < 0)
            cnt++;
    }
    if (!sum)
        return sum;
    if (cnt % 2 == 0) {
        x = l - 1, y = r + 1;
        return sum;
    }

    int i = l, j = r;

    int lsum = 0;
    int rsum = 0;
    while (i <= j && a[i] > 0)
        if (abs(a[i++]) == 2)
            lsum++;
    while (i <= j && a[j] > 0)
        if (abs(a[j--]) == 2)
            rsum++;

    if (a[i] == -2)
        lsum++;
    if (a[j] == -2)
        rsum++;

    if (lsum <= rsum) {
        sum -= lsum;
        l = i + 1;
    } else {
        sum -= rsum;
        r = j - 1;
    }

    x = l - 1, y = r + 1;
    return sum;
}

auto solve() -> PII {
    int last = 0;
    int l = 0, r = n;
    int val = 0;
    int x, y;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i])
            continue;
        if (i - last == 1) {
            last = i;
            continue;
        }
        int t = get(x, y, last + 1, i - 1);
        if (t > val)
            l = x, r = n - y + 1, val = t;
        last = i;
    }
    return {l, r};
}
auto main() -> int {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        a[n + 1] = 0;
        PII res = solve();
        cout << res.first << " " << res.second << "\n";
    }
    return 0;
}
