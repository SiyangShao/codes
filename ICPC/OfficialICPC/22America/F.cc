#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<ll, ll>> a(4);
bool check(ll x) {
  vector<ll> p = {0, 1, 2, 3};

  do {
    for (ll msk = 0; msk <= (1ll << 4) - 1; ++msk) {
      auto G = [&](ll loc, bool u) {
        bool isInvert = (msk & (1ll << p[loc])) != 0;
        return (u ^ isInvert) ? a[p[loc]].first : a[p[loc]].second;
      };
      ll L = G(0, false) + G(2, false);
      ll R = G(1, false) + G(3, false);
      ll U = G(0, true) + G(1, true);
      ll D = G(2, true) + G(3, true);

      if (L == R && U == D && L == x && U == x) {
        return true;
      }
    }
  } while (next_permutation(p.begin(), p.end()));
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  vector<pair<ll, ll>> vec(4);
  ll s = 0;
  for (auto &[w, h] : vec) {
    cin >> w >> h;
    s += w * h;
  }
  for (int i = 0; i < 4; ++i) {
    a[i] = vec[i];
  }
  const ll l = (ll)sqrtl(s);
  if (l * l != s) {
    cout << "0\n";
    return 0;
  }
  for (auto &[w, h] : vec) {
    if (w > l || h > l) {
      cout << "0\n";
      return 0;
    }
  }
  if (check(l)) {
    cout << "1\n";
    return 0;
  }
  auto check2 = [&](int no_i, int no_j, ll x, ll y) {
    if (x <= 0 || y <= 0)
      return false;
    ll a = -1, b = -1, c = -1, d = -1;
    for (int i = 0; i < 4; ++i) {
      if (i == no_i || i == no_j)
        continue;
      if (a == -1) {
        a = vec[i].first;
        b = vec[i].second;
      } else {
        c = vec[i].first;
        d = vec[i].second;
      }
    }
    if (a + c == x) {
      if (b == d && b == y)
        return true;
    }
    if (a + c == y) {
      if (b == d && b == x)
        return true;
    }
    if (b + d == x) {
      if (a == c && a == y)
        return true;
    }
    if (b + d == y) {
      if (a == c && a == x)
        return true;
    }
    if (a + d == x) {
      if (b == c && b == y) {
        return true;
      }
    }
    if (a + d == y) {
      if (b == c && b == x) {
        return true;
      }
    }
    if (b + c == x) {
      if (a == d && a == y) {
        return true;
      }
    }
    if (b + c == y) {
      if (a == d && a == x) {
        return true;
      }
    }
    return false;
  };
  // cout<<l<<"\n";
  // for(int i = 0 ; i < 4; ++i){
  //   cout<<vec[i].first<<" "<<vec[i].second<<"\n";
  // }
  // cout<<"\n";
  for (int i = 0; i < 4; ++i) {
    if (vec[i].first != l && vec[i].second != l) {
      continue;
    }
    ll x = l, y = -1;
    if (vec[i].first == l) {
      y = l - vec[i].second;
    } else {
      y = l - vec[i].first;
    }
    for (int j = 0; j < 4; ++j) {
      if (i == j)
        continue;
      ll z = -1;
      if (vec[j].first == x || vec[j].second == x) {
        // cout << i << " " << j << "\n";
        if (vec[j].first == x) {
          z = y - vec[j].second;
        } else {
          z = y - vec[j].first;
        }
        if (check2(i, j, x, z)) {
          cout << "1\n";
          return 0;
        }
      }
      if (vec[j].first == y || vec[j].second == y) {
        // cout << i << " " << j << "\n";
        if (vec[j].first == y) {
          z = x - vec[j].second;
        } else {
          z = x - vec[j].first;
        }
        if (check2(i, j, y, z)) {
          cout << "1\n";
          return 0;
        }
      }
    }
  }
  cout << "0\n";
}