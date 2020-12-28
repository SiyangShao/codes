#include <bits/stdc++.h>
#define st first
#define nd second
#define mk make_pair
using namespace std;
const int N = 2e6 + 10, INF = 1e9;
inline int read() {
    int s = 0, cnt = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            cnt *= -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * cnt;
}
int n, m, Q, cnt;
int b[N], nex[N], dep[N], f[N][21];
unordered_map<int, int> id;
vector<pair<int, int>> p[N];
struct node {
    int x, y, z, w;
} que[N];
inline void update(vector<pair<int, int>> &v) {
    sort(v.begin(), v.end());
    vector<pair<int, int>> tem;
    int mxr = 0, lst = -1;
    for (pair<int, int> u : v) {
        int l = u.st, r = u.nd;
        if (lst == -1) {
            lst = l, mxr = r;
            continue;
        }
        if (l > mxr)
            tem.push_back(mk(lst, mxr)), lst = l;
        mxr = max(mxr, r);
    }
    if (lst != -1)
        tem.push_back(mk(lst, mxr));
    v = tem;
}
inline int getA(int x, int y) //找到 A 的位置
{
    int pos =
        upper_bound(p[x].begin(), p[x].end(), mk(y, INF)) - p[x].begin() - 1;
    if (pos == -1)
        return -1;
    if (y >= p[x][pos].st && y <= p[x][pos].nd)
        return id[p[x][pos].nd]; //返回右端点的值
    return -1;
}
inline int getB(int x, int y) //找到 B 的位置
{
    int pos =
        upper_bound(p[x].begin(), p[x].end(), mk(y, INF)) - p[x].begin() - 1;
    if (pos == -1)
        return -1;
    if (y >= p[x][pos].st && y <= p[x][pos].nd)
        return id[p[x][pos].st];
    return -1;
}
signed main() {
    n = read(), m = read(), Q = read();
    for (int i = 1; i <= m; i++) {
        int a = read(), l = read(), r = read();
        p[a].push_back(mk(l, r));
    }
    for (int i = 1; i <= Q; i++) {
        int x = read(), y = read(), z = read(), w = read();
        que[i] = (node){x, y, z, w};
        p[que[i].x].push_back(mk(y, y));
        p[que[i].z].push_back(mk(w, w));
    }
    for (int i = 1; i <= n; i++) {
        update(p[i]); //合并
        for (pair<int, int> u : p[i])
            b[++cnt] = u.st, b[++cnt] = u.nd;
    }
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1; //去重
    for (int i = 1; i <= cnt; i++)
        id[b[i]] = i;
    for (int i = 1; i <= n; i++) {
        for (pair<int, int> u : p[i]) {
            int l = lower_bound(b + 1, b + cnt + 1, u.st) - b;
            int r = lower_bound(b + 1, b + cnt + 1, u.nd) - b;
            nex[l] = max(nex[l], r);
        }
    }
    for (int i = 1; i <= cnt; i++) {
        nex[i] = max(nex[i - 1], nex[i]);
    }
    for (int i = cnt; i >= 1; i--) {
        if (nex[i] <= i)
            f[i][0] = cnt + 1; //没有后继
        else
            f[i][0] = nex[i];
        dep[i] = dep[f[i][0]] + 1;
    }
    f[cnt + 1][0] = cnt + 1;
    for (int j = 1; j <= 20; j++) //倍增
        for (int i = 1; i <= cnt + 1; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    for (int i = 1; i <= Q; i++) {
        int x = que[i].x, y = que[i].y, z = que[i].z, w = que[i].w,
            ans = abs(y - w);
        if (x == z && y == w) {
            printf("0\n");
            continue;
        }
        if (y > w)
            swap(x, z), swap(y, w);
        int A = getA(x, y), B = getB(z, w);
        if (A == -1 || B == -1) {
            printf("-1\n");
            continue;
        }
        if (A >= B) {
            printf("%d\n", ans + (x != z));
            continue;
        } //在同一段区间
        int tem = A;
        for (int i = 20; i >= 0; i--)
            if (f[tem][i] < B)
                tem = f[tem][i];
        tem = f[tem][0];
        if (tem == cnt + 1) {
            printf("-1\n");
            continue;
        }
        ans += dep[A] - dep[tem] + 1;
        printf("%d\n", ans);
    }
    return 0;
}
