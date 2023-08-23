#include <cassert>
#include <iostream>
#include <vector>

constexpr int inf = 0x3f3f3f3f;

int get_ans(int a, int b) {
  int ans = 0;
  while (b != 0) {
    ans += a / b;
    int t = a % b;
    a = b;
    b = t;
  }
  return ans;
}

struct Ans {
  int x, y, n;

  Ans(int x, int y, int n) : x(x), y(y), n(n) {}
};

std::vector<Ans> ans;

void solve(int, int, int);
void solve(int, int, int, int);

void solve(int x, int y, int a, int b) {
  //    if (x == 1 && y == 4) {
  //        std::cout << a << ' ' << b << '\n';
  //    }
  if (a == 0 || b == 0) {
    return;
  }
  if (a == b) {
    solve(x, y, a);
    return;
  }
  if (a < b) {
    solve(x, y, a);
    solve(x, y + a, a, b - a);
    return;
  }
  if (a > b) {
    solve(x, y, b);
    solve(x + b, y, a - b, b);
    return;
  }
}

void solve(int x, int y, int n) {
  if (n == 0) {
    return;
  }
  if (n <= 7) {
    ans.emplace_back(x, y, n);
    return;
  }
  int mn = inf;
  int mn_k = -1;
  for (int k = 1; k < n; ++k) {
    int t = 2 * get_ans(n - k, k) + 2;
    if (t < mn) {
      mn = t;
      mn_k = k;
    }
  }
  assert(mn_k != -1);
  //    std::cout << x << ' ' << y << ' ' << n << ' ' << mn_k << '\n';
  solve(x, y, mn_k);
  solve(x + mn_k, y + mn_k, n - mn_k);
  solve(x + mn_k, y, n - mn_k, mn_k);
  solve(x, y + mn_k, mn_k, n - mn_k);
  ans.emplace_back(x, y, n);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  for (int n = 1; n <= 1000; ++n) {
    ans.clear();
    if (n == 1) {
      std::cout << "0\n";
      continue;
    }
    solve(1, 1, n);
    std::cout << ans.size() << '\n';
    for (auto &i : ans) {
      std::cout << i.x << ' ' << i.y << ' ' << i.n << '\n';
    }
  }
  return 0;
}
