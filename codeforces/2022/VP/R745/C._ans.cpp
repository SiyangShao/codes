#include <bits/stdc++.h>

char BUF_R[1 << 22], *csy1, *csy2;
#define GC                                                                     \
    (csy1 == csy2 && (csy2 = (csy1 = BUF_R) + fread(BUF_R, 1, 1 << 22, stdin), \
                      csy1 == csy2)                                            \
         ? EOF                                                                 \
         : *csy1++)

template <typename Ty> inline void RI(Ty &t) {
    char c = GC;
    for (t = 0; c < 48 || c > 57; c = GC)
        ;
    for (; c > 47 && c < 58; c = GC)
        t = t * 10 + (c ^ 48);
}

const int MAX_N = 200000 + 5;
const int MAX_M = 256;
int n, m, thre, x[MAX_N], y[MAX_N], cnt[MAX_M][MAX_M], s[MAX_N], a[MAX_N], ans;

void block_modify(int Tm, int k, int v) {
    int bl = x[k] + y[k], *c = cnt[bl];
    int l = (Tm + x[k]) % bl, r = (Tm - 1) % bl;
    if (l <= r)
        for (int i = l; i <= r; i++)
            c[i] += v;
    else {
        for (int i = 0; i <= r; i++)
            c[i] += v;
        for (int i = l; i < bl; i++)
            c[i] += v;
    }
}

int block_query(int Tm) {
    int res = 0;
    for (int i = 2; i <= thre; i++)
        res += cnt[i][Tm % i];
    return res;
}

int main() {
    RI(n);
    RI(m);
    thre = std::min((int)(0.5 * sqrt(m)) + 1, 255);
    for (int i = 1; i <= n; i++) {
        RI(x[i]);
        RI(y[i]);
    }
    for (int i = 1; i <= m; i++) {
        int opt, k;
        RI(opt);
        RI(k);
        if (opt == 1) {
            if (thre < x[k] + y[k]) {
                for (int j = i + x[k]; j <= m; j += x[k] + y[k]) {
                    a[j]++;
                    if (j + y[k] <= m)
                        a[j + y[k]]--;
                }
            } else
                block_modify(i, k, 1);
            s[k] = i;
        } else {
            if (thre < x[k] + y[k]) {
                for (int j = s[k] + x[k]; j <= m; j += x[k] + y[k]) {
                    a[j]--;
                    if (j + y[k] <= m)
                        a[j + y[k]]++;
                    if (j < i && j + y[k] >= i)
                        ans--;
                }
            } else
                block_modify(s[k], k, -1);
        }
        ans += a[i];
        printf("%d\n", ans + block_query(i));
    }
    return 0;
}