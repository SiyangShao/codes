#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
ll cnt[3][3];

int main() {
    ll n; cin >> n;
    vector<ll> a(n + 1); FOR(i, 1, n) cin >> a[i];
    
    ll currCnt[3] = {0, 0, 0};
    ll ans = 0; // n trivial answers

    cnt[0][0] = 1; // empty prefix

    FOR(i, 1, n) {
        currCnt[a[i] % 3]++;
        // first, get all subsegment ending at i
        // 1. number of nontrivial i with pfn1 === currN1 and 
        ll currAns = 0;
        currAns += cnt[currCnt[1] % 3][currCnt[2] % 3]; // the segment is nontrival and has n1 =0= 0 and n2 === 0
        currAns += cnt[(currCnt[1] + 2) % 3][currCnt[2] % 3];
        currAns += cnt[currCnt[1] % 3][(currCnt[2] + 2) % 3];
        // cout<<currAns<<"\n";
        ans += currAns;
        // 2. update answer
        cnt[currCnt[1] % 3][currCnt[2] % 3]++;
    }
    cout << ans << endl;
}