#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
constexpr ll N = 1e5 + 7;
ll n, len;
ll lef[N], rig[N], a[N];

inline ll read() {
    auto c = getchar();
    ll x = 0, tmp = 1;
    while (c < '0' || c > '9') {
        if (c == '-')
            tmp = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * tmp;
}

int main() {
    n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    lef[n] = rig[n] = n;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] == -1 || a[i + 1] == -1 || a[i] == a[i + 1]) {
            lef[i] = lef[i + 1];
            rig[i] = rig[i + 1];
        } else {
            if (a[i] < a[i + 1]) {
                lef[i] = lef[i + 1];
                rig[i] = i;
            } else {
                rig[i] = rig[i + 1];
                lef[i] = i;
            }
        }
    }
//    for (int i = 1; i <= n; ++i) {
//        cout << lef[i] << " " << rig[i] << "\n";
//    }
    len = 3;
    while (len <= n) {
        bool flag = true;
        for (ll i = 1; i < n; i += len) {
            auto u = min(i + len - 1, n);
            auto to = min(u - 1, lef[i]);
            if (to == i || rig[to] < u) {
                flag = false;
                break;
            }
        }
        if (flag) {
            puts("Y");
            return 0;
        }
        len++;
    }
    puts("N");
}