#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

void solve(){
    ll a,b,n; cin >> a >> b >> n;
    ll res = n - b;
    ll len = b - a;
    ll cnt = (res) / len + ((res) % len == 0 ? 0 : 1);
    cnt *= 2;
    cnt++;
        cout<<cnt<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
