#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll A = 1e6 + 1;
array<ll, A> ps, pt;
array<ll, A> answer;
ll n, m, q;
string s, t;
bitset<A> sb, tb, currr;
void solve() {
  cin >> n >> m >> q;
  cin >> s >> t;
  sb.set();
  tb.reset();
  fill(answer.begin(), answer.end(), -1);
  for (ll i = 1; i <= n; ++i)
    ps[i] = ps[i - 1] + (s[i - 1] == 'w' ? 2 : 1);
  for (ll i = 1; i <= m; ++i)
    pt[i] = pt[i - 1] + (t[i - 1] == 'w' ? 2 : 1);

  ll scnt = 0;
  for (auto e : s) {
    if (e == 'v')
      sb[scnt] = 0, scnt++;
    else
      sb[scnt] = 1, scnt++, sb[scnt] = 0, scnt++;
  }
  ll tcnt = 0;
  for (auto e : t) {
    if (e == 'v')
      tb[tcnt] = 0, tcnt++;
    else
      tb[tcnt] = 1, tcnt++, tb[tcnt] = 0, tcnt++;
  }

  // auto it = lower_bound(pt.begin(), pt.begin() + m + 1, pt[0] + ps[n]);
  // ll preShuffle = 0;
  // for (ll i = 1; i <= m; ++i) {
  //   ll have = pt[i - 1] + ps[n];
  //   while (it < pt.begin() + m + 1 && (*it) < have) {
  //     it++;
  //   }
  //   if (it == pt.end() || *(it) != have) {
  //     answer[i] = false;
  //   } else {
  //     tb >>= (pt[i - 1] - preShuffle);
  //     preShuffle = pt[i - 1];
  //     if (((tb & sb) == tb)) {
  //       answer[i] = true;
  //     } else {
  //       answer[i] = false;
  //     }
  //   }
  // }

  for (ll i = 1; i <= q; ++i) {
    ll u, v;
    cin >> u >> v;
    // first check number of w
    if (pt[v] - pt[u - 1] == ps[n]) {
      if (answer[u] == -1) {
        currr = tb >> (pt[u - 1]);
        if ((currr & sb) == (currr)) {
          answer[u] = 1;
        } else {
          answer[u] = 0;
        }
      }
      if (answer[u]) {
        puts("Yes");
      } else {
        puts("No");
      }
    } else
      puts("No");
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--)
    solve();
}
