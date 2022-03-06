

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
vector< vector<int> > stores;
vvl graph;
vl color;
vl subans;

void dfs(int u){
    if(graph[u].size()==0){
        stores[u].pb(color[u]);
        return;
    }
    map<int,int> occ;
    vl poss;
    int maxv=0;
    for(auto v:graph[u]){
        dfs(v);
        for(auto&[c]:stores[v]){
            if(occ.find(c)!=occ.end()) occ[c]=0;
            occ[c]++;
            if(occ[c]>maxv){
                maxv=occ[c];
                poss.clear();
                poss.pb(c);
            }
            else if (occ[c]==maxv){
                poss.pb(c);
            }
        }
        ans[u]+=ans[v];

    }
    ans[u] += graph[u].size()-maxv;
    stores[u]=poss;
}



void solve(){
    int n;
    cin >> n;
    int p[n]
    graph.assign(n+1,vl());
    stores.assign(n+1, map<int,int>());
    color.assign(n+1,0);
    subans.assign(n+1,0);
    rep(i,2,n+1){
        int x; cin >> x;
        graph[i].pb(x);
    }
    rep(i,1,n+1) cin >> color[i];
    dfs(1);
    cout << ans[1] << "\n";
    
}

int main()
{ 
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 //freopen("UT.txt","w",stdout);
  int t=1;

  while(t--){
    solve();
  }
}
  

