#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll,ll,ll> iii;
typedef string str;
typedef vector<ll>  vl;
typedef vector< vector<ll> > vvl;
typedef vector<ii> vii;
typedef vector< vector<ii> > vvii;
typedef vector<iii> viii;
typedef vector< vector<iii> > vviii;
typedef vector<str>  vs;
typedef vector< vector<str> > vvs;


#ifndef ONLINE_JUDGE
#define LOG(message) cerr << message << endl;
#else 
#define LOG(message)
#endif

#define LSOne(S) ( (S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define FOR(i,v) for(auto i:v)
#define rep(i,a,b) for(int i=(a);i<(b);i++)
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

const ll MOD = 998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll N = 2*1e5+1000;

typedef vector<ll> vll;
typedef vector<int> vi;

class FenwickTree {                              // index 0 is not used
private:
  vll ft;                                        // internal FT is an array
public:
  FenwickTree(int m) { ft.assign(m+1, 0); }      // create an empty FT

  void build(const vll &f) {
    int m = (int)f.size()-1;                     // note f[0] is always 0
    ft.assign(m+1, 0);
    for (int i = 1; i <= m; ++i) {               // O(m)
      ft[i] += f[i];                             // add this value
      if (i+LSOne(i) <= m)                       // i has parent
        ft[i+LSOne(i)] += ft[i];                 // add to that parent
    }
  }

  FenwickTree(const vll &f) { build(f); }        // create FT based on f

  FenwickTree(int m, const vi &s) {              // create FT based on s
    vll f(m+1, 0);
    for (int i = 0; i < (int)s.size(); ++i)      // do the conversion first
      ++f[s[i]];                                 // in O(n)
    build(f);                                    // in O(m)
  }

  ll rsq(int j) {                                // returns RSQ(1, j)
    ll sum = 0;
    for (; j; j -= LSOne(j))
      sum += ft[j];
    return sum;
  }

  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // inc/exclusion

  // updates value of the i-th element by v (v can be +ve/inc or -ve/dec)
  void update(int i, ll v) {
    for (; i < (int)ft.size(); i += LSOne(i))
      ft[i] += v;
  }

  int select(ll k) {                             // O(log m)
    int p = 1;
    while (p*2 < (int)ft.size()) p *= 2;
    int i = 0;
    while (p) {
      if (k > ft[i+p]) {
        k -= ft[i+p];
        i += p;
      }
      p /= 2;
    }
    return i+1;
  }
};


class RUPQ {                                     // RUPQ variant
private:
  FenwickTree ft;                                // internally use PURQ FT
public:
  RUPQ(int m) : ft(FenwickTree(m)) {}
  void range_update(int ui, int uj, ll v) {
    ft.update(ui, v);                            // [ui, ui+1, .., m] +v
    ft.update(uj+1, -v);                         // [uj+1, uj+2, .., m] -v
  }                                              // [ui, ui+1, .., uj] +v
  ll point_query(int i) { return ft.rsq(i); }    // rsq(i) is sufficient
};

class RURQ  {                                    // RURQ variant
private:                                         // needs two helper FTs
  RUPQ rupq;                                     // one RUPQ and
  FenwickTree purq;                              // one PURQ
public:
  RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} // initialization
  void range_update(int ui, int uj, ll v) {
    rupq.range_update(ui, uj, v);                // [ui, ui+1, .., uj] +v
    purq.update(ui, v*(ui-1));                   // -(ui-1)*v before ui
    purq.update(uj+1, -v*uj);                    // +(uj-ui+1)*v after uj
  }
  ll rsq(int j) {
    return rupq.point_query(j)*j -               // optimistic calculation
           purq.rsq(j);                          // cancelation factor
  }
  ll rsq(int i, int j) { return rsq(j) - rsq(i-1); } // standard
}; 

void solve(){
    ll n,q;
    cin >> n >> q;
    ll a[n];
    ll cnt[N];
    FILL(cnt,0);
    rep(i,0,n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int curmax =-1;
    RURQ ft(N);
    rep(i,1,N-1){
        
        int add = cnt[i]/2;
        cnt[i]%=2;
        cnt[i+1]+=add;

        ft.range_update(i,i,cnt[i]);
        
        if(cnt[i]) curmax =i;
        
    }
    
    //cout << curmax << "\n";

    while(q--){
        ll k,now;
        cin >> k >> now;
        k--;

        ll prev = a[k];
        a[k] = now;
        if(now>curmax) curmax =now;
        
        //delete
        ll r = curmax+2;
        ll l = prev;
        if(ft.rsq(prev,prev)==1){
            ft.range_update(prev,prev,-1);
        }
        else {
            while(l<r){
                ll mid = (r+l+1)/2;

                if(ft.rsq(l,mid)==0){
                    l= mid;
                }
                else{
                    r = mid-1;
                }

            }
            ft.range_update(l+1,l+1,-1);
            ft.range_update(prev,l,1);
            
        }
        
        // cout << "After remove\n";
        // rep(i,1,7) cout << ft.rsq(i,i) <<" ";
        // cout << "\n";
        //add
        r = curmax+2;
        l = now;
        if(ft.rsq(now,now)==0){
            ft.range_update(now,now,1);
        }
        else {
            while(l<r){
                ll mid = (r+l+1)/2;
                //cout << l << " " << mid << " " << ft.rsq(l,mid) << "\n";
                if(ft.rsq(l,mid)==(mid-l+1)){
                    l = mid;
                }
                else{
                    r = mid-1;
                }

            }
            ft.range_update(l+1,l+1,1);
            ft.range_update(now,l,-1);
        }


        // cout << "After add\n";
        // rep(i,1,7) cout << ft.rsq(i,i) <<" ";
        // cout << "\n";
        
            int target = ft.rsq(1,N-1);
            int l = 1, r = N;
            while(l<r){
                int mid = (l+r)/2;

                if(ft.rsq(1,mid)==target){
                    r = mid;
                }
                else{
                    l= mid+1;
                }
            }
            curmax = l;
        

        
        cout << curmax <<"\n";
    }

    

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
  return 0;
}


/*
Advise
1) Think from another perspective ... Insteaf of + , try - ??
2) long long
3)
*/

