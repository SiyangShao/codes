#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MAXN = 1e6 + 10;
constexpr ll base = 231;
constexpr ll mod = 1e9 + 7;
array<ll, MAXN> bs;
void init() {
    bs[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        bs[i] = bs[i - 1] * base;
        bs[i] %= mod;
    }
}
struct HASH {
    array<ll, MAXN> h;
    string s;
    void HashString() {
        h[0] = 0;
        for (int i = 1; i <= s.size(); ++i) {
            h[i] = h[i - 1] + (s[i - 1] - 'a') * bs[i];
            h[i] %= mod;
        }
    }
    ll GetHash(int l, int r) {
        return (h[r] - (h[l - 1] * bs[r - l + 1]) % mod) % mod;
    }
} ini, rev;
ll find_PAA(HASH &str, HASH &revstr) {
    ll len = str.s.size();
    ll p_len = 1;
    cout << str.s << " " << revstr.s << "\n";
    cout << "??\n";
    while (p_len <= len) {
        cout << p_len << " " << len - p_len + 1 << " " << len << "::: ";
        cout << str.GetHash(1, p_len) << " "
             << revstr.GetHash(len - p_len + 1, len) << "\n";
        if (str.GetHash(1, p_len) == revstr.GetHash(len - p_len + 1, len)) {
            if ((len - p_len) % 2 == 0) {
                auto a_len = (len - p_len) / 2;
                if (revstr.GetHash(1, a_len) ==
                    revstr.GetHash(a_len + 1, a_len + a_len)) {
                    return a_len;
                }
            }
        }
        p_len++;
    }
    return -1;
}
ll find_APA(HASH &str, HASH &revstr) {
    ll len = str.s.size();
    ll a_len = 1;
    while (a_len * 2 <= len) {
        if (str.GetHash(1, a_len) == str.GetHash(len - a_len + 1, len)) {
            auto p_len = len - a_len * 2;
            if (str.GetHash(a_len + 1, a_len + p_len) ==
                revstr.GetHash(a_len + 1, a_len + p_len)) {
                return a_len;
            }
        }
        a_len++;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    init();
    string s;
    cin >> s;
    auto l = s.begin();
    auto r = s.rbegin();
    while (l < s.end() && r < s.rend()) {
        if (*l == *r) {
            l++, r++;
        } else {
            break;
        }
    }
    if (l == s.end()) {
        // itself is
        cout << "1 1\n";
        return 0;
    }
    auto pos = l - s.begin();
    auto len = s.length() - pos * 2;
    auto modi = s.substr(pos, len);
    ini.s = modi;
    rev.s = modi;
    reverse(rev.s.begin(), rev.s.end());
    ini.HashString();
    rev.HashString();
    auto PAA = find_PAA(ini, rev);
    if (PAA != -1) {
        cout << pos + 1 << " " << (s.length() - pos - PAA) << "\n";
        return 0;
    }
    // auto AAP = find_PAA(rev, ini);
    // if (AAP != -1) {
    //     cout << pos + AAP + 1 << " " << (s.length() - pos) << "\n";
    //     return 0;
    // }
    // auto APA = find_APA(ini, rev);
    // if (APA != -1) {
    //     cout << pos + 1 << " " << pos + APA << "\n";
    //     return 0;
    // }
    cout << "-1 -1\n";
}