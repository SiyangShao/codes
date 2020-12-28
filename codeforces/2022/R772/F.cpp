#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 3e5 + 7;
constexpr ll M = LLONG_MAX;
// Notice to use LLONG_MAX
vector<ll> a(N, 0), w(N, 0);
struct FenwickTree {
    vector<ll> tree;
    FenwickTree(ll n) : tree(n + 1, M) {}
    void update(ll idx, ll val) {
        for (; idx < tree.size(); idx += idx & -idx)
            tree[idx] = min(val, tree[idx]);
    }
    // Update: IDX and all points after it
    ll query(ll idx) {
        ll ret = M;
        for (; idx > 0; idx -= idx & -idx)
            ret = min(ret, tree[idx]);
        return ret;
    }
    // Query: IDX and all points before it
} fen(N);
vector<pair<ll, ll>> Q[N];
vector<ll> P[N];
vector<ll> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> w[i];
    }
    for (int i = 0, l, r; i < q; ++i) {
        cin >> l >> r;
        Q[l].push_back({r, i});
    }
    w[0] = INT_MAX;
    stack<ll> st;
    // cout << "\n";
    for (ll i = 1; i <= n; ++i) {
        while (!st.empty() && w[st.top()] > w[i]) {
            st.pop();
        }
        if (st.empty()) {
            st.emplace(i);
            continue;
        }
        auto lef = st.top();
        P[lef].emplace_back(i);
        st.emplace(i);
        // cout << "l " << lef << " " << i << "\n";
    }
    while (!st.empty()) {
        st.pop();
    }
    for (ll i = n; i >= 1; --i) {
        while (!st.empty() && w[st.top()] > w[i]) {
            st.pop();
        }
        if (st.empty()) {
            st.emplace(i);
            continue;
        }
        auto rig = st.top();
        P[i].emplace_back(rig);
        st.emplace(i);
        // cout << "R " << i << " " << rig << "\n";
    }
    ans.resize(q);
    for (int i = n; i >= 1; --i) {
        for (auto r : P[i]) {
            auto val = abs(a[r] - a[i]) * (w[r] + w[i]);
            // cout << val << " " << i << " " << r << "\n";
            fen.update(r, val);
        }
        for (auto &[r, idx] : Q[i]) {
            ans[idx] = fen.query(r);
        }
        // Trick: Use FenwickTree don't update points before i, so as to ensure that
        // query(r) is the smallest point from i to r
    }
    for (auto i : ans) {
        cout << i << "\n";
    }
}