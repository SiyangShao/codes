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
int w,h;
ll convert(int x,int y){
    if(y==0) return x;
    if(x==w) return w+y;
    if(y==h) return w+h+(w-x);
    else return 2*w+h+(h-y);
}
void solve(){
    
    cin >> w >> h;
    stack<int> loop;
    int n;
    cin >> n;
    vector<ii> cir;
    rep(i,0,n){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if( (x1==0 || x1==w || y1==0 || y1 == h) && 
        (x2==0|| x2==w ||y2==0 || y2==h)){
            cir.pb(ii(convert(x1,y1),i));
            cir.pb(ii(convert(x2,y2),i));
        }
    }
    sort(ALL(cir));
    for(auto&[_,idx]:cir){
        if(loop.empty() || loop.top()!=idx) loop.push(idx);
        else loop.pop();
    }
    cout << ((loop.empty())?"Y\n":"N\n");

}


int main() {
    ios_base::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
    int t=1;
    //cin >> t;
    while(t--){
       solve();
    }
}