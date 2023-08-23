#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1 << 18;
int n;
struct st {
    set<int> s;
    void insert(int x) { s.insert(x); }
    void del(int l, int r) {
        for (auto cur = s.lower_bound(l); cur != s.end() && *cur < r;) {
            int curval = *cur;
            s.erase(cur);
            cur = s.upper_bound(curval);
        }
    }
    bool exist(int id) { return s.count(id); }
    pair<int, int> change(int id) {
        int l = 0, r = n;
        if (s.size()) {
            auto it = s.lower_bound(id);
            if (it != s.begin()) {
                l = *prev(it) + 1;
            }
            it++;
            if (it != s.end())
                r = *it;
        }
        return {l, r};
    }
} ods;
struct segtree {
    vector<int> data;

    segtree() { data.resize(N * 2, 0x3f3f3f3f); }

    void set(int id, int val) {
        data[id + N] = val;
        for (int i = (id + N) / 2; i > 0; i /= 2)
            data[i] = min(data[i * 2], data[i * 2 + 1]);
    }

    int get(int l, int r, int ld = 0, int rd = N, int id = 1) {
        if (l >= rd || r <= ld)
            return 0x3f3f3f3f;
        if (l <= ld && rd <= r)
            return data[id];
        return min(get(l, r, ld, (ld + rd) / 2, id * 2),
                   get(l, r, (ld + rd) / 2, rd, id * 2 + 1));
    }
} tree;
void solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        ods.insert(i);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            if (x == 0) {
                ods.del(l, r);
            } else {
                tree.set(l, min(tree.data[N + l], r));
            }
        } else {
            int pos;
            cin >> pos;
            pos--;
            if (!ods.exist(pos)) {
                cout << "NO\n";
                continue;
            }
            auto [l, r] = ods.change(pos);
            cout << ((tree.get(l, n) <= r) ? "YES\n" : "N/A\n");
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}