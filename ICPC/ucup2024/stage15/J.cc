#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  ll n, m, q;
  cin >> n >> m >> q;
  vector<ll> score(m, 0);
  vector<ll> lvl(m, -1);
  ll cur_score = 0, cur_lvl = 0;
  while (q--) {
    ll typ;
    cin >> typ;
    if (typ == 1) {
      cur_score = m;
      cin >> cur_lvl;
    } else if (typ == 2) {
      ll id, x;
      cin >> id >> x;
      id--;
      if (x != cur_lvl) {
        continue;
      }
      if (lvl[id] != x) {
        lvl[id] = x;
        score[id] += cur_score;
        cur_score--;
      }
    } else {
      ll id, x;
      cin >> id >> x;
      id--;
      if (x != cur_lvl) {
        continue;
      }
      if (lvl[id] != x) {
        lvl[id] = x;
      }
    }
  }
  vector<ll> id(m);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](ll x, ll y) {
    if (score[x] != score[y])
      return score[x] > score[y];
    else
      return x < y;
  });
  for (auto &i : id) {
    cout << i + 1 << " " << score[i] << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
