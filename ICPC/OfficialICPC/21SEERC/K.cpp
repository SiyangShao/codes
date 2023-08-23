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
int n;


vector< vector<ll> > graph;
ll dp[200003];

ll dfs(int u,int anc){
    dp[u]=n+1;
    if(graph[u].size()==1) dp[u]=u;
    FOR(v,graph[u]){
        if(v==anc) continue;
        dp[u]=min(dp[u],dfs(v,u));
    }
    return dp[u];
}

vl ans;
void traversal(int u,int anc, bool can=true){

    vii tra;
    FOR(v,graph[u]){
        if(v==anc) continue;
        tra.emplace_back(dp[v],v);
    }
    sort(ALL(tra));
    
    rep(i,0,tra.size()){
        

        if(can && i==tra.size()-1) {
            if(u > tra[i].fi){
                can = false;
                traversal(tra[i].se,u, false);
                continue;
            }
            ans.pb(u);
            traversal(tra[i].se,u,true);
            break;
        }
        traversal(tra[i].se,u, false);
        
    }
    if(!can || tra.size()==0) ans.pb(u);
    
}
 

void solve(){

  cin >> n;
    ans.clear();
  int st=-1;
  graph.assign(n+1,vl());
  rep(i,0,n-1){
    int u,v;
    cin >> u>> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  
    rep(i,1,n+1){
        if(graph[i].size()==1){
            st=i;
            break;
        }
    }
//rep(i,1,n+1) cout << dp2[i] << " ";
  dfs(st,-1);
    traversal(st,-1);
 
    FOR(v,ans){
        cout << v << " ";
    }
    cout << "\n";


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