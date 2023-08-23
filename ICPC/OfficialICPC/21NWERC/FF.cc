#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define LC k << 1
#define RC k << 1 | 1
#define IO                                                                     \
  cin.sync_with_stdio(false);                                                  \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repn(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = (n)-1; i >= a; i--)
#define pern(i, a, n) for (int i = n; i >= a; i--)

typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;
typedef pair<double, double> PDD;
typedef pair<ull, ull> PUU;
typedef pair<double, int> PDI;

const int N = 110000;
const int M = 1100000;
const int mod = 1e9 + 7;
const int inf = (int)1e9;
const LL INF = 1e18;
const double eps = 1e-16;

struct Point {
  LL x, y;
  Point(LL x = 0, LL y = 0) : x(x), y(y) {}
  void input() { cin >> x >> y; }
  bool operator<(const Point &R) const {
    if (x == R.x)
      return y < R.y;
    return x < R.x;
  }
  bool operator==(const Point &R) const { return x == R.x && y == R.y; }
  Point operator+(const Point &R) const { return Point(x + R.x, y + R.y); }
  Point operator-(const Point &R) const { return Point(x - R.x, y - R.y); }
  Point operator*(const LL &R) const { return Point(x * R, y * R); }
  LL operator^(const Point &R) const { return x * R.y - y * R.x; }
  LL operator%(const Point &R) const { return x * R.x + y * R.y; }
  double len() { return sqrt(*this % *this); }
  LL len2() { return *this % *this; }
} s, t, p[N];

int n;
vector<Point> a0, a1, a2;
LL ans;
int v[N];
inline int lowbit(int x) { return x & -x; }
int get(int x) {
  int res = 0;
  for (int i = x; i; i -= lowbit(i))
    res += v[i];
  return res;
}
void add(int x) {
  for (int i = x; i < N; i += lowbit(i))
    v[i]++;
}

bool cmp(pair<Point, int> a, pair<Point, int> b) { return (a.fi ^ b.fi) > 0; }
bool cmp2(pair<Point, int> a, pair<Point, int> b) { return (a.fi ^ b.fi) < 0; }
void work(vector<Point> &a, int tp) {
  if (a.size() == 0)
    return;
  int n = a.size();
  vector<PII> f(n);
  vector<pair<Point, int>> tmp;
  int cnt = 0, num = 0;
  for (auto p : a) {
    tmp.pb(mp(p - s, cnt));
    cnt++;
  }
  if (tp == 0)
    sort(all(tmp), cmp);
  else
    sort(all(tmp), cmp2);
  cnt = 1;
  f[tmp[0].se].fi = 1;
  rep(i, 1, n) {
    if (tmp[i].fi ^ tmp[i - 1].fi)
      cnt++;
    f[tmp[i].se].fi = cnt;
  }

  tmp.clear();
  cnt = 0;
  for (auto p : a) {
    tmp.pb(mp(p - t, cnt));
    cnt++;
  }
  if (tp == 0)
    sort(all(tmp), cmp2);
  else
    sort(all(tmp), cmp);
  cnt = 1;
  f[tmp[0].se].se = 1;
  rep(i, 1, n) {
    if (tmp[i].fi ^ tmp[i - 1].fi)
      cnt++;
    f[tmp[i].se].se = cnt;
  }
  sort(all(f));
  memset(v, 0, sizeof(v));
  for (auto p : f) {
    ans += get(p.se);
    add(p.se);
  }
}
int main() {
  IO;
  s.input(), t.input();
  cin >> n;
  Point seg = t - s;
  repn(i, 1, n) {
    p[i].input();
    Point vec = p[i] - s;
    LL res = vec ^ seg;
    if (res == 0)
      a0.pb(p[i]);
    else if (res < 0)
      a1.pb(p[i]);
    else
      a2.pb(p[i]);
  }
  sort(all(a0));
  if (s.x == t.x) {
    LL neg = 0, pos = 0;
    for (auto p : a0)
      if (p.y <= min(s.y, t.y))
        neg++;
      else
        pos++;
    ans += neg * (neg - 1) / 2;
    ans += pos * (pos - 1) / 2;
  } else {
    LL neg = 0, pos = 0;
    for (auto p : a0)
      if (p.x <= min(s.x, t.x))
        neg++;
      else
        pos++;
    ans += neg * (neg - 1) / 2;
    ans += pos * (pos - 1) / 2;
  }

  work(a1, 0);
  work(a2, 1);
  cout << ans << "\n";
  return 0;
}