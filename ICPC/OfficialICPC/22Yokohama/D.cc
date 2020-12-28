#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve(vector<string> &mpx, vector<string> &mpy) {
  int nx = (int)mpx.size(), mx = (int)mpx[0].size();
  vector<pair<int, int>> nodex, nodey;
  for (int i = 0; i < nx; ++i) {
    for (int j = 0; j < mx; ++j) {
      if (mpx[i][j] == 'o')
        nodex.emplace_back(i, j);
    }
  }
  int ny = (int)mpy.size(), my = (int)mpy[0].size();
  for (int i = 0; i < ny; ++i) {
    for (int j = 0; j < my; ++j) {
      if (mpy[i][j] == 'o')
        nodey.emplace_back(i, j);
    }
  }
  int n = (int)nodex.size();
  // cout << nodex.size() << " " << nodey.size() << "\n";
  assert(nodex.size() == nodey.size());
  // case 1:
  pair<int, int> curx;
  int flag = 0;
  set<pair<int, int>> st;
  for (int i = 1; i < n; ++i) {
    auto [u, v] = nodex[i];
    u -= nodex[0].first, v -= nodex[0].second;
    st.emplace(u, v);
  }
  for (int i = 1; i < n; ++i) {
    auto [u, v] = nodey[i];
    u -= nodey[0].first, v -= nodey[0].second;
    if (st.contains({u, v}))
      st.erase({u, v});
    else {
      flag++;
      curx = {u, v};
    }
  }
  if (flag == 1) {
    auto [u, v] = *st.begin();
    auto [x, y] = curx;
    // cout << u + nodex[0].first << " " << v + nodex[0].second << "\n";
    // cout << x + nodex[0].first << " " << y + nodex[0].second << "\n";
    cout << v + nodex[0].second << " " << u + nodex[0].first << "\n";
    cout << y + nodex[0].second << " " << x + nodex[0].first << "\n";
    return true;
  }
  if (n >= 2) {
    flag = 0;
    st.clear();
    for (int i = 1; i < n; ++i) {
      auto [u, v] = nodex[i];
      u -= nodex[0].first, v -= nodex[0].second;
      st.emplace(u, v);
    }
    for (int i = 0; i < n; ++i) {
      if (i == 1)
        continue;
      auto [u, v] = nodey[i];
      u -= nodey[1].first, v -= nodey[1].second;
      if (st.contains({u, v}))
        st.erase({u, v});
      else {
        flag++;
        curx = {u, v};
      }
    }
    if (flag == 1) {
      auto [u, v] = *st.begin();
      auto [x, y] = curx;
      cout << v + nodex[0].second << " " << u + nodex[0].first << "\n";
      cout << y + nodex[0].second << " " << x + nodex[0].first << "\n";
      return true;
    }
    flag = 0;
    st.clear();
    for (int i = 0; i < n; ++i) {
      if (i == 1)
        continue;
      auto [u, v] = nodex[i];
      u -= nodex[1].first, v -= nodex[1].second;
      st.emplace(u, v);
    }
    for (int i = 1; i < n; ++i) {
      auto [u, v] = nodey[i];
      u -= nodey[0].first, v -= nodey[0].second;
      if (st.contains({u, v}))
        st.erase({u, v});
      else {
        flag++;
        curx = {u, v};
      }
    }
    if (flag == 1) {
      auto [u, v] = *st.begin();
      auto [x, y] = curx;
      cout << v + nodex[1].second << " " << u + nodex[1].first << "\n";
      cout << y + nodex[1].second << " " << x + nodex[1].first << "\n";
      return true;
    }
    flag = 0;
    st.clear();
    for (int i = 0; i < n; ++i) {
      if (i == 1)
        continue;
      auto [u, v] = nodex[i];
      u -= nodex[1].first, v -= nodex[1].second;
      st.emplace(u, v);
    }
    for (int i = 0; i < n; ++i) {
      if (i == 1)
        continue;
      auto [u, v] = nodey[i];
      u -= nodey[1].first, v -= nodey[1].second;
      if (st.contains({u, v}))
        st.erase({u, v});
      else {
        flag++;
        curx = {u, v};
      }
    }
    if (flag == 1) {
      auto [u, v] = *st.begin();
      auto [x, y] = curx;
      cout << v + nodex[1].second << " " << u + nodex[1].first << "\n";
      cout << y + nodex[1].second << " " << x + nodex[1].first << "\n";
      return true;
    }
  }
  return false;
}
void rotate(vector<string> &mp) {
  int n = (int)mp.size();
  int m = (int)mp[0].size();
  vector<string> ans(m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      ans[i] += " ";
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ans[j][n - i - 1] = mp[i][j];
    }
  }
  swap(mp, ans);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> mp(n);
  for (auto &i : mp)
    cin >> i;

  int x, y;
  cin >> x >> y;
  vector<string> should(x);
  for (auto &i : should)
    cin >> i;

  if (solve(mp, should))
    return 0;
  rotate(should);
  if (solve(mp, should))
    return 0;
  rotate(should);
  if (solve(mp, should))
    return 0;
  rotate(should);
  if (solve(mp, should))
    return 0;
  rotate(should);
}