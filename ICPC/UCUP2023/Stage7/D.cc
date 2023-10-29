#include <cassert>
#include <iostream>
#include <set>
#include <utility>

constexpr int n = 8;

bool ins(std::set<std::pair<int, int>> &st, int x, int y) {
  if (1 <= x && x <= n && 1 <= y && y <= n) {
    st.emplace(x, y);
    return true;
  }
  return false;
}

std::set<std::pair<int, int>> Ma(int x, int y) {
  const int dirx[] = {1, 2, 2, 1, -1, -2, -2, -1};
  const int diry[] = {2, 1, -1, -2, -2, -1, 1, 2};
  std::set<std::pair<int, int>> st;
  for (int i = 0; i < 8; ++i) {
    ins(st, x + dirx[i], y + diry[i]);
  }
  st.emplace(x, y);
  return st;
}

std::set<std::pair<int, int>> B(int x, int y) { // Xiang
  const int dirx[] = {1, 1, -1, -1};
  const int diry[] = {1, -1, 1, -1};
  std::set<std::pair<int, int>> st;
  for (int i = 0; i < 4; ++i) {
    int nowx = x, nowy = y;
    while (ins(st, nowx, nowy)) {
      nowx += dirx[i];
      nowy += diry[i];
    }
  }
  return st;
}

std::set<std::pair<int, int>> R(int x, int y) {
  const int dirx[] = {1, -1, 0, 0};
  const int diry[] = {0, 0, 1, -1};
  std::set<std::pair<int, int>> st;
  for (int i = 0; i < 4; ++i) {
    int nowx = x, nowy = y;
    while (ins(st, nowx, nowy)) {
      nowx += dirx[i];
      nowy += diry[i];
    }
  }
  return st;
}

std::set<std::pair<int, int>> merge(const std::set<std::pair<int, int>> &a,
                                    const std::set<std::pair<int, int>> &b) {
  std::set<std::pair<int, int>> ans = a;
  for (auto x : b) {
    ans.insert(x);
  }
  return ans;
}

std::set<std::pair<int, int>> Q(int x, int y) {
  return merge(B(x, y), R(x, y));
}

std::set<std::pair<int, int>> A(int x, int y) {
  return merge(B(x, y), Ma(x, y));
}

std::set<std::pair<int, int>> C(int x, int y) {
  return merge(R(x, y), Ma(x, y));
}

std::set<std::pair<int, int>> M(int x, int y) {
  return merge(Q(x, y), Ma(x, y));
}

std::set<std::pair<int, int>> get(char c, int x, int y) {
  if (c == 'B') {
    return B(x, y);
  } else if (c == 'R') {
    return R(x, y);
  } else if (c == 'Q') {
    return Q(x, y);
  } else if (c == 'A') {
    return A(x, y);
  } else if (c == 'M') {
    return M(x, y);
  } else if (c == 'C') {
    return C(x, y);
  }
  std::cerr << c << std::endl;
  assert(false);
}

char mp[10][10];
std::string s;

bool get(int now) { // 1: 先手必胜
  assert(now < 10);
  char now_c = s[now];
  bool ans = false;
  //    std::cerr << now << std::endl;
  //    for (int i = 1; i <= 8; ++i) {
  //        for (int j = 1; j <= 8; ++j) {
  //            std::cerr << mp[i][j];
  //        }
  //        std::cerr << std::endl;
  //    }
  //    std::cerr << std::endl;
  for (int x = 1; x <= 8; ++x) {
    for (int y = 1; y <= 8; ++y) {
      if (mp[x][y] == '.') {
        const auto to = get(now_c, x, y);
        bool can = true;
        //                std::cerr << "=================================" <<
        //                std::endl; std::cerr << x << ' ' << y << std::endl;
        //                for (const auto [to_x, to_y] : to) {
        //                    std::cerr << to_x << ' ' << to_y << std::endl;
        //                }
        //                std::cerr << "=================================" <<
        //                std::endl;
        for (const auto [to_x, to_y] : to) {
          if (mp[to_x][to_y] != '.' && mp[to_x][to_y] != '*') {
            can = false;
            break;
          }
        }
        if (can) {
          for (const auto [to_x, to_y] : to) {
            mp[to_x][to_y] = '*';
          }
          mp[x][y] = now_c;
          ans |= !get(now + 1);
          for (const auto [to_x, to_y] : to) {
            mp[to_x][to_y] = '.';
          }
          //                    mp[x][y] = '.';
          if (ans) {
            return ans;
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  //    auto x = get('B', 2, 3);
  //    for (auto [a, b]: x) {
  //        std::cout << a << ' ' << b << std::endl;
  //    }
  std::cin >> s;
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      mp[i][j] = '.';
    }
  }
  if (get(0)) {
    std::cout << "Alice\n";
  } else {
    std::cout << "Bob\n";
  }
  return 0;
}