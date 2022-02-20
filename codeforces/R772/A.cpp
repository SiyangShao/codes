#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> cnt(31);

void judge(ll x) {
    int tmp = 0;
    while (x) {
        if (x % 2 == 1) {
            cnt[tmp]++;
        }
        tmp++;
        x >>= 1;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i: cnt) {
        i = 0;
    }
    for (auto &i: a) {
        cin >> i;
        judge(i);
    }
    ll res = 1, tmp = 0;
    for (auto i: cnt) {
        if (i > 0) {
            tmp += res;
        }
        res <<= 1;
    }
    cout << tmp << "\n";

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