#include <bits/stdc++.h>
#define pi 3.141592653589793
const double eps = 0.0000000001;
const double eps2 = 0.0000000000001;
using namespace std;
int n, maxn;
int x[1010];
bool cal(double y) {
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += asin(double(x[i]) / y);
    }
    return ans - pi >= 0;
}
bool judge(double y) {
    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += asin(double(x[i]) / y);
    }
    if (ans + eps < pi) {
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
    double l = maxn, r = double(6000000);
    if (cal(l)) {
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
