#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    string s;
    cin >> s;
    vector<int> mp(26, 0);
    for (auto &i : s) {
        mp[i - 'a']++;
    }
    int flag = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (mp[s[i] - 'a'] == 1) {
            flag = i;
            break;
        }
        mp[s[i] - 'a']--;
    }
    for (int i = flag; i < s.size(); ++i) {
        cout << s[i];
    }
    cout << "\n";
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