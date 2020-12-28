#include <bits/stdc++.h>
using namespace std;
using ll = long long;
std::ostream &operator<<(std::ostream &dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}
auto solve() {
    ll n;
    cin >> n;
    vector<string> s(n);
    vector<__int128> num1(26), num2(26);
    num1.assign(26, 0), num2.assign(26, 0);
    unordered_map<string, __int128> mp;
    mp.clear();
    for (auto &i : s) {
        cin >> i;
        num1[i[0] - 'a']++;
        num2[i[1] - 'a']++;
        mp[i]++;
    }
    __int128 cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (num1[i] != 0)
            cnt += num1[i] * (num1[i] - 1) / 2;
        if (num2[i] != 0)
            cnt += num2[i] * (num2[i] - 1) / 2;
    }
    for (auto [k, v] : mp) {
        // cout << v << " ";
        if (v != 0)
            cnt -= v * (v - 1);
    }
    cout << cnt << "\n";
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