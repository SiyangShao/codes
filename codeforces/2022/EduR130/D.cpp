#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array<ll, 26> pos;
array<ll, 1010> mp;
vector<ll> have;
map<pair<ll, ll>, ll> asked;
ll n;
ll ask_number;
auto ask1(ll pos) {
    cout << "? 1 " << pos << endl;
    char x;
    assert(pos <= n && pos >= 1);
    cin >> x;
    ask_number++;
    return x - 'a';
}
auto ask2(ll l, ll r) {
    if (l == r) {
        return 1LL;
    }
    assert(l >= 1 && r <= n);
    if (asked.contains({l, r})) {
        return asked[{l, r}];
    }
    cout << "? 2 " << l << " " << r << endl;
    ll num;
    cin >> num;
    asked[{l, r}] = num;
    ask_number++;
    return num;
}
auto output() {
    cout << "! ";
    for (ll i = 1; i <= n; ++i) {
        cout << char(mp[i] + 'a');
    }
    cout << "\n";
}
auto Get(ll p) {
    vector<ll> HavePos = have;
    HavePos.emplace_back(p);
    for (ll i = 0; i + 1 < HavePos.size(); ++i) {
        HavePos[i] = pos[HavePos[i]];
    }
    assert(is_sorted(HavePos.begin(), HavePos.end()));
    ll L = 0, R = have.size(), ans = 0;
    while (L <= R) {
        ll mid = (L + R) / 2;
        ll num = ask2(HavePos[mid], p);
        assert(num - (have.size() - mid) <= 1);
        if (num > have.size() - mid) {
            R = mid - 1;
        } else {
            L = mid + 1;
            ans = max(ans, mid);
        }
    }
    return ans;
}
auto solve() {
    cin >> n;
    pos.fill(-1);
    mp.fill(-1);
    have.clear();
    for (ll i = 1; i <= n; ++i) {
        ll num = ask2(1, i);
        if (num != have.size()) {
            ll c = ask1(i);
            have.emplace_back(c);
            mp[i] = c;
            pos[c] = max(pos[c], i);
        } else {
            ll c = Get(i);
            mp[i] = have[c];
            pos[have[c]] = max(pos[have[c]], i);
            sort(have.begin(), have.end(),
                 [&](auto l, auto r) { return pos[l] < pos[r]; });
        }
    }
    assert(ask_number <= 6000);
    output();
    // cout << ask_number;
}
auto main() -> int {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}