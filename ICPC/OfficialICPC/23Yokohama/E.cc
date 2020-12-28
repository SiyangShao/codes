#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1 << 24;
constexpr int MOD = 998'244'353;
int f[N];
bitset<N> unvailable;
bitset<N> ailable;
deque<int> cant[25];
bitset<N> vis, inQueue;
vector<int> cantX(N + 1);

auto solve() {
    int n, m;
    cin >> n >> m;

    int all = (1 << n) - 1;


    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        cantX[all ^ (1 << a) ^ (1 << b) ^ (1 << c)] |= 1 << b;
    }
    for (int msk = all; msk >= 0; --msk) {
        for (int bit = 0; bit < n; ++bit) {
            if ((msk >> bit) & 1) {
                cantX[msk ^ (1 << bit)] |= cantX[msk];
            }
        }
    }

    ailable[0] = true;
    for (int i = 0; i < all; ++i) {
        if (! ailable[i]) {
            unvailable[i] = true;
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if ((cantX[i] >> j) & 1) {
                continue;
            }
            ailable[i ^ (1 << j)] = true;
        }
    }

//    for (int x = 0; x < n; ++x) {
//        vis.reset();
//        inQueue.reset();
//        for (auto u : cant[x])
//            inQueue[u] = true;
//        while (!cant[x].empty()) {
//            auto u = cant[x].front();
//            cant[x].pop_front();
//            if (vis[u])
//                continue;
//            vis[u] = true;
//            for (int i = 0; i < n; ++i) {
//                if (i == x || !check(u, i))
//                    continue;
//                if (!inQueue[u - (1 << i)]) {
//                    cant[x].emplace_back(u - (1 << i));
//                    inQueue[u - (1 << i)] = true;
//                }
//            }
//        }
//        unvailable |= vis;
//    }
    f[0] = 1;
    for (int i = 1; i < (1 << n); ++i) {
        if (unvailable[i] || unvailable[((1 << n) - 1) ^ i]) {
            f[i] = 0;
            continue;
        }
        for (int j = 0; j < n; ++j) {
            f[i] += f[i ^ (1 << j)];
            if (f[i] >= MOD) {
                f[i] -= MOD;
            }
        }
    }
    std::cout << f[(1 << n) - 1] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
