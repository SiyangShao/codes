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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int MAXK= 101;

void solve(){
    ll x[3],y[3];
    ii xy[3];
    rep(i,0,3) cin >> x[i] >> y[i];
    rep(i,0,3) xy[i]=ii(x[i],y[i]);
    sort(x,x+3);
    sort(y,y+3);
    vvl ans;
    
    vl temp;
    if(x[0]!=x[2]){
        temp.pb(x[0]);
        temp.pb(y[1]);
        temp.pb(x[2]);
        temp.pb(y[1]);
        ans.pb(temp);
    }
    temp.clear();
    rep(i,0,3)
        if(y[1]!=xy[i].se){
            temp.pb(xy[i].fi);
            temp.pb(xy[i].se);
            temp.pb(xy[i].fi);
            temp.pb(y[1]);
            ans.pb(temp);
            
     temp.clear();
        }

    cout << ans.size() << "\n";
    rep(i,0,ans.size()){
        rep(j,0,4) cout << ans[i][j] << " ";
        cout << "\n";
    }
        
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t=1;//cin >> t;
    rep(i,0,t){
        //cout << "Case #" << i+1  << ": " << solve() <<"\n";
       solve();
    }

    return 0;
}