#include <bits/stdc++.h>

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(2e5 + 5);
std::vector<int> primes, pp[N];
int lpf[N];

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!lpf[i]) {
            lpf[i] = i;
            primes.push_back(i);
            for (int j = i; j <= n; j += i) {
                pp[j].push_back(i);
            }
        }
        for (int j : primes) {
            if (1LL * i * j > n)
                break;
            lpf[i * j] = j;
            if (i % j == 0) {
                break;
            }
        }
    }
}

std::vector<int> a, b;
int n, m, aa[N], cnt[66][2];
bool vis[N];

bool dfs(int x, int c) {
    if (x == n + m + 1) {
        if (c == n) {
            a.assign(aa + 1, aa + c + 1);
        }
        return c == n;
    }

    std::vector<int> &p = pp[x];

    if (c < n) {
        bool ok = true;
        for (int i : p) {
            cnt[i][0]++;
            if (cnt[i][0] > 1 && cnt[i][1] > 1) {
                ok = false;
            }
        }
        if (ok) {
            aa[c + 1] = x;
            if (dfs(x + 1, c + 1))
                return true;
        }
        for (int i : p)
            cnt[i][0]--;
    }
    if (x - c <= m) {
        bool ok = true;
        for (int i : p) {
            cnt[i][1]++;
            if (cnt[i][0] > 1 && cnt[i][1] > 1) {
                ok = false;
            }
        }
        if (ok) {
            if (dfs(x + 1, c))
                return true;
        }
        for (int i : p)
            cnt[i][1]--;
    }
    return false;
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n + m; i++)
        vis[i] = false;

    bool swp = n > m;
    if (swp)
        std::swap(n, m);

    a = {1}, b.clear();
    vis[1] = true;
    for (int i : primes) {
        if (i > n + m || a.size() == n)
            break;
        a.push_back(i);
        vis[i] = true;
    }

    if (a.size() == n) {
        for (int i = 1; i <= n + m; i++) {
            if (!vis[i])
                b.push_back(i);
        }
    } else if (n + m <= 30) {
        for (int i = 1; i <= n + m; i++)
            cnt[i][0] = cnt[i][1] = 0;
        a.clear(), b.clear();
        if (dfs(1, 0)) {
            for (int i = 1; i <= n + m; i++)
                vis[i] = false;
            for (int i : a)
                vis[i] = true;
            for (int i = 1; i <= n + m; i++)
                if (!vis[i])
                    b.push_back(i);
        }
    } else {
        a.clear(), b.clear();
    }

    if (swp)
        std::swap(a, b);
    if (a.empty()) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        for (int i = 0; i < a.size(); i++)
            std::cout << a[i] << " \n"[i + 1 == a.size()];
        for (int i = 0; i < b.size(); i++)
            std::cout << b[i] << " \n"[i + 1 == b.size()];
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    sieve(2e5);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
