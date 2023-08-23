#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 5e5 + 7;
constexpr ll inf = 1e9;
constexpr ll mod = inf + 7;
ll n;
array<ll, N> a, pos, sz, T, t, parent;
array<vector<ll>, N> g, vertices;
ll answ;
void update(ll pos, ll delta1, ll delta2) {
  for (; pos <= n; pos += pos & -pos) {
    T[pos] += delta1;
    T[pos] %= mod;
    t[pos] += delta2;
    t[pos] %= mod;
  }
}
ll get(ll pos, ll tp) {
  ll answ = 0;
  for (; pos > 0; pos -= pos & -pos) {
    answ += tp == 1 ? T[pos] : t[pos];
    answ %= mod;
  }
  return answ;
}
ll get(ll l, ll r, ll tp) { return get(r, tp) - get(l - 1, tp); }
void dfs(ll v, ll p) {
  sz[v] = 1;
  parent[v] = p;
  for (ll i = 0; i < (ll)g[v].size(); i++) {
    ll to = g[v][i];
    if (to == p)
      continue;
    dfs(to, v);
    sz[v] += sz[to];
  }
}
void rec(ll v, ll p) {
  ll mx = 0, vertex = -1;
  for (auto to : g[v]) {
    if (to == p)
      continue;
    if (sz[to] > mx) {
      mx = sz[to];
      vertex = to;
    }
  }
  for (ll i = 0; i < (ll)g[v].size(); i++) {
    ll to = g[v][i];
    if (to == p || to == vertex)
      continue;
    rec(to, v);
    for (ll vert : vertices[to]) {
      update(pos[vert], mod - sz[vert], mod - (sz[vert] * 1ll * a[vert] % mod));
    }
  }
  if (vertex != -1) {
    rec(vertex, v);
    ll c = a[v] * 1ll * (n - sz[vertex]) % mod;
    answ += get(1, pos[v] - 1, 1) * 1ll * c % mod;
    answ %= mod;

    answ += get(pos[v] + 1, n, 2) * 1ll * (n - sz[vertex]) % mod;
    answ %= mod;

    swap(vertices[v], vertices[vertex]);
    for (ll i = 0; i < (ll)g[v].size(); i++) {
      ll to = g[v][i];
      if (to == p || to == vertex)
        continue;
      for (ll vert : vertices[to]) {
        vertices[v].push_back(vert);
        update(pos[vert], sz[vert], sz[vert] * 1ll * a[vert] % mod);
        ///
        if (a[v] > a[vert]) {
          c = a[v] * 1ll * (n - sz[to]) % mod;
          answ += c * 1ll * sz[vert] % mod;
          answ %= mod;
        } else {
          c = a[vert] * 1ll * (n - sz[to]) % mod;
          answ += c * 1ll * sz[vert] % mod;
          answ %= mod;
        }
      }
      vertices[to].clear();
    }
  }

  // remove
  ll c = a[v] * 1ll * sz[v] % mod;
  answ -= get(1, pos[v] - 1, 1) * 1ll * c % mod;
  answ = (answ + mod) % mod;

  answ -= get(pos[v] + 1, n, 2) * 1ll * sz[v] % mod;
  answ = (answ + mod) % mod;

  vertices[v].push_back(v);
  update(pos[v], sz[v], sz[v] * 1ll * a[v] % mod);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  vector<ll> mas;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    mas.push_back(a[i]);
  }
  sort(mas.begin(), mas.end());

  for (ll i = 1; i <= n; i++) {
    pos[i] = lower_bound(mas.begin(), mas.end(), a[i]) - mas.begin() + 1;
  }

  for (ll i = 1; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(1, -1);

  vector<pair<ll, ll>> A;
  for (ll i = 1; i <= n; i++) {
    A.emplace_back(a[i], i);
  }
  sort(A.begin(), A.end());

  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    ll v = A[i].second;
    ll c = A[i].first * 1ll * sz[v] % mod;
    answ += c * 1ll * sum % mod;
    answ %= mod;
    ///
    sum += sz[v];
    sum %= mod;
  }

  rec(1, -1);

  for (ll i = 1; i <= n; i++) {
    ll coff = sz[i] * 1ll * (n - sz[i] + 1) % mod;
    answ += coff * 1ll * a[i] % mod;
    answ %= mod;

    ll sum = 0;
    for (ll j = 0; j < (ll)g[i].size(); j++) {
      ll vertex = g[i][j];
      if (vertex == parent[i])
        continue;
      ll coff = sum * 1ll * sz[vertex] % mod;
      answ += coff * 1ll * a[i] % mod;
      answ %= mod;
      sum = (sum + sz[vertex]) % mod;
    }
  }
  cout << answ << "\n";
  return 0;
}
