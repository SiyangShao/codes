#include <iostream>
#include <vector>

constexpr int maxn = 105;

char ans[maxn][maxn];

void solve_ou(int n) {
  for (int i = 0; i + 1 < n; i += 3) {
    for (int j = 0; j < n; j += 2) {
      ans[i][j] = '#';
      ans[i + 1][j] = '#';
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ans[i][j] = '.';
    }
    ans[i][n] = '\0';
  }
  n++;
  if (n % 6 == 1) {
    solve_ou(n - 8);
    for (int i = 0; i < n - 7; i += 3) {
      ans[i][n - 7] = ans[i + 1][n - 7] = '#';
      ans[n - 7][i] = ans[n - 7][i + 1] = '#';
      ans[i][n - 5] = ans[i + 1][n - 5] = '#';
      ans[n - 5][i] = ans[n - 5][i + 1] = '#';
    }
    for (int i = 0; i < n - 7; i += 2) {
      ans[i][n - 3] = ans[i][n - 2] = '#';
      ans[n - 3][i] = ans[n - 2][i] = '#';
    }
    ans[n - 7][n - 7] = ans[n - 6][n - 7] = '#';
    ans[n - 7][n - 5] = ans[n - 6][n - 5] = '#';
    ans[n - 4][n - 7] = ans[n - 4][n - 6] = '#';
    ans[n - 2][n - 7] = ans[n - 2][n - 6] = '#';
    ans[n - 7][n - 3] = ans[n - 7][n - 2] = '#';
    ans[n - 5][n - 3] = ans[n - 5][n - 2] = '#';
    ans[n - 3][n - 4] = ans[n - 2][n - 4] = '#';
    ans[n - 3][n - 2] = ans[n - 2][n - 2] = '#';
    n--;
  } else if (n % 6 == 3) {
    solve_ou(n - 4);
    for (int i = 0; i < n - 3; i += 2) {
      ans[i][n - 3] = ans[i][n - 2] = '#';
      ans[n - 3][i] = ans[n - 2][i] = '#';
    }
    ans[n - 3][n - 3] = ans[n - 3][n - 2] = '#';
    n--;
  } else if (n % 6 == 5) {
    solve_ou(n - 6);
    for (int i = 0; i < n - 5; i += 2) {
      ans[i][n - 5] = ans[i][n - 4] = '#';
      ans[n - 5][i] = ans[n - 4][i] = '#';
    }
    for (int i = 0; i < n - 5; i += 3) {
      ans[i][n - 2] = ans[i + 1][n - 2] = '#';
      ans[n - 2][i] = ans[n - 2][i + 1] = '#';
    }
    ans[n - 5][n - 5] = ans[n - 4][n - 5] = '#';
    ans[n - 2][n - 5] = ans[n - 2][n - 4] = '#';
    ans[n - 2][n - 2] = ans[n - 3][n - 2] = '#';
    ans[n - 5][n - 2] = ans[n - 5][n - 3] = '#';
    n--;
  } else if (n % 6 == 0) {
    solve_ou(n - 1);
    n--;
  } else if (n % 6 == 2) {
    solve_ou(n - 3);
    for (int i = 0; i < n - 3; i += 3) {
      ans[n - 2][i] = ans[n - 2][i + 1] = '#';
      ans[i][n - 2] = ans[i + 1][n - 2] = '#';
    }
    n--;
  } else {
    solve_ou(n - 5);
    for (int i = 0; i < n - 5; i += 3) {
      ans[n - 2][i] = ans[n - 2][i + 1] = '#';
      ans[i][n - 2] = ans[i + 1][n - 2] = '#';
      ans[n - 4][i] = ans[n - 4][i + 1] = '#';
      ans[i][n - 4] = ans[i + 1][n - 4] = '#';
    }
    ans[n - 4][n - 4] = ans[n - 4][n - 3] = '#';
    ans[n - 2][n - 4] = ans[n - 2][n - 3] = '#';
    n--;
  }
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << '\n';
  }
  // std::cout << "CASE\n\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int T;
  std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}