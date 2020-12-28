#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e5 + 7;
array<ll, N> is_prime;
vector<ll> prime;
array<vector<ll>, N> prime_partition;
array<ll, N> special_case;
auto init() {
    is_prime.fill(1);
    is_prime[1] = 0;
    for (ll i = 2; i < N; ++i) {
        if (is_prime[i]) {
            prime.emplace_back(i);
            for (ll j = i; j < N; j += i) {
                prime_partition[j].emplace_back(i);
            }
        }
        for (auto j : prime) {
            if (i * j >= N)
                break;
            is_prime[i * j] = 0;
            if (!(i % j)) {
                break;
            }
        }
    }
}
auto solve() {
    ll n, m;
    cin >> n >> m;
    ll SUM = n + m;
    vector<ll> vis(SUM + 1, 0);
    bool flg = n > m;
    if (flg) {
        swap(n, m);
    }
    vector a = {1LL};
    vector<ll> b = {};
    vis[1] = 1;
    // Obviously, it will ok when all the numbers in one side are prime numbers
    for (auto i : prime) {
        if (i > SUM || a.size() == n) {
            break;
        }
        a.emplace_back(i);
        vis[i] = 1;
    }
    if (a.size() == n) {
        for (ll i = 1; i <= SUM; ++i) {
            if (!vis[i]) {
                b.emplace_back(i);
            }
        }
    } else if (n + m <= 30) {
        // As been proved in editorial, only when n + m less then 30 has special
        // cases we can use bruteforce to search the answer
        vector cnt(2, vector<ll>(SUM + 1, 0));
        a.clear(), b.clear();
        for (ll i = 1; i <= SUM; ++i) {
            vis[i] = 0;
        }
        function<bool(ll, ll)> dfs = [&](ll x, ll c) {
            // c is the capacity of a (saved in special_case)
            if (x == SUM + 1) {
                return c == n;
            }
            auto &partition = prime_partition[x];
            if (c < n) {
                // have to add new number
                bool flag = true;
                for (auto i : partition) {
                    if (i > SUM)
                        break;
                    cnt[0][i]++;
                    if (cnt[0][i] > 1 && cnt[1][i] > 1) {
                        flag = false;
                    }
                }
                if (flag) {
                    special_case[c] = x;
                    if (dfs(x + 1, c + 1))
                        return true;
                }
                for (auto i : partition) {
                    if (i > SUM)
                        break;
                    cnt[0][i]--;
                }
            }
            if (x - c <= m) {
                bool flag = true;
                for (auto i : partition) {
                    if (i > SUM)
                        break;
                    cnt[1][i]++;
                    if (cnt[0][i] > 1 && cnt[1][i] > 1) {
                        flag = false;
                    }
                }
                if (flag) {
                    special_case[c] = x;
                    if (dfs(x + 1, c))
                        return true;
                }
                for (auto i : partition) {
                    if (i > SUM)
                        break;
                    cnt[1][i]--;
                }
            }
            return false;
        };
        if (dfs(1, 0)) {
            for (ll i = 0; i < n; ++i) {
                vis[special_case[i]] = 1;
            }
            for (ll i = 1; i <= SUM; ++i) {
                if (vis[i]) {
                    a.emplace_back(i);
                } else {
                    b.emplace_back(i);
                }
            }
        }
    } else {
        a.clear(), b.clear();
        // No answer
    }
    if (flg) {
        swap(a, b);
    }
    if (a.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto i : a) {
            cout << i << " \n"[i == a.back()];
        }
        for (auto i : b) {
            cout << i << " \n"[i == b.back()];
        }
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}