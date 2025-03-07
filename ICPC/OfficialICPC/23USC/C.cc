#include <bits/stdc++.h>
// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include "dbg.h"
#else
#define dbg(...) (__VA_ARGS__)
#endif
using namespace std;
using ll = long long;
constexpr int N = 1024;
array<bitset<N>, N> cmp, inv;
vector<array<int, 5>> vec;
int final_val;

class Parser {
public:
  string expr; // The expression to parse
  int pos;     // Current position in the expression

  // Constructor initializes the expression and starting position
  Parser(const string &s) : expr(s), pos(0) {}

  // Entry point to parse the entire expression
  int parse() {
    int res = parse_xor(); // Start parsing from the lowest precedence
    // After parsing, ensure we've consumed the entire expression
    if (pos != expr.size()) {
      throw invalid_argument("Unexpected characters at end of expression");
    }
    return res;
  }

private:
  // Parse the '^' (XOR) operator
  int parse_xor() {
    int left = parse_or();
    while (true) {
      if (match('^')) {
        int right = parse_or();
        left = left ^ right;
      } else {
        break;
      }
    }
    return left;
  }

  // Parse the '|' (OR) operator
  int parse_or() {
    int left = parse_and();
    while (true) {
      if (match('|')) {
        int right = parse_and();
        left = left | right;
      } else {
        break;
      }
    }
    return left;
  }

  // Parse the '&' (AND) operator
  int parse_and() {
    int left = parse_equality();
    while (true) {
      if (match('&')) {
        int right = parse_equality();
        left = left & right;
      } else {
        break;
      }
    }
    return left;
  }

  // Parse the '=' (EQUALS) operator
  int parse_equality() {
    int left = parse_unary();
    while (true) {
      if (match('=')) {
        int right = parse_unary();
        left = (left == right) ? 1 : 0;
      } else {
        break;
      }
    }
    return left;
  }

  // Parse the '!' (NOT) unary operator
  int parse_unary() {
    if (match('!')) {
      int operand = parse_unary();
      return !operand; // Logical NOT: !0 = 1, !1 = 0
    }
    return parse_primary();
  }

  // Parse primary expressions: '0', '1', or '(' expression ')'
  int parse_primary() {
    if (match('(')) {
      int val = parse_xor(); // Start parsing from the lowest precedence
      if (!match(')')) {
        throw invalid_argument("Expected ')'");
      }
      return val;
    }
    // Parse a single digit: '0' or '1'
    char current = peek();
    if (current == '0') {
      pos++;
      return 0;
    }
    if (current == '1') {
      pos++;
      return 1;
    }
    throw invalid_argument(string("Unexpected character: ") + current);
  }

  // Helper function to match and consume an expected character
  bool match(char expected) {
    skip_whitespace(); // In case there are any (though the user specified no
                       // spaces)
    if (peek() == expected) {
      pos++;
      return true;
    }
    return false;
  }

  // Helper function to get the current character without consuming it
  char peek() const {
    if (pos >= expr.size())
      return '\0';
    return expr[pos];
  }

  // Optional: Skip any whitespace (not needed if input has no spaces)
  void skip_whitespace() {
    while (pos < expr.size() && isspace(expr[pos])) {
      pos++;
    }
  }
};

auto cal(string exp, int x, int y) {
  // x == 0 or 1
  // y == 0 or 1
  for (auto &c : exp) {
    if (c == 'x') {
      c = x + '0';
    } else if (c == 'y') {
      c = y + '0';
    }
  }
  Parser p(exp);
  return p.parse();
}
auto get_bit(int x, int i) { return (x >> i) & 1; }
auto op(int x, int y) {
  for (auto [a, b, c, d, e] : vec) {
    // a bit in x and b bit in y
    if (get_bit(x, a) == c && get_bit(y, b) == d) {
      return e;
    }
  }
  return final_val;
}
auto solve() {
  int n, k;
  cin >> n >> k;
  map<tuple<int, int, int, int>, int> mp;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    string exp;
    cin >> exp;
    int r;
    cin >> r;
    for (int x = 0; x < 2; ++x) {
      for (int y = 0; y < 2; ++y) {
        // dbg(exp, x, y, cal(exp, x, y));
        if (mp.contains({a, b, x, y})) {
          continue;
        } else if (cal(exp, x, y)) {
          mp[{a, b, x, y}] = r;
          vec.push_back({a, b, x, y, r});
        }
      }
    }
  }
  cin >> final_val;
  ll ans = 0;
  // for (auto &[a, b, c, d, e] : vec) {
  //   cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
  // }
  for (int i = 0; i < (1 << k); ++i) {
    if (op(i, i) != 0) {
      ans++;
    }
  }
  cout << ans << " ";
  for (int i = 0; i < (1 << k); ++i) {
    for (int j = 0; j < (1 << k); ++j) {
      cmp[i][j] = op(i, j);
      inv[i][j] = !cmp[i][j];
    }
  }
  ans = 0;
  for (int i = 0; i < (1 << k); ++i) {
    for (int j = 0; j < (1 << k); ++j) {
      if (cmp[i][j] == cmp[j][i] && cmp[i][j] == 1) {
        ans++;
      }
    }
  }
  cout << ans << " ";
  ans = 0;
  for (int i = 0; i < (1 << k); ++i) {
    for (int j = 0; j < (1 << k); ++j) {
      if (cmp[i][j]) {
        ans += (cmp[j] & inv[i]).count();
      }
    }
  }
  cout << ans << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}