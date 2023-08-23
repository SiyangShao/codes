#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct stream {
  int len, from, to;
  stream(int _len, int _from, int _to) : len(_len), from(_from), to(_to) {}
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int m, n, q;
  cin >> m >> n >> q;
  vector<tuple<char, int, int, int>> node(n);
  vector<int> sum(n), num(n);
  int id = 0;
  for (auto &[type, x, y, z] : node) {
    cin >> type >> x >> y >> z;
    x--, y--, z--;
    id = max(id, x), id = max(id, y), id = max(id, z);
  }
  vector<stream> streams(id + 1, {0, -1, -1});
  streams[0] = {m, -1, -1};
  {
    int i = 0;
    for (const auto &[type, x, y, z] : node) {
      if (type == 'S') {
        streams[x].to = i;
        streams[y].from = i;
        streams[z].from = i;
        // streams[y].len = (streams[x].len + 1) / 2;
        // streams[z].len = streams[x].len - streams[y].len;
      } else {
        streams[x].to = i;
        streams[y].to = i;
        streams[z].from = i;
        // streams[z].len = streams[x].len + streams[y].len;
      }
      i++;
    }
  }
  queue<int> Q;
  Q.emplace(0);
  while (!Q.empty()) {
    auto u = Q.front();
    Q.pop();
    auto &[len, from, to] = streams[u];
    if (to == -1)
      continue;
    sum[to] += len;
    num[to]++;
    if (num[to] == 1 && get<0>(node[to]) == 'S') {
      auto &[type, x, y, z] = node[to];
      assert(x == u && sum[to] == len);
      streams[y].len = (len + 1) / 2;
      streams[z].len = len - streams[y].len;
      Q.emplace(y);
      Q.emplace(z);
    } else if (num[to] == 2) {
      auto &[type, x, y, z] = node[to];
      assert(x == u || y == u);
      streams[z].len = sum[to];
      Q.emplace(z);
    }
  }
  function<void(int, int)> cal = [&](int u, int pos) {
    if (pos > streams[u].len) {
      cout << "none\n";
      return;
    }
    if (u == 0) {
      cout << pos << '\n';
      return;
    }
    int fr = streams[u].from;
    if (fr == -1) {
      cout << "none\n";
      return;
    }
    const auto &[type, x, y, z] = node[fr];
    if (type == 'S') {
      assert(y == u || z == u);
      if (y == u) {
        cal(x, pos * 2 - 1);
      } else {
        cal(x, pos * 2);
      }
    } else {
      assert(z == u);
      int alter_len = 2 * min(streams[x].len, streams[y].len);
      if (pos <= alter_len) {
        if (pos % 2 == 1) {
          cal(x, (pos + 1) / 2);
        } else {
          cal(y, pos / 2);
        }
      } else {
        assert(streams[x].len != streams[y].len);
        if (streams[x].len > streams[y].len) {
          cal(x, pos - alter_len / 2);
        } else {
          cal(y, pos - alter_len / 2);
        }
      }
    }
  };
  while (q--) {
    int x, k;
    cin >> x >> k;
    x--;
    cal(x, k);
  }
}