#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array<ll, 26> in, out, self, uni, nxt;
array<string, 26> ans;
bool check(string &s) {
    vector<ll> a(26);
    a.assign(26, 0);
    for (auto i = s.begin(); i < s.end(); ++i) {
        a[*i - 'A']++;
        if (a[*i - 'A'] > 1 && *i != *(i - 1)) {
            return false;
        }
    }
    if (*s.begin() == *(s.end() - 1)) {
        self[*s.begin() - 'A'] += s.length();
        if (uni[*s.begin() - 'A'] != 0) {
            return false;
        }
    } else {
        out[*s.begin() - 'A']++;
        in[*(s.end() - 1) - 'A']++;
        ans[*s.begin() - 'A'] = s;
        if (nxt[*s.begin() - 'A'] != -1) {
            return false;
        }
        nxt[*s.begin() - 'A'] = *(s.end() - 1) - 'A';
        for (auto i : s) {
            if (i == *s.begin() || i == *(s.end() - 1))
                continue;
            if (uni[i - 'A'] != 0 || in[i - 'A'] != 0 || out[i - 'A'] != 0) {
                return false;
            }
        }
        for (auto i : s) {
            if (i == *s.begin() || i == *(s.end() - 1))
                continue;
            uni[i - 'A'] = 1;
        }
    }
    return true;
}
auto solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    in.fill(0), out.fill(0), self.fill(0), uni.fill(0), nxt.fill(-1);
    for (auto &i : s) {
        cin >> i;
    }
    for (auto i : s) {
        if (!check(i)) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    vector<int> cnt;
    for (int i = 0; i < 26; ++i) {
        if (in[i] == 0 && out[i] == 1) {
            cnt.emplace_back(i);
        }
    }
    auto dfs = [&](auto dd, int pos) -> void {
        if (pos == -1) {
            return;
        }
        for (int i = 0; i < self[pos]; ++i) {
            cout << char(pos + 'A');
        }
        self[pos] = 0;
        cout << ans[pos];
        if (nxt[pos] != -1) {
            for (int i = 0; i < self[nxt[pos]]; ++i) {
                cout << char(nxt[pos] + 'A');
            }
            self[nxt[pos]] = 0;
        }
        dd(dd, nxt[pos]);
    };
    if (cnt.empty()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto i : cnt) {
        // cout << i << " ";
        dfs(dfs, i);
    }
    for (int i = 0; i < 26; ++i) {
        if (in[i] == 0 && out[i] == 0) {
            for (int j = 0; j < self[i]; ++j) {
                cout << char(i + 'A');
            }
        }
    }
    cout << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1, cnt = 0;
    cin >> _;
    while (_--) {
        cout << "Case #" << ++cnt << ": ";
        solve();
    }
}