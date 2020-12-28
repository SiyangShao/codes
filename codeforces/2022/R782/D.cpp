#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e5 + 5;
struct SegmentTree {
    array<ll, N> a;
    array<ll, N << 2> d, b;
    void build(ll l, ll r, ll p) { // l:区间左端点 r:区间右端点 p:节点标号
        if (l == r) {
            d[p] = a[l]; // 将节点赋值
            return;
        }
        ll m = l + ((r - l) >> 1);
        build(l, m, p << 1), build(m + 1, r, (p << 1) | 1); // 分别建立子树
        d[p] = d[p << 1] + d[(p << 1) | 1];
    }

    void update(ll l, ll r, ll c, ll s, ll t, ll p) {
        if (l <= s && t <= r) {
            d[p] += (t - s + 1) * c,
                b[p] += c; // 如果区间被包含了，直接得出答案
            return;
        }
        ll m = s + ((t - s) >> 1);
        if (b[p])
            d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
                b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
        b[p] = 0;
        if (l <= m)
            update(l, r, c, s, m,
                   p << 1); // 本行和下面的一行用来更新p*2和p*2+1的节点
        if (r > m)
            update(l, r, c, m + 1, t, (p << 1) | 1);
        d[p] = d[p << 1] + d[(p << 1) | 1]; // 计算该节点区间和
    }

    auto getsum(ll l, ll r, ll s, ll t, ll p) -> ll {
        if (l <= s && t <= r)
            return d[p];
        ll m = s + ((t - s) >> 1);
        if (b[p])
            d[p << 1] += b[p] * (m - s + 1), d[(p << 1) | 1] += b[p] * (t - m),
                b[p << 1] += b[p], b[(p << 1) | 1] += b[p];
        b[p] = 0;
        ll sum = 0;
        if (l <= m)
            sum = getsum(l, r, s, m,
                         p << 1); // 本行和下面的一行用来更新p*2和p*2+1的答案
        if (r > m)
            sum += getsum(l, r, m + 1, t, (p << 1) | 1);
        return sum;
    }
} st;
auto solve() {
    ll n;
    cin >> n;
    ll cnt = 0;
    st.a.fill(0);
    st.b.fill(0);
    st.d.fill(0);
    for (int i = 1; i <= n; ++i) {
        cin >> st.a[i];
        cnt += st.a[i];
    }
    assert(cnt % n == 0);
    cnt /= n;
    st.build(1, n, 1);
    vector<ll> ans(n + 1);
    for (int i = n; i >= 1; --i) {
        st.update(max(i - cnt + 1, 1LL), i, -1, 1, n, 1);
        auto tmp = st.getsum(i, i, 1, n, 1);
        if (tmp == 0) {
            ans[i] = 0;
        } else {
            ans[i] = 1;
            cnt--;
        }
    }
    if (cnt != 0)
        ans[1] = 1;
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
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