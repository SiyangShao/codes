#include <iostream>
#include <vector>

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> board;
  for (int i = 0; i < n; ++i) {
    std::string s;
    std::cin >> s;
    board.push_back(s);
  }
  std::vector<std::string> ans(n, std::string(m, '.'));
  for (int j = 0; j < m; ++j) {
    int col = 0;
    for (int i = 0; i < n; ++i) {
      if (board[i][j] == 'R') {
        if (ans[i][j] == 'W') {
          col++;
        } else {
          col--;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (board[i][j] == 'L') {
        if (col > 0) {
          ans[i][j] = 'B';
          ans[i][j + 1] = 'W';
          col--;
        } else {
          ans[i][j] = 'W';
          ans[i][j + 1] = 'B';
          col++;
        }
      }
    }
    if (col != 0) {
      std::cout << "-1\n";
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    int row = 0;
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'D') {
        if (ans[i][j] == 'W') {
          row++;
        } else {
          row--;
        }
      }
    }
    for (int j = 0; j < m; ++j) {
      if (board[i][j] == 'U') {
        if (row > 0) {
          ans[i][j] = 'B';
          ans[i + 1][j] = 'W';
          row--;
        } else {
          ans[i][j] = 'W';
          ans[i + 1][j] = 'B';
          row++;
        }
      }
    }
    if (row != 0) {
      std::cout << "-1\n";
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << '\n';
  }
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