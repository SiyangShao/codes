#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int m;
  cin >> m;
  vector<string> mp(m);
  for (auto &i : mp) {
    cin >> i;
    sort(i.begin(), i.end());
  }
  vector<int> W_I, I_W, N_W, W_N, N_I, I_N;
  vector<tuple<int, char, int, char>> ans;
  auto change_W_I = [&](int id) {
    if (I_W.empty()) {
      W_I.emplace_back(id);
    } else {
      ans.emplace_back(I_W.back(), 'i', id, 'w');
      I_W.pop_back();
    }
  };
  auto change_I_W = [&](int id) {
    if (W_I.empty()) {
      I_W.emplace_back(id);
    } else {
      ans.emplace_back(W_I.back(), 'w', id, 'i');
      W_I.pop_back();
    }
  };
  auto change_N_W = [&](int id) {
    if (W_N.empty()) {
      N_W.emplace_back(id);
    } else {
      ans.emplace_back(W_N.back(), 'w', id, 'n');
      W_N.pop_back();
    }
  };
  auto change_W_N = [&](int id) {
    if (N_W.empty()) {
      W_N.emplace_back(id);
    } else {
      ans.emplace_back(N_W.back(), 'n', id, 'w');
      N_W.pop_back();
    }
  };
  auto change_I_N = [&](int id) {
    if (N_I.empty()) {
      I_N.emplace_back(id);
    } else {
      ans.emplace_back(N_I.back(), 'n', id, 'i');
      N_I.pop_back();
    }
  };
  auto change_N_I = [&](int id) {
    if (I_N.empty()) {
      N_I.emplace_back(id);
    } else {
      ans.emplace_back(I_N.back(), 'i', id, 'n');
      I_N.pop_back();
    }
  };
  for (int i = 0; i < m; ++i) {
    if (mp[i] == "inw")
      continue;
    int W = 0, I = 0, N = 0;
    for (int j = 0; j < 3; ++j) {
      if (mp[i][j] == 'i')
        I++;
      if (mp[i][j] == 'w')
        W++;
      if (mp[i][j] == 'n')
        N++;
    }
    if (W > 1) {
      if (W == 3) {
        change_W_N(i);
        change_W_I(i);
      } else {
        if (I == 1) {
          change_W_N(i);
        } else {
          change_W_I(i);
        }
      }
    } else if (I > 1) {
      if (I == 3) {
        change_I_W(i);
        change_I_N(i);
      } else {
        if (W == 1) {
          change_I_N(i);
        } else {
          change_I_W(i);
        }
      }
    } else {
      if (N == 3) {
        change_N_I(i);
        change_N_W(i);
      } else {
        if (W == 1) {
          change_N_I(i);
        } else {
          change_N_W(i);
        }
      }
    }
  }
  if (!W_I.empty()) {
    assert(!I_N.empty() && !N_W.empty());
    for (auto id : W_I) {
      change_W_N(id);
      change_N_I(id);
    }
  } else if (!I_W.empty()) {
    assert(!N_I.empty() && !W_N.empty());
    for (auto id : I_W) {
      change_I_N(id);
      change_N_W(id);
    }
  }
  cout << ans.size() << "\n";
  for (auto &[l, x, r, y] : ans) {
    cout << l + 1 << " " << x << " " << r + 1 << " " << y << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}