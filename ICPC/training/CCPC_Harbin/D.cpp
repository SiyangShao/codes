#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
string a, b;
vector<ll> dig(20, 1);
ll GCD, A, B, N, N_B;
ll ANSWER = LLONG_MAX;
ll GetInt() {
    ll ans = 0, tmp = 1;
    for (ll i = 0; i < N; ++i) {
        if (dig[i] == 1) {
            ans += tmp * (a[i] - '0');
            tmp = tmp * 10;
        }
    }
    return ans;
}
bool check(ll A_ans) {
    if (A_ans % A != 0)
        return false;
    if (A_ans == 0)
        return false;
    ll B_ans = (A_ans / A) * B;
    ll cnt = 0;
    vector<ll> count(10);
    for (ll i = 0; i < N; ++i) {
        if (dig[i] == 0) {
            count[a[i] - '0']++;
        }
    }
    while (B_ans) {
        ll tmp = B_ans % 10;
        while (cnt < N_B && tmp != b[cnt] - '0') {
            count[b[cnt] - '0']--;
            cnt++;
        }
        // cnt == n_b || tmp == b[cnt]
        if (cnt == N_B)
            return false;
        else
            cnt++;
        B_ans = B_ans / 10;
    }
    for (ll i = cnt; i < N_B; ++i) {
        count[b[i] - '0']--;
    }
    for (auto i : count) {
        if (i != 0)
            return false;
    }
    return true;
}
void dfs(ll step) {
    if (step == N) {
        ll A_ans = GetInt();
        // cout << A_ans << "\n";
        if (check(A_ans)) {
            ANSWER = min(ANSWER, A_ans);
        }
    } else {
        dig[step] = 0;
        dfs(step + 1);
        dig[step] = 1;
        dfs(step + 1);
    }
}
void solve() {
    cin >> a >> b;
    // cout << "\n\n";
    A = stoll(a), B = stoll(b);
    N_B = b.length();
    dig.resize(20, 1);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    N = a.length();
    GCD = gcd(A, B);
    ANSWER = A;
    A /= GCD;
    B /= GCD;
    dfs(0);
    cout << ANSWER << " " << (ANSWER / A) * B << "\n";
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