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
map<string,int> mpp;
void solve(){
    mpp["Mon"]=0;
    mpp["Tue"]=1;
    mpp["Wed"]=2;
    mpp["Thu"]=3;
    mpp["Fri"]=4;
    mpp["Sat"]=5;
    mpp["Sun"]=6;
   string s ; int n;
   cin >> s >> n;
   ll cur = mpp[s];
   ll ans = 10000;
   rep(i,0,n){
       ll day;
        cin >> day;
        ll ori = ((cur -day)%7 + 7 )%7;
        ll pass =0;
        while( (ori % 7 != 0 || (pass==0 && day==0)) && (pass <day || (pass==0 && day==0)) ){
            ori += 30;
            pass +=30;
            if(ori %7 ==6){
                ori +=1;
                pass +=1;
            }
            else if (ori %7 == 5){
                ori +=2;
                pass +=2;
            }
        }
        if(pass<day){
            ori += (91)*((day-pass)/91);
            pass += (91)*((day-pass)/91);
            while(pass<day){
                pass+=30;
                ori +=30;
            }
        }

        if(ori %7 ==6){
            ori += 1;
            pass +=1;
        }
        else if (ori %7 == 5){
            ori +=2;
            pass +=2;
        }
        //cout << ori << "\n";
        ans = min(ans,pass-day);


        
   }
   cout << ans << "\n";
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