#include<bits/stdc++.h> 
using namespace std; 
 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
#define in insert 
#define all(x) x.begin(),x.end() 
#define pb push_back 
#define eb emplace_back 
#define ff first 
#define ss second 
 
#define int long long 
 
// typedef long long ll; 
typedef vector<int> vi; 
typedef set<int> si; 
typedef multiset<int> msi; 
typedef pair<int, int> pii; 
typedef vector<pii> vpii; 
// typedef pair<int, int> P; 
 
template<typename T, typename U> 
ostream & operator << (ostream &out, const pair<T, U> &c) { 
 out << c.first << ' ' << c.second; 
 return out; 
} 
 
template<typename T> 
ostream & operator << (ostream &out, vector<T> &v) { 
 const int sz = v.size(); 
 for (int i = 0; i < sz; i++) { 
  if (i) out << ' '; 
  out << v[i]; 
 } 
 return out; 
} 
 
template<typename T> 
istream & operator >> (istream &in, vector<T> &v) { 
 for (T &x : v) in >> x; 
 return in; 
} 
 
template<typename T, typename U> 
 istream & operator >> (istream &in, pair<T, U> &c) { 
 in >> c.first; 
 in >> c.second; 
 return in; 
} 
 
template<typename T> 
void mxx(T &a, T b){if(b > a) a = b;} 
template<typename T> 
void mnn(T &a, T b){if(b < a) a = b;} 
 
const int mxn = 3e5 + 10, MXLOG = 19; 
// const int mod = 998244353; 
const int mod = 1e9 + 7; 
// const int P = 1181, D = 1523, N = 2500; 
const long long inf = 1e18 + 10; 
 
vector<vector<int>> solve(vector<int> &a) { 
 int n = a.size(); 
 vector<int> pre(n + 1); 
 for(int i = 1; i <= n; i++) { 
  pre[i] = pre[i - 1] + a[i - 1]; 
 } 
 vector<vector<int>> dp(n + 1, vector<int>(n * 2 + 1)); 
 vector<deque<int>> my(n * 3 + 1); 
 for(int i = 1; i <= n; i++) { 
  for(int j = i - 1; j >= 1; j--) { 
   int val = i - j * 2 + n; 
   if(my[val].size() && my[val].front() == i) my[val].pop_front(); 
  } 
  for(int j = 1; j <= n * 2; j++) { 
   int val = j - i + n; 
   dp[i][j] = pre[min(n, i + j)] - pre[i - 1]; 
   if(my[val].size()) { 
    int r = my[val].front(); 
    int l = (r - val + n) / 2; 
    mxx(dp[i][j], pre[min(n, r)] - pre[l - 1]); 
   } 
  } 
  for(int j = 1; j <= n * 2; j++) { 
   int val = j - i + n; 
   while(my[val].size()) { 
    int r = my[val].back(); 
    int l = (r - val + n) / 2; 
    if(pre[min(n, r)] - pre[l - 1] <= pre[min(n, i + j)] - pre[i - 1]) my[val].pop_back(); 
    else break; 
   } 
   my[val].push_back(i + j); 
  } 
 } 
 for(int i = 1; i <= n; i++) { 
  for(int j = 1; j <= n * 2; j++) { 
   mxx(dp[i][j], dp[i][j - 1]); 
  } 
 } 
 return dp; 
} 
 
void go() { 
 int n; 
 cin >> n; 
 vector<int> a(n), b(n); 
 cin >> a; 
 b = a; 
 reverse(all(b)); 
 auto dpa = solve(a), dpb = solve(b); 
 
 for(int i = 1; i <= n; i++) { 
  for(int j = 1; j <= n * 2; j++) { 
   mxx(dpa[i][j], dpb[n - i + 1][j]); 
  } 
 } 
 
 int ans = 0; 
 for(int i = 1; i <= n; i++) { 
  int sum = 0; 
  for(int j = 1; j <= n * 2; j++) { 
   sum ^= j * dpa[i][j]; 
  } 
  ans ^= sum + i; 
 } 
 cout << ans << endl; 
} 
 
signed main() { 
 fast; 
 int t = 1; 
 // cin >> t; 
 while(t--) { 
  go(); 
 } 
 return 0; 
}
