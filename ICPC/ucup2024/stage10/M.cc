#include <bits/stdc++.h>
using namespace std;

#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define in insert
#define all(x) x.begin(), x.end()
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

template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &c) {
  out << c.first << ' ' << c.second;
  return out;
}

template <typename T> ostream &operator<<(ostream &out, vector<T> &v) {
  const int sz = v.size();
  for (int i = 0; i < sz; i++) {
    if (i)
      out << ' ';
    out << v[i];
  }
  return out;
}

template <typename T> istream &operator>>(istream &in, vector<T> &v) {
  for (T &x : v)
    in >> x;
  return in;
}

template <typename T, typename U>
istream &operator>>(istream &in, pair<T, U> &c) {
  in >> c.first;
  in >> c.second;
  return in;
}

template <typename T> void mxx(T &a, T b) {
  if (b > a)
    a = b;
}
template <typename T> void mnn(T &a, T b) {
  if (b < a)
    a = b;
}

const int mxn = 5e5 + 10, MXLOG = 19;
// const int mod = 998244353;
// const int mod = 1e9 + 7;
// const int P = 1181, D = 1523, N = 2500;
const long long inf = 1e18 + 10;

void go() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> pos(k + 1);
  vector<vector<pair<int, int>>> g(m + 1);
  vector<vector<tuple<int, int, int>>> adj(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y, c, l;
    cin >> x >> y >> c >> l;
    adj[x].eb(y, c, l);
    adj[y].eb(x, c, l);
  }
  for (int i = 1; i <= k; i++) {
    int c, l;
    cin >> c >> l;
    g[c].eb(i, l);
    pos[i] = c;
  }
  vector<vector<vector<int>>> sp(m + 1);
  for (int i = 1; i <= m; i++) {
    int sz = (int)g[i].size();
    sp[i] = vector<vector<int>>(sz);
    for (int j = 0; j < sz; j++) {
      sp[i][j].pb(g[i][j].ss);
    }
    for (int p = 1; (1 << p) <= sz; p++) {
      for (int j = 0; j + (1 << p) <= sz; j++) {
        sp[i][j].pb(min(sp[i][j][p - 1], sp[i][j + (1 << (p - 1))][p - 1]));
      }
    }
  }
  vector<int> my(k + 1);
  for (int i = 2; i <= k; i++) {
    my[i] = my[i / 2] + 1;
  }
  auto get = [&](int i, int l, int r) -> int {
    int d = my[r - l + 1];
    return min(sp[i][l][d], sp[i][r - (1 << d) + 1][d]);
  };
  vector<int> mn(n + 1, inf), now(m + 1, 0);
  mn[1] = 0;

  priority_queue<pair<int, int>> q;
  q.emplace(0, 1);

  int tp = 1;

  while (q.size()) {
    int st, x;
    tie(st, x) = q.top();
    st = -st;
    q.pop();
    if (mn[x] != st)
      continue;
    while (tp <= st) {
      now[pos[tp]]++;
      tp++;
    }
    for (auto [y, c, L] : adj[x]) {
      if (mn[y] <= mn[x])
        continue;
      int l = now[c] - 1, r = (int)g[c].size();
      while (r - l > 1) {
        int mid = (l + r) / 2;
        if (get(c, now[c], mid) <= L)
          r = mid;
        else
          l = mid;
      }
      if (r != (int)g[c].size() && mn[y] > r) {
        mn[y] = r;
        q.emplace(-mn[y], y);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (mn[i] <= k)
      cout << 1;
    else
      cout << 0;
  }
  cout << endl;
}

signed main() {
  fast;
  int t = 1;
  cin >> t;
  while (t--) {
    go();
  }
  return 0;
}
