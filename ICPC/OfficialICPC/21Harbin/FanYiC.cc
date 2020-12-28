#include <iostream>
#include <map>
#include <set>
#include <vector>

constexpr int maxn = (int)1e5 + 5;

std::vector<int> e[maxn];
std::map<int, int> f[maxn];
int c[maxn];
int mx[maxn];
int dp[maxn];
void dfs(int now) {
  //    std::cout << now << std::endl;
  if (c[now] != 0) {
    f[now][c[now]] = 1;
    mx[now] = 1;
    dp[now] = 1;
    return;
  }
  mx[now] = 1;
  for (int to : e[now]) {
    dfs(to);
    if (f[now].size() < f[to].size()) {
      std::swap(f[now], f[to]);
      std::swap(dp[now], dp[to]);
    }
    dp[now] += dp[to];
    for (auto [u, v] : f[to]) {
      f[now][u] += v;
      mx[now] = std::max(mx[now], f[now][u]);
    }
  }
  dp[now] -= mx[now];
  dp[now]++;
  if (mx[now] != 1) {
    std::map<int, int> tmp;
    for (auto [u, v] : f[now]) {
      if (v == mx[now]) {
        tmp[u] = 1;
      }
    }
    f[now] = tmp;
  }
  mx[now] = 1;
}

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    e[i].clear();
    f[i].clear();
    mx[i] = 0;
    dp[i] = 0;
  }
  for (int i = 2; i <= n; ++i) {
    int to;
    std::cin >> to;
    e[to].push_back(i);
    //        std::cout << i << ' ' << to << std::endl;
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> c[i];
  }
  dfs(1);
  std::cout << dp[1] << std::endl;
  //    for (int i = 1; i <= n; ++i) {
  //        std::cout << dp[i] << " ";
  //    }
  //    std::cout << std::endl;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  //    int T;
  //    std::cin >> T;
  //    while (T--) {
  solve();
  //    }
  return 0;
}