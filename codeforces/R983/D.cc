#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
void debug_out() { cerr << endl; }
template <typename T, typename... Args> void debug_out(T first, Args... rest) {
  std::cout << first << " ";
  debug_out(rest...);
}
#else
#define dbg(...) {};
#endif
using namespace std;
using ll = long long;
auto ask(int x, int y) {
  cout << "? " << x << " " << y << endl;
  int res;
  cin >> res;
  return res == 1;
}
auto solve() {
  int n;
  cin >> n;
  queue<int> head;
  vector<int> p(n);
  int cnt = 0;
  for (int i = 2; i < n; ++i) {
    cnt = i;
    if (ask(1, i)) {
      p[i] = 0;
      head.emplace(i);
    } else {
      p[i] = 1;
      head.emplace(i);
      break;
    }
  }
  for (int i = cnt + 1; i < n; ++i) {
    auto x = head.front();
    while (ask(x, i)) {
      head.pop();
      x = head.front();
    }
    p[i] = x;
    head.pop();
    head.emplace(i);
  }
  cout << "! ";
  for (int i = 1; i < n; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
