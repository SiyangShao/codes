#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, res, cnt, num;
struct node {
    int a, b;
    bool operator<(const node &t) const { return b < t.b; }
} s[N];
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i].a >> s[i].b;
    sort(s + 1, s + 1 + n);
    int l = 1, r = n;
    while (l <= r) {
        if (s[l].b <= cnt) {
            cnt += s[l].a;
            res += s[l].a;
            l++;
        } else {
            num = min(s[r].a, s[l].b - cnt);
            cnt += num;
            res += 2 * num;
            s[r].a -= num;
            if (!s[r].a)
                r--;
        }
    }
    cout << res << endl;
}
