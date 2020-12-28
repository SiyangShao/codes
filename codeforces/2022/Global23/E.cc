#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v1, v2, v3, v4;
vector<ll> v;
auto ask(const vector<ll> &l, const vector<ll> &r) {
  cout << "? " << l.size() + r.size();
  for (auto &i : l) {
    cout << " " << i;
  }
  for (auto &i : r) {
    cout << " " << i;
  }
  cout << endl;
  string s;
  cin >> s;
  return s == "YES";
}
auto real_ask() {
  v1.clear(), v2.clear(), v3.clear(), v4.clear();
  for (ll i = 0; i < v.size(); ++i) {
    if (i % 4 == 0) {
      v1.emplace_back(v[i]);
    } else if (i % 4 == 1) {
      v2.emplace_back(v[i]);
    } else if (i % 4 == 2) {
      v3.emplace_back(v[i]);
    } else {
      v4.emplace_back(v[i]);
    }
  }
  bool ans1 = ask(v1, v2);
  bool ans2 = ask(v1, v3);
  if (ans1 && ans2) {
    v4.clear();
  } else if (!ans1 && !ans2) {
    v1.clear();
  } else if (ans1 && !ans2) {
    v3.clear();
  } else {
    v2.clear();
  }
  v.clear();
  for (auto &i : v1) {
    v.emplace_back(i);
  }
  for (auto &i : v2) {
    v.emplace_back(i);
  }
  for (auto &i : v3) {
    v.emplace_back(i);
  }
  for (auto &i : v4) {
    v.emplace_back(i);
  }
}
auto solve() {
  ll n;
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    v.emplace_back(i);
  }
  while (v.size() >= 4) {
    real_ask();
  }
  // cout << "! " << v.size() << endl;
  // assert(v.size() == 1 || v.size() == 2);
  if (v.size() == 1) {
    cout << "! " << v[0] << endl;
  } else if (v.size() == 2) {
    cout << "! " << v[0] << endl;
    cout << "! " << v[1] << endl;
  } else {
    int bad = -1;
    bool x = ask(vector<ll>{v[0]}, vector<ll>{});
    bool y = ask(vector<ll>{v[1]}, vector<ll>{});
    if (x && y)
      bad = 2;
    if (x && !y)
      bad = 1;
    if (!x && y)
      bad = 0;
    if (!x && !y) {
      bool w = ask(vector<ll>{v[1]}, vector<ll>{});
      if (!w) {
        bad = 1;
      } else {
        bool q = ask(vector<ll>{v[2]}, vector<ll>{});
        if (q == 1) {
          bad = 0;
        } else {
          bad = 2;
        }
      }
    }
    assert(bad != -1);
    for (ll i = 0; i < 3; ++i) {
      if (i == bad)
        continue;
      cout << "! " << v[i] << endl;
    }
  }
}
auto main() -> int {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}