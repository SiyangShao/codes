#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using namespace std;
using ll = long long;
constexpr ll N = 86400;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> p(n), fa(n), siz(n);
    siz.assign(n, 1);
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](auto self, auto x) -> ll {
        if (x != fa[x]) {
            fa[x] = self(self, fa[x]);
        }
        return fa[x];
    };
    auto merge = [&](auto x, auto y) {
        x = find(find, x);
        y = find(find, y);
        if (x == y)
            return;
        if (siz[x] > siz[y]) {
            swap(x, y);
        }
        fa[x] = y;
        siz[y] += siz[x];
    };
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        merge(i, p[i]);
    }
    vector<ll> ans;
    for (ll i = 0; i < n; ++i) {
        if (find(find, i) == i) {
           ans.emplace_back(siz[i]);
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size() >= 2){
        auto num = ans.back();
        ans.pop_back();
        num += ans.back();
        ans.pop_back();
        ans.emplace_back(num);
    }
    ll cnt = 0;
    for(auto i : ans){
        cnt += i * i;
    }
    cout<<cnt;
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}