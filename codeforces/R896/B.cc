#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
auto solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for (auto &i : a) {
    cin >> i;
    sum += i;
  }
  if (sum % n != 0) {
    cout << "No\n";
    return;
  }
  sum /= n;
  // cout << sum << "\n";
  vector<ll> dif(n);
  vector<ll> num(40);
  vector<ll> add(40), del(40);
  for (int i = 0; i < n; ++i) {
    dif[i] = a[i] - sum;
    if (dif[i] == 0) {
      continue;
    } else {
      ll x = abs(dif[i]);
      ll lef = 0;
      ll cnt = 0;
      bool flag = false;
      while (x) {
        cnt++;
        if (x & 1) {
          if (!flag) {
            lef = cnt - 1;
          }
          flag = true;
        } else {
          if (flag) {
            cout << "No\n";
            return;
          }
        }
        x >>= 1;
      }
      assert(abs(dif[i]) == (1LL << cnt) - (1LL << lef));
      assert(cnt >= lef + 1);
      if (cnt == lef + 1) {
        assert(popcount(ull(abs(dif[i]))) == 1);
        assert(abs(dif[i]) == (1LL << lef));
        if (dif[i] > 0)
          add[lef]++;
        else
          del[lef]++;
      } else if (dif[i] > 0) {
        // need to - dif[i]
        num[cnt]++;
        num[lef]--;
      } else {
        num[cnt]--;
        num[lef]++;
      }
    }
  }
  for (int i = 0; i < 35; ++i) {
    if (num[i] == 0) {
      ll change = min(del[i], add[i]);
      add[i] -= change, del[i] -= change;
      if (add[i] % 2 == 0) {
        num[i + 1] += add[i] / 2;
      } else {
        cout << "No\n";
        return;
      }
      if (del[i] % 2 == 0) {
        num[i + 1] -= del[i] / 2;
      } else {
        cout << "No\n";
        return;
      }

    } else {
      if (abs(num[i]) > abs(add[i] + del[i])) {
        cout << "No\n";
        return;
      }
      if (num[i] > 0) {
        ll change = min(num[i], del[i]);
        num[i] -= change, del[i] -= change;
        if (num[i] == 0) {
          // del[i] 兑子 add[i]
          change = min(del[i], add[i]);
          add[i] -= change, del[i] -= change;
          if (add[i] % 2 == 0) {
            num[i + 1] += add[i] / 2;
          } else {
            cout << "No\n";
            return;
          }
          if (del[i] % 2 == 0) {
            num[i + 1] -= del[i] / 2;
          } else {
            cout << "No\n";
            return;
          }
        } else {
          // add[i] 取反 num[i]
          change = min(add[i], num[i]);
          num[i] -= change;
          num[i + 1] += change;
          assert(num[i] == 0);
          add[i] -= change;
          if (add[i] % 2 == 0) {
            num[i + 1] += add[i] / 2;
          } else {
            cout << "No\n";
            return;
          }
        }
      } else {
        ll change = min(abs(num[i]), add[i]);
        num[i] += change, add[i] -= change;
        if (num[i] == 0) {
          // add[i] 兑子 del[i]
          change = min(del[i], add[i]);
          add[i] -= change, del[i] -= change;
          if (add[i] % 2 == 0) {
            num[i + 1] += add[i] / 2;
          } else {
            cout << "No\n";
            return;
          }
          if (del[i] % 2 == 0) {
            num[i + 1] -= del[i] / 2;
          } else {
            cout << "No\n";
            return;
          }
        } else {
          // del[i] 取反 num[i]
          change = min(del[i], abs(num[i]));
          num[i] += change;
          num[i + 1] -= change;
          assert(num[i] == 0);
          del[i] -= change;
          if (del[i] % 2 == 0) {
            num[i + 1] -= del[i] / 2;
          } else {
            cout << "No\n";
            return;
          }
        }
      }
    }
  }
  cout << "Yes\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}