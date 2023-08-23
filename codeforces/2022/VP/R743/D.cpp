#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> ans;
auto output(auto a, auto b, auto c) {
    return min(a.second, min(b.second, c.second));
}
auto sol(auto &a) {
    if (a.empty())
        return;
    auto n = a.size();
    ll cur = 0;
    while (cur + 2 < n) {
        assert(a[cur].first == 0);
        if (a[cur + 1].first == 0 && a[cur + 2].first == 0) {
            cur += 2;
        } else if (a[cur + 1].first == 0 && a[cur + 2].first == 1) {
            cur++;
        } else if (a[cur + 1].first == 1 && a[cur + 2].first == 0) {
            if (a[cur + 3].first == 1) {
                ans.emplace_back(output(a[cur + 1], a[cur + 2], a[cur + 3]));
                a[cur + 1].first = 0, a[cur + 3].first = 0;
                cur = cur + 3;
            } else {
                ans.emplace_back(output(a[cur + 1], a[cur + 2], a[cur + 3]));
                a[cur + 1].first = 1, a[cur + 2].first = 1,
                        a[cur + 3].first = 1;
                ans.emplace_back(output(a[cur], a[cur + 1], a[cur + 2]));
                a[cur + 1].first = 0, a[cur + 2].first = 0;
                cur = cur + 3;
            }
        } else {
            ans.emplace_back(output(a[cur], a[cur + 1], a[cur + 2]));
            a[cur + 1].first = 0, a[cur + 2].first = 0;
            cur = cur + 2;
        }
    }
}
auto solve() {
    ll n;
    cin >> n;
    ans.clear();
    vector<pair<ll, ll>> a(n);
    ll cnt = 0, MIN = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        MIN = min(MIN, a[i].first);
        a[i].second = i + 1;
        cnt += a[i].first;
    }
    if (cnt % 2 == 1 || MIN == 1) {
        cout << "NO\n";
        return;
    }
    if (a[0].first == 0) {
        sol(a);
    } else {
        if (a.back().first == 0) {
            if (!a.empty())
                reverse(a.begin(), a.end());
            sol(a);
        } else {
            if (a[1].first == 1 && a[2].first == 0) {
                ans.emplace_back(output(a[0], a[1], a[2]));
                a[0].first = 0, a[1].first = 0;
                sol(a);
            } else if (a[1].first == 0 && a[2].first == 1) {
                ans.emplace_back(output(a[0], a[1], a[2]));
                a[0].first = 0, a[2].first = 0;
                sol(a);
            } else {
                if (a[1].first == 0 && a[2].first == 0) {
                    ans.emplace_back(output(a[0], a[1], a[2]));
                    a[1].first = 1, a[2].first = 1;
                }
                vector<pair<ll, ll>> lef;
                lef.clear();
                ll cnt = 0;
                ll flag = -1;
                for (int i = 0; i < n; ++i) {
                    cnt += a[i].first;
                    if (a[i].first == 0) {
                        if (cnt % 2 == 0) {
                            flag = i;
                            lef.emplace_back(a[i]);
                            break;
                        } else {
                            if (a[i - 1].first == 1 && a[i + 1].first == 1) {
                                flag = i;
                                ans.emplace_back(
                                    output(a[i - 1], a[i], a[i + 1]));
                                a[i - 1].first = 0, a[i + 1].first = 0,
                                      a[i].first = 0;
                                if (!lef.empty())
                                    lef.pop_back();
                                lef.emplace_back(a[i - 1]);
                                lef.emplace_back(a[i]);
                                break;
                            } else if (a[i - 1].first == 0 &&
                                       a[i + 1].first == 0) {
                                lef.emplace_back(a[i]);

                                continue;
                            } else {
                                ans.emplace_back(
                                    output(a[i - 1], a[i], a[i + 1]));
                                a[i - 1].first = 1;
                                a[i + 1].first = 1;
                                a[i].first = 1;
                                lef.emplace_back(a[i]);
                                cnt++;
                            }
                        }
                    } else
                        lef.emplace_back(a[i]);
                }
                if (flag == -1) {
                    cout << "NO\n";
                    return;
                }
                // cout << flag << "\n";
                for (int i = 0; i < min(flag, n); ++i) {
                    a[i].first = 0;
                }
                // for (auto i : lef) {
                //     cout << i.first << " ";
                // }
                // cout << "\n";
                // for (auto i : a) {
                //     cout << i.first << " ";
                // }
                // cout << "\n";
                if (!lef.empty())
                    reverse(lef.begin(), lef.end());
                sol(lef);
                sol(a);
            }
        }
    }
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    if (ans.size() != 0)
        cout << "\n";
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