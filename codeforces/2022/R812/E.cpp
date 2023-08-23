#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y)
            return x;
        if (-parent_or_size[x] < -parent_or_size[y])
            std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0)
            return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int> &v) { return v.empty(); }),
                     result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

} // namespace atcoder
auto solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> A(n, vector<ll>(n, 0));
    for (auto &i : A) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    atcoder::dsu dsu(n * 2);
    vector<ll> vis(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (A[i][j] > A[j][i]) {
                if (!dsu.same(i, j)) {
                    dsu.merge(i, j + n), dsu.merge(i + n, j);
                }
            } else if (A[i][j] < A[j][i]) {
                if (!dsu.same(i, j + n)) {
                    dsu.merge(i, j), dsu.merge(i + n, j + n);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i])
            continue;
        auto l = dsu.leader(i);
        vis[i] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (vis[j])
                continue;
            if (dsu.leader(j) == l) {
                vis[j] = 1;
            } else if (dsu.leader(j + n) == l) {
                vis[j] = 2;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((vis[i] + vis[j]) % 2 == 1)
                swap(A[i][j], A[j][i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " \n"[j + 1 == n];
        }
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}