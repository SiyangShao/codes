#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = (b); a <= (c); ++ a)
#define per(a, b, c) for(int a = (b); a >= (c); -- a)
using namespace std;
template <class T> void rd(T &x){
  x = 0; int f = 1; char ch = getchar();
  while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}

typedef long long ll;
const int maxn = 1e6 + 5;
int a[maxn], b[maxn];
int dp[maxn];
int sum, ans;
int n, q;
ll tot;

struct edge{ int v, nxt; }; vector <edge> e; int head[maxn];

void adde(int u, int v){
  e.push_back((edge){v, head[u]});
  head[u] = e.size() - 1;
}

void dfs(int u, int f){
  int mx = 0;
  for(int i = head[u]; ~i; i = e[i].nxt){
    int v = e[i].v; if(v == f) continue;
    dfs(v, u);
    mx = max(mx, a[v]);
  }
  if(mx <= a[u]) return ;
  if(sum < mx - a[u]){ ans = -1; return ; }
  a[u] += dp[mx - a[u]];
}

int main(){
  memset(head, -1, sizeof(head));
  rd(n), rd(q);
  q = 1000;
  rep(i, 1, n) rd(a[i]);
  rep(i, 1, n - 1){
    int u, v; rd(u), rd(v);
    adde(u, v), adde(v, u);
  }
  ll add = 0;
  rep(i, 1, q) b[i] = q, sum += b[i];
  dp[0] = 1;
  rep(i, 1, q) per(j, sum, b[i]) dp[j] |= dp[j - b[i]], add++;
  cout<<add<<"!\n";
  per(i, sum, 0) dp[i] = !dp[i] ? dp[i + 1] : i;
  dfs(1, 0);
  if(ans == -1) puts("-1");
  else{
    rep(i, 1, n) tot += a[i];
    printf("%lld\n", tot);
  }
  return 0;
}