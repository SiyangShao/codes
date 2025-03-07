#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

ll fibs[150];
int d[150];
int fcnt;
int it = 0;

pair<ll, pair<int, int>> cash[155][5];
int cnt[155];
pair<int, int> tofl(ll v, int num) {
  for (int i = 0; i < cnt[num]; i++)
    if (cash[num][i].first == v)
      return cash[num][i].second;
  cout << "CNT: " << cnt[num] << endl;
  if (num == 0)
    return mp(0, 0);
  if (num == 1)
    return mp(v == 1LL ? 0 : 1, v == 1LL ? 1 : 0);
  if (v > fibs[num - 1]) {
    pair<int, int> t = tofl(v - fibs[num - 1], num - 2);
    pair<int, int> ans = mp(t.first + 1, t.second);
    cash[num][cnt[num]++] = mp(v, ans);
    return ans;
  }
  pair<int, int> t = tofl(v, num - 1);
  pair<int, int> ans =
      mp(min(t.first, t.second + 2), min(t.first, t.second) + 1 + d[num - 2]);
  cash[num][cnt[num]++] = mp(v, ans);
  return ans;
}

int tofirst(ll v, int num) { return tofl(v, num).first; }

int tolast(ll v, int num) { return tofl(v, num).second; }

int between(ll a, ll b, int num) // O(log^2 max(a,b))
{
  if (a == b)
    return 0;
  if (fabs(a - b) == 1ll)
    return 1;
  if (a < b)
    swap(a, b);
  if (b > fibs[num - 1])
    return between(a - fibs[num - 1], b - fibs[num - 1], num - 2);
  pair<int, int> toa, tob;
  if (a <= fibs[num - 1]) {
    toa = tofl(a, num - 1);
    tob = tofl(b, num - 1);
    return min(min(toa.first, toa.second) + min(tob.first, tob.second) + 2,
               between(a, b, num - 1));
  }
  tob = tofl(b, num - 1);
  return min(tob.first, tob.second) + 1 + tofirst(a - fibs[num - 1], num - 2);
}

int go_between(ll a, ll b, int num) {
  for (int i = 0; i <= num; i++)
    cnt[i] = 0;
  return between(a, b, num);
}

int main() {
  fibs[0] = 1ll, fibs[1] = 2ll;
  d[0] = 0;
  d[1] = 1;
  for (int i = 2;; i++) {
    d[i] = d[i - 2] + 1;
    // cout<<d[i]<<" "<<(i+1)/2<<"\n";
    assert(d[i] == (i + 1) / 2);
    fibs[i] = fibs[i - 1] + fibs[i - 2];
    if (fibs[i] > 1e18) {
      fcnt = i;
      break;
    }
  }
  return 0;
  cout << fcnt << endl;
  int q, n;
  cin >> q >> n;
  for (int i = 0; i < q; i++) {
    //   cout << "query: " << i << endl;
    ll a, b;
    cin >> a >> b;
    it = 0;
    cout << go_between(a, b, min(n, 86)) << endl;
  }
  cerr << (double)clock() / (double)CLOCKS_PER_SEC << endl;
}
