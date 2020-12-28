#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
int arr[2000005];
void solve(){
    int n;
    cin >> n ;
    ll sum  =0 ;
    FOR(i,1,n){
        int a; cin >> a;
        sum += a;
        arr[sum]=sum;
    }
    int curmax = 0;
    for(int i =0;i<2000005 ; i++){
        if(arr[i] == i) curmax = i;
        arr[i] = curmax;
    }
    

  

    int q;
    cin >> q;
    unordered_map<ll, ll> f;
    while(q--){
        int t;
        cin >> t;
        if(f.find(t)!=f.end()){
            if(f[t]==-1) cout << "Impossible\n";
           else cout << f[t] << "\n"; 
           continue;
        }
    // 4 2 3 1 3 4
    // 4 4 4 4 4 6 6 9 9 9 10 13 13 13 17 17 17 -1 -1 -1 -1
         curmax = 0;
        int curpos = 0;
        int ans = 0;
        while(curpos<sum){
            curpos += t;
            if(arr[curpos]==curmax){
                ans = -1;
                f[t]=-1;
                break;
            }
            curpos = arr[curpos];
            curmax = curpos;
            ans++;
        }
        f[t]= ans; //
        if(f[t]==-1) cout << "Impossible" << "\n";
           else cout << f[t] << "\n"; 
           

    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
