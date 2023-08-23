#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5 + 2;
using bst = bitset<N>;
vector<tuple<ll, int, int, int>> edg;

vector<tuple<int, int, ll, ll, int>> Edg;
namespace MST {
struct DSU {
  int n;
  vector<int> fa;
  DSU(int _n) : n(_n), fa(_n) { iota(fa.begin(), fa.end(), 0); }
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y) {
      fa[x] = y;
    }
  }
};

DSU dsu(0);
void update(ll t) {
  for (auto &[w, u, v, id] : edg) {
    auto [x, y, a, b, z] = Edg[id];
    w = a * t + b;
  }
  iota(dsu.fa.begin(), dsu.fa.end(), 0);
}
bst get_MST(int n, ll t) {
  update(t);
  // ranges::sort(edg);
  sort(edg.begin(), edg.end());
  bst st;
  for (auto [w, u, v, id] : edg) {
    if (dsu.find(u) != dsu.find(v)) {
      dsu.merge(u, v);
      st[id] = true;
    }
  }
  return st;
}
}; // namespace MST

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, T;
  cin >> n >> T;
  MST::dsu = MST::DSU(n);
  Edg.resize(n + 1);
  edg.resize(n + 1);
  for (int i = 0; i < n + 1; ++i) {
    int u, v, a, b;
    cin >> u >> v >> a >> b;
    u--, v--;
    Edg[i] = {u, v, a, b, i};
    edg[i] = {b, u, v, i};
  }
  function<ll(int)> cal_fi = [&](int id) {
    ll l = 0, r = T;
    ll ans = r;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      if (MST::get_MST(n, mid)[id]) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  };
  function<ll(int)> cal_ls = [&](int id) {
    ll l = 0, r = T;
    ll ans = l;
    while (l <= r) {
      ll mid = (l + r) >> 1;
      if (MST::get_MST(n, mid)[id]) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  };

  auto zero = MST::get_MST(n, 0);
  auto final = MST::get_MST(n, T);
  priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>>
      edit;
  int LLL = 0, RRR = 0;
  for (int i = 0; i < n + 1; ++i) {
    if (zero[i] && !final[i]) {
      ll t = cal_ls(i);
      LLL++;
      edit.emplace(t + 1, i, 0);
    }
  }

  for (int i = 0; i < n + 1; ++i) {
    if (!zero[i] && final[i]) {
      auto t = cal_fi(i);
      RRR++;
      edit.emplace(t, i, 1);
    }
  }
  assert((LLL == 0 && RRR == 0) || (LLL == 1 && RRR == 1));
  ll ans_a = 0, cur = 0;
  for (int i = 0; i < n + 1; ++i) {
    if (zero[i]) {
      auto [u, v, a, b, _] = Edg[i];
      ans_a += a;
      cur += b;
    }
  }
  for (ll i = 0; i <= T; ++i) {
    while (!edit.empty()) {
      auto [t, id, op] = edit.top();
      if (t != i)
        break;
      edit.pop();
      auto [u, v, a, b, _] = Edg[id];
      if (op == 0) {
        ans_a -= a;
        cur -= b + a * i;
      } else {
        ans_a += a;
        cur += b + a * i;
      }
    }
    cout << cur << "\n";
    cur += ans_a;
  }
}