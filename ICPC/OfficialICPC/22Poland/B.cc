#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;
int n, tot, T;
const int N = 500010;
struct node {
  ll x, y;
} a[N], p[N];
ll ans;
ll m(node a, node b, node c) {
  return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
double dis(node a, node b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmp(node p, node p2) {
  ll res = m(p, p2, a[1]);
  if (res > 0)
    return 1;
  if (res == 0 && dis(a[1], p) < dis(a[1], p2))
    return 1;
  return 0;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(p, 0, sizeof p);
    a[1].x = 1, a[1].y = 0;
    a[2].x = n, a[2].y = 0;
    n += 2;
    for (int i = 3; i <= n; ++i) {
      ll v;
      scanf("%lld", &v);
      a[i].x = i - 2;
      a[i].y = v;
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i > 1 && a[i].y < a[1].y || a[i].y == a[1].y && a[i].x < a[1].x)
        swap(a[i], a[1]);
    }
    tot = 1;
    sort(a + 2, a + n + 1, cmp);
    p[1] = a[1];
    for (int i = 2; i <= n; i++) {
      while (tot > 1 && m(p[tot], a[i], p[tot - 1]) <= 0)
        tot--;
      tot++;
      p[tot] = a[i];
    }
    p[tot + 1] = a[1];
    for (int i = 1; i <= tot; i++)
      ans += m(p[i + 1], p[1], p[i]);
    printf("%lld\n", ans);
  }
  return 0;
}