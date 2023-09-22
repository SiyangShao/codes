#include <bits/stdc++.h>
#include <dbg.h>
using namespace std;
using ll = long long;
#define chkmax(a, x) a = max(a, x)

void solve() {
  vector<ll> a(500);
  for (ll i = 0; i < 500; ++i)
    a[i] = i;
  random_device rd;
  mt19937 rng(rd());

  set<array<ll, 3>> s;
  for (ll u = 0; u < 500; ++u)
    for (ll v = u + 1; v < 500; ++v)
      for (ll w = v + 1; w < 500; ++w) {
        s.insert(array{a[u], a[v], a[w]});
        s.insert(array{a[w], a[v], a[u]});
      }

  dbg(s.size());
  vector<vector<ll>> ans;
  for (ll i = 2; i < 50; ++i) {
    dbg(i);
    shuffle(a.begin(), a.end(), rng);
    vector<array<ll, 3>> tmp;
    for (ll u = 0; u < 500; ++u)
      for (ll v = u + 1; v < 500; ++v)
        for (ll w = v + 1; w < 500; ++w) {
          if (!s.contains(array{a[u], a[v], a[w]})) {
            tmp.push_back({a[u], a[v], a[w]});
          }
        }
    dbg(tmp.size());
    if (!tmp.empty()) {
      for (auto [u, v, w] : tmp) {
        s.insert(array{u, v, w});
      }
      ans.emplace_back(a);
    } else {
      i--;
    }
    dbg(s.size());
  }
  if (a.size() >= 124251000) {
    for (auto &a : ans) {
      for (auto j : a) {
        cout << j << ", ";
      }
      cout << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int _ = 1;
  // cin >> _;
  while (_--)
    solve();
}