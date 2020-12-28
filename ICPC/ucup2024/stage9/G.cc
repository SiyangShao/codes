#include <bits/stdc++.h>

using ll = long long;
const int N = 1e5 + 5;

int isprime[N], prime[N], cnt;

void sieve(int n) {
  isprime[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!isprime[i])
      prime[++cnt] = i;
    for (int j = i * 2; j <= n; j += i)
      isprime[j] = 1;
  }
}

void solve() {
  ll n;
  scanf("%lld", &n);
  if (n == 1)
    return (void)(puts("1"));
  std::vector<std::pair<ll, ll>> vec;
  ll tmp = n;
  for (ll t = 1; tmp > 1 && t <= cnt; ++t) {
    int cur = 0;
    while (tmp > 1 && tmp % prime[t] == 0)
      tmp /= prime[t], ++cur;
    if (cur)
      vec.emplace_back(prime[t], cur);
  }
  if (tmp > 1)
    vec.emplace_back(tmp, 1);
  ll t1 = 1, t2 = 1;
  for (auto [p, k] : vec) {
    t2 = t2 * (k + k + 1);
    // printf("%lld %lld\n", p, k);
  }
  printf("%lld\n", (t2 + 1) / 2);
}

int main() {
  int T;
  scanf("%d", &T);
  sieve(1e5);
  // for(int i = 1; i<=10; ++i){
  //   printf("%d ", isprime[i]);
  // }
  // printf("\n");
  // for(int i = 1; i<=10; ++i){
  //   printf("%d ", prime[i]);
  // }
  while (T--)
    solve();
  return 0;
}