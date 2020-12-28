#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef string str;
typedef vector<ll>  vl;
typedef vector<ll>  vll;
typedef vector<int>  vi;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<iii> viii;
typedef vector< vector<iii> > vviii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;
typedef long double ld;

//typelower_bounddef priority_queue<long long> pq;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,v) for(auto i:v)
#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define repn(i,a,b) for(int i=(a);i<=(b);i++)
#define repin(i,a,b,x) for(int i=(a);i<(b);i+=x)
#define repnin(i,a,b,x) for(int i=(a);i<=(b);i+=x)
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define fbo find_by_order
#define ook order_of_key
#define ALL(v) v.begin(),v.end()
#define FILL(arr,x) memset(arr,x,sizeof arr);
// if else int i = (number <0) ? 1:0 -  if (number <0) i=1 else 0
const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int MAXK= 101;

ll binpow(ll a, ll b) {
    ll res = 1;

    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        res%=MOD;
        a%=MOD;
        b >>= 1;
    }
    return res%MOD;
}

ll modInverse(ll a)
{
    return binpow(a, MOD - 2);
    
}

void solve(){
    int n;
    cin >> n;
    ll a[n];
    ll pos[n+2];
    ll dp[ (n+1)/2 ][n+1]; // position in final , number used in this position
    FILL(a,0);
    FILL(pos,0);
    FILL(dp,0);

    rep(i,0,n) {
        cin >> a[i];
        pos[a[i]]++;
    }
    ll prefix[n];
    FILL(prefix,0);
    rep(i,0,n/2){
        ll val = 0;
        rep(j,1,n+1){
            if(pos[j]==0 ) continue;
            dp[i][j] = (((i!=0)?prefix[j-1]:1) * ((val<=(2*i+((i==n/2-1)?0:1)))?0:( ((i==n/2-1)?(val-2*i):(val-(2*i)-1))*((i==0)?(val - (2*i)):1))))%MOD * pos[j];
            val += pos[j];
        }
        rep(j,1,n+1){
            prefix[j] = (prefix[j-1]+dp[i][j])%MOD;
            //cout << prefix[j] << " ";
        }
       // cout << "\n";
    }

    // rep(i,0,n/2){
    //     rep(j,1,n+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    ll ans = dp[n/2-1][a[n-1]];
    rep(i,1,n+1){
        if(pos[i]>1){
            ans *=modInverse(pos[i]);
            ans %=MOD;
        }
    }
    cout <<ans  << "\n";


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t=1;cin >> t;
    rep(i,0,t){
        //cout << "Case #" << i+1  << ": " << solve() <<"\n";
       solve();
    }

    return 0;
}