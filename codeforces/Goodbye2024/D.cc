#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
ll qpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) {
      res = res * x % MOD;
    }
    x = x * x % MOD;
    y >>= 1;
  }
  return res;
}
ll inv(ll x) { return qpow(x, MOD - 2); }
void swp(vector<pair<ll, ll>> &b, vector<ll> &bid, ll x, ll y) {
  assert(b[x].first == b[y].first);
  swap(b[x], b[y]);
  bid[b[x].second] = x;
  bid[b[y].second] = y;
}
void op(vector<pair<ll, ll>> &a, vector<pair<ll, ll>> &b, vector<ll> &bid, ll x,
        map<ll, ll> &cntb, map<ll, ll> &begb, ll &P) {
  ll curPos = bid[x];
  assert(b[curPos].second == x);
  // step 1: check how many b[x] is there with same value
  ll num = cntb[b[curPos].first];
  ll beg = begb[b[curPos].first];
  // if num is not 1, then we need to swap
  if (num != 1) {
    swp(b, bid, curPos, beg + num - 1);
    curPos = beg + num - 1;
  }
  // remove prev
  P = P * inv(min(a[curPos].first, b[curPos].first)) % MOD;
  // step 2: add curPos 1
  cntb[b[curPos].first]--;
  if (cntb[b[curPos].first] == 0) {
    begb.erase(b[curPos].first);
    cntb.erase(b[curPos].first);
  }
  b[curPos].first++;
  cntb[b[curPos].first]++;
  begb[b[curPos].first] = curPos;
  // apply cur
  P = P * min(a[curPos].first, b[curPos].first) % MOD;
}
auto solve() {
  int n, q;
  cin >> n >> q;
  vector<pair<ll, ll>> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<ll> aid(n), bid(n);
  map<ll, ll> cnta, cntb, bega, begb;
  ll P = 1;
  for (int i = 0; i < n; i++) {
    aid[a[i].second] = i;
    bid[b[i].second] = i;
    P = P * min(a[i].first, b[i].first) % MOD;
    cnta[a[i].first]++;
    cntb[b[i].first]++;
    if (!bega.contains(a[i].first)) {
      bega[a[i].first] = i;
    }
    if (!begb.contains(b[i].first)) {
      begb[b[i].first] = i;
    }
  }
  cout << P;
  while (q--) {
    int o, x;
    cin >> o >> x;
    x--;
    if (o == 1) {
      op(b, a, aid, x, cnta, bega, P);
    } else {
      // o == 2
      op(a, b, bid, x, cntb, begb, P);
    }
    cout << " " << P;
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
