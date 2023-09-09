#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 300;
vector<vector<int>> E, Big;
vector<unordered_set<int>> Oppo, Same;
vector<int> deg, bigNode, in, del;
vector<pair<int, int>> edg;
unordered_set<int> small_node, big_node;
vector<int> BigNodes;
char read_char() {
  char ch = 0;
  while (ch < '0' || ch > '9') { // ch 不是数字时
    if (ch == '+')
      return '+';
    if (ch == '?')
      return '?';
    if (ch == '-')
      return '-';
    ch = (char)getchar(); // 继续读入
  }
  return 'x';
}
int read() {
  int x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') { // ch 不是数字时
    if (ch == '-')
      w = -1;             // 判断是否为负
    ch = (char)getchar(); // 继续读入
  }
  while (ch >= '0' && ch <= '9') { // ch 是数字时
    x = x * 10 + (ch - '0'); // 将新读入的数字「加」在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = (char)getchar(); // 继续读入
  }
  return x * w; // 数字 * 正负号 = 实际数值
}
void write(int x) {
  static int sta[40];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top)
    putchar(sta[--top] + 48); // 48 是 '0'
  puts("");
}
void add(int u) {
  in[u] = 1;
  if (deg[u] < N) {
    for (auto id : E[u]) {
      if (del[id])
        continue;
      int v = u ^ edg[id].first ^ edg[id].second;
      if (deg[v] < N) {
        if (in[v]) {
          small_node.erase(id);
        } else {
          small_node.emplace(id);
        }
      } else {
        if (in[v]) {
          Oppo[v].erase(id);
          Same[v].emplace(id);
        } else {
          Oppo[v].emplace(id);
          Same[v].erase(id);
        }
      }
    }
  } else {
    for (auto id : Big[u]) {
      if (del[id])
        continue;
      int v = u ^ edg[id].first ^ edg[id].second;
      if (in[v]) {
        big_node.erase(id);
      } else {
        big_node.emplace(id);
      }
    }
    swap(Oppo[u], Same[u]);
  }
}
void delet(int u) {
  in[u] = 0;
  if (deg[u] < N) {
    for (auto id : E[u]) {
      if (del[id])
        continue;
      int v = u ^ edg[id].first ^ edg[id].second;
      if (deg[v] < N) {
        if (in[v]) {
          small_node.emplace(id);
        } else {
          small_node.erase(id);
        }
      } else {
        if (in[v]) {
          Oppo[v].emplace(id);
          Same[v].erase(id);
        } else {
          Oppo[v].erase(id);
          Same[v].emplace(id);
        }
      }
    }
  } else {
    for (auto id : Big[u]) {
      if (del[id])
        continue;
      int v = u ^ edg[id].first ^ edg[id].second;
      if (!in[v]) {
        big_node.erase(id);
      } else {
        big_node.emplace(id);
      }
    }
    swap(Oppo[u], Same[u]);
  }
}
void ask() {
  if (!small_node.empty()) {
    int id = *small_node.begin();
    write(id + 1);
    small_node.erase(small_node.begin());
    del[id] = 1;
    return;
  }
  if (!big_node.empty()) {
    int id = *big_node.begin();
    write(id + 1);
    big_node.erase(big_node.begin());
    del[id] = 1;
    return;
  }
  for (auto u : BigNodes) {
    if (!Oppo[u].empty()) {
      int id = *Oppo[u].begin();
      Oppo[u].erase(Oppo[u].begin());
      del[id] = 1;
      write(id + 1);
      return;
    }
  }
  write(0);
  return;
}
auto solve() {
  int n, m;
  n = read();
  m = read();
  small_node.clear();
  big_node.clear();
  E = vector<vector<int>>(n + 5);
  edg = vector<pair<int, int>>(m + 5);
  del = vector<int>(m + 5);
  deg = in = vector<int>(n + 5);
  bigNode = vector<int>(n + 5, -1);
  for (int i = 0, u, v; i < m; ++i) {
    u = read();
    v = read();
    u--, v--;
    edg[i] = {u, v};
    E[u].emplace_back(i), E[v].emplace_back(i);
    deg[u]++, deg[v]++;
  }
  int cnt = 0;
  BigNodes.clear();
  for (int i = 0; i < n; ++i) {
    if (deg[i] >= N) {
      bigNode[i] = cnt++;
      BigNodes.emplace_back(i);
    }
  }
  Oppo = Same = vector<unordered_set<int>>(n);
  Big = vector<vector<int>>(n);
  for (int u = 0; u < n; ++u) {
    if (deg[u] >= N) {
      for (auto id : E[u]) {
        int v = u ^ edg[id].first ^ edg[id].second;
        if (deg[v] >= N) {
          Big[u].emplace_back(id);
        } else {
          Same[u].emplace(id);
        }
      }
    }
  }
  int q;
  q = read();
  while (q--) {
    char s = read_char();
    if (s == '+') {
      int v = read();
      v--;
      add(v);
    } else if (s == '-') {
      int v = read();
      v--;
      delet(v);
    } else {
      ask();
    }
  }
}
int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}