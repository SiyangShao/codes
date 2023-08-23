// #include <bits/stdc++.h>
// // #define ONLINE_JUDGE
// #ifndef ONLINE_JUDGE
// #include "dbg.h"
// #else
// #define dbg(...) (__VA_ARGS__)
// #endif
// using namespace std;
// constexpr int inf = 1e9;
// constexpr int N = 26;
// array<array<array<array<int, 2>, 260>, 50>, 50> vis;
// struct Trie {
//   vector<array<int, N>> nxt;
//   array<int, N> base;
//   int cnt{0};
//   vector<int> exi;
//   Trie() {
//     fill(base.begin(), base.end(), -1);
//     nxt.emplace_back(base);
//     exi.emplace_back(-1);
//   };
//   void insert(string_view s) {
//     int p = 0;
//     for (auto i : s) {
//       int c = i - 'A';
//       if (nxt[p][c] == -1) {
//         nxt[p][c] = ++cnt;
//         nxt.emplace_back(base);
//         exi.emplace_back(-1);
//       }
//       p = nxt[p][c];
//     }
//     exi[p] = (int)s.length();
//   }
// };

// auto solve() {
//   int n, m, kkk;
//   cin >> n >> m >> kkk;
//   vector mp(n, vector<int>(m));
//   for (auto &i : mp) {
//     for (auto &j : i) {
//       string s;
//       cin >> s;
//       j = s[0] - 'A';
//     }
//   }
//   vector<string> pattern(kkk);
//   Trie trie;
//   for (auto &i : pattern) {
//     cin >> i;
//     trie.insert(i);
//   }
//   using node = tuple<int, int, int, int, int>;
//   priority_queue<node, vector<node>, greater<>> Q;
//   for (int i = 0; i < 1; ++i) {
//     for (int j = 0; j < m; ++j) {
//       Q.emplace(0, -i, j, 0, 0);
//     }
//   }
//   function<void(int, int, int, int, int)> line = [&](int dis, int i, int j,
//                                                      int p, int op) {
//     j += op;
//     dis++;
//     while (j >= 0 && j < m) {
//       if (p == -1) {
//         return;
//       }
//       if (trie.exi[p] != -1) {
//         line(dis, i, j, 0, op);
//       }
//       Q.emplace(dis, -i, j, p, 1);
//       p = trie.nxt[p][mp[i][j]];
//       j += op;
//       dis++;
//     }
//   };
//   while (!Q.empty()) {
//     auto [dis, i, j, p, k] = Q.top();
//     i = -i;
//     Q.pop();
//     if (vis[i][j][p][k])
//       continue;
//     vis[i][j][p][k] = 1;
//     p = trie.nxt[p][mp[i][j]];
//     if (p == -1) {
//       continue;
//     }
//     dbg(i + 1, j + 1, p, k);
//     if (k == 0) {
//       if (trie.exi[p] != -1) {
//         line(dis, i, j, 0, -1);
//         line(dis, i, j, 0, 1);
//       } else {
//         line(dis, i, j, p, -1);
//         line(dis, i, j, p, 1);
//       }
//     }
//     if (i + 1 < n) {
//       if (trie.exi[p] != -1) {
//         Q.emplace(dis + 1, -(i + 1), j, 0, 0);
//       } else {
//         Q.emplace(dis + 1, -(i + 1), j, p, 0);
//       }
//     } else {
//       if (trie.exi[p] != -1) {
//         cout << dis + 1 << "\n";
//         return;
//       }
//     }
//   }
//   cout << "impossible\n";
//   return;
//   // vector ans(n, vector<vector<int>>(m, vector<int>(trie.cnt + 1, -1)));
// }
// auto main() -> signed {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr), cout.tie(nullptr);
//   int _ = 1;
//   // cin >> _;
//   while (_--) {
//     solve();
//   }
// }
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

constexpr int inf = 1e9;
constexpr int N = 26;
array<array<array<array<int, 2>, 260>, 50>, 50> vis;
struct Trie {
  vector<array<int, N>> nxt;
  array<int, N> base;
  int cnt{0};
  vector<int> exi;
  vector<char> curr;
  Trie() {
    fill(base.begin(), base.end(), -1);
    nxt.emplace_back(base);
    exi.emplace_back(-1);
    curr.emplace_back('x');
  };
  ll insert(string_view s) {
    int p = 0;
    for (auto i : s) {
      int c = i - 'A';
      if (nxt[p][c] == -1) {
        nxt[p][c] = ++cnt;
        nxt.emplace_back(base);
        exi.emplace_back(-1);
        curr.emplace_back(i);
      }
      p = nxt[p][c];
    }
    exi[p] = (int)s.length();
    return p;
  }
};

ll dp[52][52][2704][2];
void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  FOR(i, 1, n) FOR(j, 1, m) {
    string s;
    cin >> s;
    a[i][j] = s[0];
  }
  Trie t;
  map<char, vector<ll>> terms;
  FOR(i, 1, k) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    ll id = t.insert(s);
    terms[s.back()].emplace_back(id);
  }

  ll tSize = t.nxt.size();
  FOR(i, 0, n)
  FOR(j, 0, m) FOR(tt, 0, tSize + 2) FOR(dir, 0, 1) dp[i][j][tt][dir] = 1e16;

  // init dp by last line
  // FOR(i, 1, m) for (auto te: terms[a[n][i]]) dp[n][i][te] = 1;

  auto advance = [&](ll x, char nxt) { // advance from trie position x to char
                                       // nxt. At most 2 index is returned.
    vector<ll> ret;
    if (t.nxt[x][nxt - 'A'] != -1)
      ret.emplace_back(t.nxt[x][nxt - 'A']);
    if (t.exi[x] != -1 && t.nxt[0][nxt - 'A'] != -1)
      ret.emplace_back(t.nxt[0][nxt - 'A']);
    return ret;
  };

#define f(i, j, e) (min(dp[i][j][e][0], dp[i][j][e][1]))
  for (ll i = n; i >= 1; --i) {
    ll dj = 0;
    for (ll j = 1; j <= m; ++j) {
      for (ll tp = 1; tp <= tSize - 1; ++tp) {
        // 1. consider down from this position; here tp serve as real one
        if (i == n) {
          if (tp == t.nxt[0][a[i][j] - 'A'])
            dp[i][j][tp][dj] = 1;
        } else
          for (auto e : advance(tp, a[i][j]))
            chkmin(dp[i][j][e][dj], f(i + 1, j, tp) + 1);

        // 2. consider direction specified; here tp serve as pp
        ll tdj = dj == 0 ? -1 : 1;
        if (j + tdj >= 1 && j + tdj <= m) {
          auto v = advance(tp, a[i][j]);
          for (auto e : v)
            chkmin(dp[i][j][e][dj], f(i, j + tdj, tp) + 1);
        }
      }
    }
    dj = 1;
    for (ll j = m; j >= 1; --j) {
      for (ll tp = 1; tp <= tSize - 1; ++tp) {
        // 1. consider down from this position; here tp serve as real one
        if (i == n) {
          if (tp == t.nxt[0][a[i][j] - 'A'])
            dp[i][j][tp][dj] = 1;
        } else
          for (auto e : advance(tp, a[i][j]))
            chkmin(dp[i][j][e][dj], f(i + 1, j, tp) + 1);

        // 2. consider direction specified; here tp serve as pp
        ll tdj = dj == 0 ? -1 : 1;
        if (j + tdj >= 1 && j + tdj <= m) {
          auto v = advance(tp, a[i][j]);
          for (auto e : v)
            chkmin(dp[i][j][e][dj], f(i, j + tdj, tp) + 1);
        }
      }
    }
  }

  // generate answer
  ll ans = 1e16;
  FOR(i, 1, m)
  FOR(tp, 1, tSize - 1) if (t.exi[tp] != -1 && t.curr[tp] == a[1][i])
      chkmin(ans, f(1, i, tp));

  if (ans > (ll)1e14)
    cout << "impossible\n";
  else
    cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll T_ = 1;
  // cin >> T_;
  while (T_--)
    solve();
  return 0;
}
