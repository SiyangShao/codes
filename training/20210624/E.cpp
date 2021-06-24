#include <bits/stdc++.h>
#define pi 3.141592653589793
const double eps = 1e-8;
const double eps2 = 1e-14;
using namespace std;
int n, maxn;
int x[1010];
bool cal(double y) {
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += asin(double(x[i]) / y);
    }
    return ans - pi >= eps2;
}
bool judge(double y) {
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += asin(double(x[i]) / y);
    }
    if (ans + eps2 < pi) {
        return false;
    } else {
        return true;
    }
}
bool judge2(double y) {
    double ans = asin(double(maxn) / y);
    for (int i = 1; i <= n; ++i) {
        if (x[i] == maxn)
            continue;
        ans -= asin(double(x[i]) / y);
    }
    if (ans < eps2) {
        return false;
    } else {
        return true;
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x[i]);
        maxn = max(maxn, x[i]);
    }
    double l = maxn, r = 0x3f3f3f3f;
    if (cal(l)) {
        // r = n*maxn/2.0;
        while (l + eps < r) {
            double middle = (l + r) / 2.0;
            if (judge(middle)) {
                l = middle;
            } else {
                r = middle;
            }
        }
        printf("%.8lf\n", l / 2);
    } else {
        while (l + eps < r) {
            double middle = (l + r) / 2.0;
            if (judge2(middle)) {
                l = middle;
            } else {
                r = middle;
            }
        }
        printf("%.8lf\n", l / 2);
    }
}