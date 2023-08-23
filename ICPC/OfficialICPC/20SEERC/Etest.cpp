#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
ll cnt[3][3];

int main() {
    ll n; cin >> n;
    vector<ll> a(n + 1); FOR(i, 1, n) cin >> a[i];
    ll cnt = 0; 
    FOR(i, 1, n) FOR(j, i, n) {
        ll sum = 0;
        FOR(u, i, j) FOR(v, u+1, j) if (u < v) sum = (sum + a[u] * a[v] % 3) % 3;
        if (sum % 3 == 0) cout << "i = " << a[i] << ", j = " << a[j] << endl, cnt++;
    }
    cout<<cnt;
}