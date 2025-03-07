#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<ll, ll>> a(n);
  ll miny = 1e9, minx = 1e9, maxx = 0;
  map<ll, vector<ll>> mp;
  for (auto &[x, y] : a) {
    cin >> x >> y;
    miny = min(miny, y);
    minx = min(minx, x);
    maxx = max(maxx, x);
    mp[x].emplace_back(y);
  }
  set<pair<ll, ll>> st;
  vector<pair<ll, ll>> ans;
  st.emplace(minx, miny);
  ans.emplace_back(minx, miny);
  vector<ll> line;
  for(auto &[x, vec]: mp) {
    sort(vec.begin(), vec.end());

  }
  for (auto &[x, vec] : mp) {
    reverse(vec.begin(), vec.end());
    if (x != minx && !st.contains({x, miny + 1})) {
      st.emplace(x, miny + 1);
      ans.emplace_back(x, miny + 1);
    }
    for (auto y : vec) {
      if (st.count({x, y})) {
        continue;
      }
      st.emplace(x, y);
      ans.emplace_back(x, y);
    }
    st.emplace(x + 1, miny + 1);
    ans.emplace_back(x + 1, miny + 1);
  }
  ans.emplace_back(maxx + 1, miny);
  reverse(line.begin(), line.end());
  for (auto i : line) {
    if (!st.contains({i, miny})) {
      ans.emplace_back(i, miny);
    }
  }
  cout << ans.size() << "\n";
  for (auto [x, y] : ans) {
    cout << x << " " << y << "\n";
  }
}
