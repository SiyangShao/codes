#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto sol(string &s, int n, int k) {
    string ans = s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            ans[i] = '0';
        }
    }
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (ans[i] != ans[i - 1]) {
            cnt++;
        }
    }
    if ((cnt - k) % 2 != 0) {
        ans[0] = '2';
        return ans;
    }
    if (cnt > k) {
        for (int r = n - 1; r > 0; --r) {
            if (s[r] == '1' && s[r - 1] == '?') {
                int l = r - 1;
                while (s[l] == '?') {
                    l--;
                }
                if (s[l] == '1') {
                    for (int i = l + 1; i < r; ++i) {
                        ans[i] = '1';
                    }
                    cnt -= 2;
                    if (cnt == k) {
                        return ans;
                    }
                }
            }
        }
        if (cnt > k) {
            ans[0] = '2';
            return ans;
        }
    }
    // cout<<ans<<" "<<cnt<<endl;
    for (int i = n - 2; i >= 1; --i) {
        if (s[i] == '?') {
            // Can Do Modification
            assert(ans[i] == '0');
            int change =
                    (ans[i] == ans[i - 1] ? 1 : -1) + (ans[i] == ans[i + 1] ? 1 : -1);
            assert(change == 0 || change == -2 || change == 2);
            if (change == 0)
                continue;
//            std::cout << "change " << i << std::endl;
            if ((cnt > k && change == -2) || (cnt < k && change == 2)) {
                ans[i] = '1';
                cnt += change;
            }
        }
    }
    // 0?0????1
    // cout<<ans<<" "<<cnt<<endl;
    if (cnt != k) {
        ans[0] = '2';
    }
    return ans;
}
auto solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1) {
        if (k == 0) {
            cout << (s[0] == '?' ? '0' : s[0]) << '\n';
        } else {
            cout << "Impossible\n";
        }
        return;
    }
    if (s[0] == '?' && s[n - 1] == '?') {
        vector<string> ans(4);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                string t = s;
                t[0] = char(i + '0');
                t[n - 1] = char(j + '0');
                ans[i * 2 + j] = sol(t, n, k);
            }
        }
        auto x = *min_element(ans.begin(), ans.end());
        if (x[0] == '2') {
            cout << "Impossible\n";
        } else {
            cout << x << '\n';
        }
    } else if (s[0] == '?') {
        vector<string> ans(2);
        for (int i = 0; i < 2; ++i) {
            string t = s;
            t[0] = char(i + '0');
            ans[i] = sol(t, n, k);
        }
        auto x = *min_element(ans.begin(), ans.end());
        if (x[0] == '2') {
            cout << "Impossible\n";
        } else {
            cout << x << '\n';
        }
    } else if (s[n - 1] == '?') {
        vector<string> ans(2);
        for (int i = 0; i < 2; ++i) {
            string t = s;
            t[n - 1] = char(i + '0');
            ans[i] = sol(t, n, k);
        }
        auto x = *min_element(ans.begin(), ans.end());
        if (x[0] == '2') {
            cout << "Impossible\n";
        } else {
            cout << x << '\n';
        }
    } else {
        string ans = sol(s, n, k);
        if (ans[0] == '2') {
            cout << "Impossible\n";
        } else {
            cout << ans << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}