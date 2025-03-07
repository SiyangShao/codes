#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int L = 32;
template <typename T, int N> class ST {
private:
  int l, log[N + 1];
  T st[L][N];
  inline int log2n(int n) { return 32 - __builtin_clz(n - 1); }

public:
  ST() {
    log[1] = 0;
    for (int i = 2; i <= N; i++) {
      log[i] = 31 - __builtin_clz(i - 1);
    }
  }
  void build(int n, const T *value) {
    l = log2(n);
    memcpy(st[0], value, sizeof(T) * n);
    for (int i = 1; i < l; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
      }
    }
  }
  T rmq(int a, int b) const {
    const int l = log[b - a];
    return min(st[l][a], st[l][b - (1 << l)]);
  }
};
constexpr int N = 2e5 + 10;
ST<int, N> st;
int n;
int p[N], pos[N], q[N], ans[N];
int check(int i, int now) {
  if (now > i)
    return 1;
  if (now == i)
    return 0;
  return -1;
}
bool cmp(int x, int y) {
  if (x == y) {
    return false;
  }
  if (x > y) {
    return !cmp(y, x);
  }
  // i < j
  int pos_i = (x % 2 == 0 ? x : x - 1), pos_j = (y % 2 == 0 ? y : y - 1);
  int offset_i = x % 2, offset_j = y % 2;

  // if there's a middle element
  vector<pair<int, int>> contri;
  if (pos_i + 3 <= pos_j - 1) {
    auto mid = st.rmq(pos_i + 3, pos_j);
    int val = p[mid];
    int contribution = 0;
    // cerr << "From " << pos_i + 3 << " to " << pos_j - 1 << " is " << mid
         // << " with " << val << endl;
    if (val % 2 == 1) {
      contribution = -1;
    } else {
      contribution = 1;
    }
    contri.emplace_back(mid, contribution);
  }
  if (pos_i == pos_j) {
    // just offset
    for (int i = pos_i; i <= pos_i + 2; i++) {
      int prv, cur;
      if (i == pos_i) {
        prv = i + 2 - offset_i;
        cur = i + 2 - offset_j;
      } else if (i == pos_i + 1) {
        prv = (offset_i == 0 ? i - 1 : i + 1);
        cur = (offset_j == 0 ? i - 1 : i + 1);
      } else {
        prv = i - 1 - offset_i;
        cur = i - 1 - offset_j;
      }
      // cerr << x << " to " << y << " is " << i << " " << pos[i] << " " << prv
      //      << " " << cur << endl;
      if(prv != cur)
      contri.emplace_back(pos[i], (prv > cur ? -1 : 1));
    }
  } else {
    for (int i = pos_i; i <= pos_i + 2; i++) {
      if (i == pos_i) {
        contri.emplace_back(
            pos[i], -check((i % 2 != 0 ? i - 1 : i + 1), i + 2 - offset_i));
      } else if (i == pos_i + 1) {
        contri.emplace_back(pos[i], -check((i % 2 != 0 ? i - 1 : i + 1),
                                           (offset_i == 0 ? i - 1 : i + 1)));
      } else {
        if (pos_i + 2 != pos_j) {
          contri.emplace_back(
              pos[i], -check((i % 2 != 0 ? i - 1 : i + 1), i - 1 - offset_i));
        }
      }
    }
    if (pos_i + 2 == pos_j) {
      int prv = pos_j - 1 - offset_i;
      int cur = pos_j + 2 - offset_j;
      if(prv != cur)
      contri.emplace_back(pos[pos_i + 2], (prv > cur ? -1 : 1));
    }
    for (int i = pos_j; i <= pos_j + 2; i++) {
      if (i == pos_j) {
        if (pos_i + 2 != pos_j) {
          contri.emplace_back(
              pos[i], check((i % 2 == 0 ? i - 1 : i + 1), i + 2 - offset_j));
        }
      } else if (i == pos_j + 1) {
        contri.emplace_back(pos[i], check((i % 2 == 0 ? i - 1 : i + 1),
                                          (offset_j == 0 ? i - 1 : i + 1)));
      } else {
        contri.emplace_back(
            pos[i], check((i % 2 == 0 ? i - 1 : i + 1), i - 1 - offset_j));
      }
    }
  }
  // cerr << "Compare " << x << " and " << y << endl;
  // for (auto it : contri) {
  //   cerr << it.first << " " << it.second << endl;
  // }
  // cerr << "===========" << endl;
  auto it = contri.end();
  for (auto jt = contri.begin(); jt != contri.end(); ++jt) {
    if (jt->second != 0 && (it == contri.end() || jt->first < it->first)) {
      it = jt;
    }
  }
  assert(it != contri.end());
  return it->second > 0;
}
auto solve() {
  int k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
    pos[p[i]] = i;
  }
  if (n % 2 == 0) {
    if (k != 1) {
      cout << "-1\n";
      return;
    }
    for (int i = 0; i < n; ++i) {
      cout << (p[i] ^ 1) + 1 << " ";
    }
    cout << "\n";
    return;
  }
  if (k > n - 1) {
    cout << "-1\n";
    return;
  }
  vector<int> sol(n - 1);
  st.build(n, pos);
  iota(sol.begin(), sol.end(), 0);
  sort(sol.begin(), sol.end(), cmp);
  // for (auto i : sol) {
  //   cerr << i << " ";
  // }
  // cerr << "\n";
  int ord = sol[k - 1];
  int base = ord / 2, offset = ord % 2;
  int start_p = base * 2;
  // base, base+1, base+2 in triangle
  // 0-1 2-3 4-5-6 7-8 9-10
  for (int i = 0; i < n; ++i) {
    if (i < start_p) {
      q[i] = pos[i ^ 1];
    } else if (i > start_p + 2) {
      if (i % 2 == 0) {
        q[i] = pos[i - 1];
      } else {
        q[i] = pos[i + 1];
      }
    } else {
      // offset = 0: 6-4-5
      // offset = 1: 5-6-4
      if (i == start_p) {
        q[i] = pos[i + 1 + offset];
      } else if (i == start_p + 1) {
        q[i] = (offset == 0 ? pos[i + 1] : pos[i - 1]);
      } else {
        q[i] = pos[i - 2 + offset];
      }
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   cerr << q[i] << " ";
  // }
  // cerr << "\n";
  for (int i = 0; i < n; ++i) {
    ans[q[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] + 1 << " ";
  }
  cout << "\n";
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
