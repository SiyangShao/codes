#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr int MAXN = 1e5 + 9;
constexpr ll INF = LLONG_MAX / 2;

int n, m, k;
ll x[MAXN];

struct laddar {
    int b, d;
    ll h, end;
} l[MAXN];

vector<laddar *> startf[MAXN], endf[MAXN];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        startf[i].clear();
        endf[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < k; ++i) {
        int ta, tc;
        cin >> ta >> l[i].b >> tc >> l[i].d >> l[i].h;
        l[i].end = INF;
        startf[ta].push_back(&l[i]);
        endf[tc].push_back(&l[i]);
    }
    laddar vstart;
    vstart.d = 1;
    vstart.end = 0;
    endf[1].push_back(&vstart);
    laddar vend;
    vend.b = m;
    vend.h = 0;
    vend.end = INF;
    startf[n].push_back(&vend);
    for (int i = 1; i <= n; ++i) {
        sort(startf[i].begin(), startf[i].end(), [](const laddar *p, const laddar *q) { return p->b < q->b; });
        sort(endf[i].begin(), endf[i].end(), [](const laddar *p, const laddar *q) { return p->d < q->d; });
    }
    using vlp = vector<laddar *>;
    for (int i = 1; i <= n; ++i) {
        {
            vlp::iterator it = endf[i].begin();
            ll best = INF;
            for (auto curit = startf[i].begin(); curit != startf[i].end(); ++curit) {
                while (it != endf[i].end() && (*it)->d <= (*curit)->b) {
                    best = min(best, (*it)->end - x[i] * (*it)->d);
                    ++it;
                }
                (*curit)->end = min((*curit)->end, best - (*curit)->h + x[i] * (*curit)->b);
            }
        }
        {
            vlp::reverse_iterator it = endf[i].rbegin();
            ll best = INF;
            for (auto curit = startf[i].rbegin(); curit != startf[i].rend(); ++curit) {
                while (it != endf[i].rend() && (*it)->d >= (*curit)->b) {
                    best = min(best, (*it)->end + x[i] * (*it)->d);
                    ++it;
                }
                (*curit)->end = min((*curit)->end, best - (*curit)->h - x[i] * (*curit)->b);
            }
        }
    }
    if (vend.end >= INF / 2) {
        cout << "NO ESCAPE\n";
    } else {
        cout << vend.end << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}