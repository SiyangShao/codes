#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
string ans;
inline bool judge(int x) {
    for (int i = 0; i <ans.length(); i++) {
        if (s[i + x] > ans[i]) {
            return true;
        } else if (s[i + x] < ans[i]) {
            return false;
        }
    }
    return false;
}
int main() {
    cin >> n >> k >> s;
    if (s[0] < s[1]) {
        for (int i = 1; i <= k; i++) {
            cout << s[0];
        }
        return 0;
    }
    ans = s[0];
    s+=s;
    for (int i = 1; i < n; i++) {
        if (judge(i)) {
            ans += ans;
            break;
        } else {
            ans += s[i];
        }
    }
    while (ans.length() < k) {
        ans += ans;
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i];
    }
}