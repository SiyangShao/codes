#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int ask(int x) {
  cout << "- " << x << endl;
  int cnt;
  cin >> cnt;
  assert(cnt != -1);
  return cnt;
}
void answer(int x) { cout << "! " << x << endl; }
auto solve() {
  int cnt;
  cin >> cnt;
  // ....1 -> 0: -1
  // ...10 -> 01: 0
  // ..100 -> 011: 1
  int ans = 0, cur_bit = 0, sure = 0, res = cnt, prev = cnt;
  while (res) {
    int x = ask(1 << cur_bit);
    int dif = x - prev;
    cur_bit += dif + 1;
    ans += 1 << cur_bit;
    cur_bit++;
    prev = x;
    res--;
  }
  answer(ans);
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}