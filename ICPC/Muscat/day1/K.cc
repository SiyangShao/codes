#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll INF = 1e13 + 2;
const long double INFd = 1e18;
const ll mod = 1e9 + 7;
auto cal(int n, auto &&l, auto &&r) {
  vector<int> is_zombie(n + 1, 0);
  constexpr ll ll_inf = 1e18;
  const long double inf = INFd;
  constexpr long double multi = 1e8;
  using ld = long double;
  vector<ll> time(n + 1, ll_inf);
  vector<tuple<ll, int, int>> vec;
  vector<vector<ll>> L(n + 1, vector<ll>(n + 1, -1));
  vector<vector<pair<ll, int>>> critical(n + 1);
  for (int i = 0; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (l[i][j] >= inf) {
        L[i][j] = L[j][i] = ll_inf;
        continue;
      }
      ll x = std::roundl(l[i][j] * multi);
      L[i][j] = L[j][i] = x * 2;
      // critical[i].emplace_back(x * 2, j);
      // critical[j].emplace_back(x * 2, i);
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (r[i][j] >= inf) {
        continue;
      }
      ll x = std::roundl(r[i][j] * multi);
      critical[i].emplace_back(x * 2 + 1, j);
      critical[j].emplace_back(x * 2 + 1, i);
    }
  }
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> zombie;
  zombie.emplace(0, 0);
  time[0] = 0;
  while (!zombie.empty()) {
    auto [_, u] = zombie.top();
    zombie.pop();
    if (is_zombie[u])
      continue;
    is_zombie[u] = 1;
    if (critical[u].empty())
      continue;
    sort(critical[u].begin(), critical[u].end());
    for (auto [t, v] : critical[u]) {
      if (t < time[u])
        continue;
      ll real_t = max(L[u][v], time[u]);
      if (time[v] > real_t) {
        time[v] = real_t;
        zombie.emplace(time[v], v);
      }
    }
  }
  for (auto &i : time) {
    i /= 2;
  }
  vector<ld> real_time(n + 1);
  for (int i = 0; i <= n; ++i) {
    if (time[i] >= ll_inf / 10)
      real_time[i] = -1;
    else
      real_time[i] = (ld)time[i] / multi;
  }
  return real_time;
}
void solve() {
  ll i, j, n; // s, h, ans, subans;
  cin >> n;
  ll x[n + 1], y[n + 1], vx[n + 1], vy[n + 1];
  vector tl(n + 1, vector<long double>(n + 1));
  auto tr = tl;
  // long double tl[n + 1][n + 1], tr[n + 1][n + 1];
  long double sqdelta;
  ll a, b, c, d, delta;
  cin >> d;
  ll subx, subvx, suby, subvy;
  for (i = 0; i <= n; i++) {
    cin >> x[i] >> y[i] >> vx[i] >> vy[i];
  }
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      subvx = vx[i] - vx[j];
      subvy = vy[i] - vy[j];
      subx = x[i] - x[j];
      suby = y[i] - y[j];
      a = subvx * subvx + subvy * subvy;
      if (a == 0) {
        if (subx * subx + suby * suby > d * d) {
          tl[i][j] = INFd;
          tr[i][j] = INFd;
        } else {
          tl[i][j] = 0;
          tr[i][j] = 1e9;
        }
      } else {
        b = 2 * (subvx * subx + subvy * suby);
        c = subx * subx + suby * suby - d * d;
        delta = b * b - 4 * a * c;
        if (delta < 0) {
          tl[i][j] = INFd;
          tr[i][j] = INFd;
        } else {
          sqdelta = sqrt(delta);
          tl[i][j] = (-b * 1.0 - sqdelta) / (2.0 * a);
          tr[i][j] = (-b * 1.0 + sqdelta) / (2.0 * a);
          // tl[i][j] = -tl[i][j];
        }
      }
    }
  }
  // for(int i = 0 ; i<= n; ++i){
  //   for(int j = i+1; j<=n; ++j){
  //     cout << i << " to " << j << ": " << tl[i][j] << " " << tr[i][j] <<
  //     "\n";
  //   }
  // }
  for (i = 0; i <= n; ++i) {
    for (j = i + 1; j <= n; ++j) {
      if (tr[i][j] < 0) {
        tl[i][j] = tr[i][j] = tl[j][i] = tr[j][i] = INFd;
      } else {
        tl[i][j] = tl[j][i] = max((long double)0, tl[j][i]);
      }
    }
  }

  auto ans = cal(n, tl, tr);
  cout.setf(ios::fixed);
  cout.precision(8);
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << "\n";
    // cout << ans[i] << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll tc;
  tc = 1;
  // cin >> tc;
  while (tc--) {
    solve();
  }
}