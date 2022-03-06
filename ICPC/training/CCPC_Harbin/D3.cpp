#include<bits/stdc++.h>

#define maxn 100005
#define inf 1e20
#define ll __int128
#define rep(i, a, b) for(int i=a;i<=b;i++)
using namespace std;

ll A[maxn], B[maxn], a, b, ca, cb, cnta[15], cntb[15], aa, bb, fz, fm, tmp[15], P[maxn], cp;

inline ll read() {
    ll x = 0, w = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c <= '9' && c >= '0') x = (x << 1) + (x << 3) + c - '0', c = getchar();
    return w == 1 ? x : -x;
}

inline void write(ll x) {
    if (x >= 10) write(x / 10);
    putchar(x % 10 + '0');
}

inline ll wk(int sta) {
    ll nw = 0, base = 1;
    rep(i, 1, ca) if (sta & (1 << (i - 1))) nw += A[i] * base, base *= 10;
    return nw;
}

inline bool jud(int sta) {
    rep(i, 0, 9) tmp[i] = cntb[i];
    rep(i, 1, ca) if (!(sta & (1 << (i - 1)))) tmp[A[i]]--;
    ll p = wk(sta), xx = p * bb / aa, xxx = xx;
    if (xx == 0 || (p * bb) % aa != 0) return false;
    while (xx) tmp[xx % 10]--, xx /= 10;
    rep(i, 1, 9) if (tmp[i]) return false;
    if (tmp[0] < 0) return false;
    cp = 0;
    while (xxx) P[++cp] = xxx % 10, xxx /= 10;
    rep(i, 1, tmp[0]) P[++cp] = 0;

    int nw = 1;
    rep(i, 1, cb) {
        if (B[i] == P[nw]) nw++;
        if (nw == cp + 1) return true;
    }
    return false;
}

void solve() {
    a = read();
    b = read();
    aa = a;
    bb = b;
    while (a) A[++ca] = a % 10, a /= 10;
    while (b) B[++cb] = b % 10, b /= 10;
    rep(i, 1, ca) cnta[A[i]]++;
    rep(i, 1, cb) cntb[B[i]]++;

    int ed = (1 << ca) - 1;
    fz = inf;
    rep(i, 1, ed) if (jud(i)) {
            if (fz > wk(i)) fz = wk(i), fm = fz * bb / aa;
        }
    write(fz);
    printf(" ");
    write(fm);
    printf("\n");
    ca = 0;
    cb = 0;
    rep(i, 0, 9) cnta[i] = 0, cntb[i] = 0;
}

int main() {
    int T;
    T = read();
    while (T--) {
        solve();
    }
    return 0;
}