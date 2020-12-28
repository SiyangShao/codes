#include <bits/stdc++.h>
using namespace std;
inline void chg(vector<int> &ar, vector<pair<int, int>> &ans, vector<int> &lens,
                int &mdf, int l, int r) {
    for (int i = l; i <= r; ++i)
        ans.emplace_back(r + 1 + mdf + i - 2 * l, ar[i]);
    if (r - l + 1 > 0)
        lens.push_back((r - l + 1) * 2);
    mdf += (r - l + 1) * 2;
    reverse(ar.begin() + l, ar.begin() + r + 1);
}
inline void ltf(vector<int> &ar, vector<pair<int, int>> &ans, vector<int> &lens,
                int &mdf, int l, int r) {
    chg(ar, ans, lens, mdf, l, r - 1);
    chg(ar, ans, lens, mdf, l, r);
}
void solve() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (auto &it : ar)
        cin >> it;
    if (n % 2) {
        cout << "-1\n";
        return;
    }
    int xr = 0;
    unordered_map<int, int> cnt;
    for (auto &it : ar) {
        cnt[it]++;
    }
    for (auto &it : cnt)
        if (it.second % 2) {
            cout << "-1\n";
            return;
        }
    vector<pair<int, int>> ans;
    vector<int> lens;
    ans.reserve(n * n * 2);
    lens.reserve(n * 2);
    int mdf = 0;
    for (int i = 0; i < n; i += 2) {
        int fnd = (int)(find(ar.begin() + i + 1, ar.end(), ar[i]) - ar.begin());
        ltf(ar, ans, lens, mdf, i, fnd);
        lens.push_back(2);
        mdf += 2;
    }
    cout << (int)ans.size() << "\n";
    for (auto &it : ans)
        cout << it.first << " " << it.second << "\n";
    cout << (int)lens.size() << "\n";
    for (auto &it : lens)
        cout << it << " ";
    cout << "\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}
