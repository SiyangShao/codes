#include <bits/stdc++.h>
#define dbg(...) (__VA_ARGS__)
using namespace std;
using ll = long long;
#define int ll
int getInt() {
  int tmp;
  cin >> tmp;
  return tmp;
}
vector<int> st;
void dfs(int u, const vector<vector<int>> &E, vector<int> &cur) {
  for (int i = cur[u]; i < (int)E[u].size(); i = cur[u]) {
    cur[u] = i + 1;
    dfs(E[u][i], E, cur);
  }
  st.emplace_back(u);
}
struct DSU {
  vector<int> fa;
  DSU(int n) : fa(n) { iota(fa.begin(), fa.end(), 0); }
  int find(int u) {
    if (u != fa[u]) {
      fa[u] = find(fa[u]);
    }
    return fa[u];
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    fa[u] = v;
  }
};

bool cal(const vector<int> &idx, const vector<int> &idy, const int OFFSET,
         const int n, const int m, const auto &front_a, const auto &front_b,
         const auto &back_a, const auto &back_b, const auto &front_a2,
         const auto &front_b2, const auto &back_a2, const auto &back_b2) {
  map<pair<int, int>, int> mpx, mpy;
  int cnt = 0;
  for (auto i : idx) {
    // const string &s = a[i];
    // string_view FIRST_HALF = string_view(s).substr(0, OFFSET);
    int FIRST_HALF = front_a[i][OFFSET - 1];
    int FIRST_HALF2 = front_a2[i][OFFSET - 1];
    if (mpx[{FIRST_HALF, FIRST_HALF2}] == 0) {
      mpx[{FIRST_HALF, FIRST_HALF2}] = ++cnt;
    }
    // string_view SECOND_HALF = string_view(s).substr(OFFSET, m - OFFSET);
    int SECOND_HALF = back_a[i][m - OFFSET - 1];
    int SECOND_HALF2 = back_a2[i][m - OFFSET - 1];
    if (mpy[{SECOND_HALF, SECOND_HALF2}] == 0) {
      mpy[{SECOND_HALF, SECOND_HALF2}] = ++cnt;
    }
  }
  for (auto i : idy) {
    // const string &s = b[i];
    // string_view FIRST_HALF = string_view(s).substr(m - OFFSET, OFFSET);
    int FIRST_HALF = back_b[i][OFFSET - 1];
    int FIRST_HALF2 = back_b2[i][OFFSET - 1];
    if (mpx[{FIRST_HALF, FIRST_HALF2}] == 0) {
      mpx[{FIRST_HALF, FIRST_HALF2}] = ++cnt;
    }
    // string_view SECOND_HALF = string_view(s).substr(0, m - OFFSET);
    int SECOND_HALF = front_b[i][m - OFFSET - 1];
    int SECOND_HALF2 = front_b2[i][m - OFFSET - 1];
    if (mpy[{SECOND_HALF, SECOND_HALF2}] == 0) {
      mpy[{SECOND_HALF, SECOND_HALF2}] = ++cnt;
    }
  }
  vector<vector<int>> E(cnt);
  vector<size_t> in(cnt, 0);
  vector<int> type(cnt, 0);
  DSU dsu(cnt);
  unordered_map<int, vector<int>> vecx, vecy;
  for (auto i : idx) {
    // const string &s = a[i];
    // string_view FIRST_HALF = string_view(s).substr(0, OFFSET);
    int FIRST_HALF = front_a[i][OFFSET - 1];
    int FIRST_HALF2 = front_a2[i][OFFSET - 1];
    int u = mpx[{FIRST_HALF, FIRST_HALF2}];
    type[u - 1] = 1;
    // string_view SECOND_HALF = string_view(s).substr(OFFSET, m - OFFSET);
    int SECOND_HALF = back_a[i][m - OFFSET - 1];
    int SECOND_HALF2 = back_a2[i][m - OFFSET - 1];
    int v = mpy[{SECOND_HALF, SECOND_HALF2}];
    type[v - 1] = 0;
    assert(u > 0 && v > 0);
    E[u - 1].emplace_back(v - 1);
    vecx[(u - 1) * cnt + v - 1].emplace_back(i);
    in[v - 1]++;
    dsu.merge(u - 1, v - 1);
  }
  for (auto i : idy) {
    // const string &s = b[i];
    // string_view FIRST_HALF = string_view(s).substr(m - OFFSET, OFFSET);
    int FIRST_HALF = back_b[i][OFFSET - 1];
    int FIRST_HALF2 = back_b2[i][OFFSET - 1];
    int u = mpx[{FIRST_HALF, FIRST_HALF2}];
    type[u - 1] = 1;
    // string_view SECOND_HALF = string_view(s).substr(0, m - OFFSET);
    int SECOND_HALF = front_b[i][m - OFFSET - 1];
    int SECOND_HALF2 = front_b2[i][m - OFFSET - 1];
    int v = mpy[{SECOND_HALF, SECOND_HALF2}];
    type[v - 1] = 0;
    assert(u > 0 && v > 0);
    E[v - 1].emplace_back(u - 1);
    vecy[(v - 1) * cnt + u - 1].emplace_back(i);
    dsu.merge(u - 1, v - 1);
    in[u - 1]++;
  }
  for (int i = 0; i < cnt; ++i) {
    if (in[i] != E[i].size())
      return false;
    if (dsu.find(i) != dsu.find(0))
      return false;
  }
  vector<int> cur(cnt, 0);
  st.clear();
  dfs(0, E, cur);
  reverse(st.begin(), st.end());
  if (*st.begin() != st.back())
    return false;
  if ((int)st.size() != n * 2 + 1)
    return false;
  vector<int> up, down;
  for (int i = 0; i + 1 < (int)st.size(); i++) {
    int u = st[i];
    int v = st[i + 1];
    if (type[u] == 1) {
      assert(type[v] == 0);
      assert(!vecx[u * cnt + v].empty());
      up.emplace_back(vecx[u * cnt + v].back());
      vecx[u * cnt + v].pop_back();
    } else {
      assert(type[v] == 1);
      assert(!vecy[u * cnt + v].empty());
      down.emplace_back(vecy[u * cnt + v].back());
      vecy[u * cnt + v].pop_back();
    }
  }
  assert((int)up.size() == n && (int)down.size() == n);
  for (auto i : up)
    cout << i + 1 << " ";
  cout << "\n";
  for (auto i : down)
    cout << i + 1 << " ";
  cout << "\n";
  return true;
}
auto solve() {
  const int n = getInt();
  const int m = getInt();
  vector<string> a(n), b(n);
  for (auto &i : a) {
    cin >> i;
  }
  for (auto &i : b) {
    cin >> i;
  }
  vector<int> idx(n), idy(n);
  for (int i = 0; i < n; ++i) {
    idx[i] = idy[i] = i;
  }

  bool ZERO_OFFSET = true;
  vector<int> num(26, 0);
  vector<vector<int>> front_a(n, vector<int>(m));
  vector<vector<int>> front_a2(n, vector<int>(m));
  vector<vector<int>> front_b(n, vector<int>(m));
  vector<vector<int>> front_b2(n, vector<int>(m));
  vector<vector<int>> back_a(n, vector<int>(m));
  vector<vector<int>> back_a2(n, vector<int>(m));
  vector<vector<int>> back_b(n, vector<int>(m));
  vector<vector<int>> back_b2(n, vector<int>(m));
  constexpr int M = 1e9 + 9;
  constexpr int M2 = 1e9 + 7;
  constexpr int B = 503;
  for (int i = 0; i < n; ++i) {
    for (auto j : a[i]) {
      num[j - 'a']++;
    }
    int res = 0, res2 = 0;
    for (int j = 0; j < m; ++j) {
      res = int(((ll)res * B + a[idx[i]][j]) % M);
      front_a[idx[i]][j] = res;
      res2 = int(((ll)res2 * B + a[idx[i]][j]) % M2);
      front_a2[idx[i]][j] = res2;
    }
    int bb = B, bb2 = B;
    for (int j = 0; j < m; ++j) {
      // from m - j - 1 to m - 1
      back_a[idx[i]][j] =
          front_a[idx[i]][m - 1] -
          (int)((m - j - 1 != 0 ? (ll)front_a[idx[i]][m - j - 2] : 0LL) * bb %
                M);
      back_a[idx[i]][j] = (back_a[idx[i]][j] + M) % M;
      bb = (int)((ll)bb * B % M);
      back_a2[idx[i]][j] =
          front_a2[idx[i]][m - 1] -
          (int)((m - j - 1 != 0 ? (ll)front_a2[idx[i]][m - j - 2] : 0LL) * bb2 %
                M2);
      back_a2[idx[i]][j] = (back_a2[idx[i]][j] + M2) % M2;
      bb2 = (int)((ll)bb2 * B % M2);
    }
    for (auto j : b[i]) {
      num[j - 'a']--;
    }
    res = 0, res2 = 0;
    bb = B, bb2 = B;
    for (int j = 0; j < m; ++j) {
      res = int(((ll)res * B + b[idy[i]][j]) % M);
      front_b[idy[i]][j] = res;
      res2 = int(((ll)res2 * B + b[idy[i]][j]) % M2);
      front_b2[idy[i]][j] = res2;
    }
    for (int j = 0; j < m; ++j) {
      // from m - j - 1 to m - 1
      back_b[idy[i]][j] =
          front_b[idy[i]][m - 1] -
          (int)((m - j - 1 != 0 ? (ll)front_b[idy[i]][m - j - 2] : 0LL) * bb %
                M);
      back_b[idy[i]][j] = (back_b[idy[i]][j] + M) % M;
      bb = (int)((ll)bb * B % M);
      back_b2[idy[i]][j] =
          front_b2[idy[i]][m - 1] -
          (int)((m - j - 1 != 0 ? (ll)front_b2[idy[i]][m - j - 2] : 0LL) * bb2 %
                M2);
      back_b2[idy[i]][j] = (back_b2[idy[i]][j] + M2) % M2;
      bb2 = (int)((ll)bb2 * B % M2);
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (num[i] != 0) {
      cout << "-1\n";
      return;
    }
  }
  ranges::sort(idx, [&](int i, int j) {
    if (front_a[i][m - 1] != front_a[j][m - 1])
      return front_a[i][m - 1] < front_a[j][m - 1];
    else
      return front_a2[i][m - 1] < front_a2[j][m - 1];
  });
  ranges::sort(idy, [&](int i, int j) {
    if (front_b[i][m - 1] != front_b[j][m - 1])
      return front_b[i][m - 1] < front_b[j][m - 1];
    else
      return front_b2[i][m - 1] < front_b2[j][m - 1];
  });
  for (int i = 0; i < n; ++i) {
    if (a[idx[i]] != b[idy[i]]) {
      ZERO_OFFSET = false;
    }
  }
  if (ZERO_OFFSET) {
    for (auto i : idx) {
      cout << i + 1 << " ";
    }
    cout << "\n";
    for (auto i : idy) {
      cout << i + 1 << " ";
    }
    cout << "\n";
    return;
  }
  for (int OFFSET = 1; OFFSET < m; ++OFFSET) {
    if (cal(idx, idy, OFFSET, n, m, front_a, front_b, back_a, back_b, front_a2,
            front_b2, back_a2, back_b2))
      return;
  }
  cout << "-1\n";
}
auto main() -> signed {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}