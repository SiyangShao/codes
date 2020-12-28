#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;

const int N = 500010, mod = 998244353, INF = 1e9;

int n, m, k;
LL a[N];
int f[N];
vector<LL> alls;
struct node {
    int l, r;
    int mx1, mx2, mx3;
} tr[4 * N];

void push_up(node &mid, node &l, node &r) {
    mid.mx1 = max(l.mx1, r.mx1);
    mid.mx2 = max(l.mx2, r.mx2);
    mid.mx3 = max(l.mx3, r.mx3);
}

void push_up(int u) { push_up(tr[u], tr[u << 1], tr[u << 1 | 1]); }

void build(int u, int l, int r) {
    tr[u] = {l, r, -INF, -INF, -INF};
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    else {
        int mid = (tr[u].l + tr[u].r) / 2;
        if (r <= mid)
            return query(u << 1, l, r);
        else if (l > mid)
            return query(u << 1 | 1, l, r);
        else {
            node left = query(u << 1, l, r);
            node right = query(u << 1 | 1, l, r);
            node res;
            push_up(res, left, right);
            return res;
        }
    }
}

void modify(int u, int x, int v, int d) {
    if (x == tr[u].l && x == tr[u].r) {
        tr[u].mx1 = max(v - d, tr[u].mx1);
        tr[u].mx2 = max(v, tr[u].mx2);
        tr[u].mx3 = max(v + d, tr[u].mx3);
    } else {
        int mid = (tr[u].l + tr[u].r) / 2;
        if (x <= mid)
            modify(u << 1, x, v, d);
        else
            modify(u << 1 | 1, x, v, d);
        push_up(u);
    }
}

int find(LL x) {
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin() + 1;
}

void solve() {
    alls.clear();
    a[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), a[i] += a[i - 1], alls.push_back(a[i]);
    alls.push_back(0);
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    m = alls.size();
    for (int i = 0; i <= n; i++)
        a[i] = find(a[i]);
    m = alls.size();
    build(1, 1, m);
    f[0] = 0;
    modify(1, a[0], 0, 0);
    for (int i = 1; i <= n; i++) {
        f[i] = -1e9;
        if (a[i] > 1) {
            node t = query(1, 1, a[i] - 1);
            f[i] = max(f[i], t.mx1 + i);
        }
        if (a[i] < m) {
            node t = query(1, a[i] + 1, m);
            f[i] = max(f[i], t.mx3 - i);
        }
        node t = query(1, a[i], a[i]);
        f[i] = max(f[i], t.mx2);
        modify(1, a[i], f[i], i);
    }
    // for(int i=1;i<=n;i++){
    //     f[i]=-1e9;
    //     for(int j=0;j<i;j++){
    //         if(s[i]>s[j]){
    //             f[i]=max(f[i],f[j]+i-j);
    //         }else if(s[i]==s[j]){
    //             f[i]=max(f[i],f[j]+0);
    //         }else if(s[i]==s[j]){
    //             f[i]=max(f[i],f[j]-(i-j));
    //         }
    //     }
    // }
    cout << f[n] << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}