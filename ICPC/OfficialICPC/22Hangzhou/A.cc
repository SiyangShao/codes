#include <bits/stdc++.h>
using namespace std;
#define rt return 0
int ask(int x) {
  cout << "? " << x << endl;
  int y;
  cin >> y;
  return y;
}
void answer(int x) { cout << "! " << x << endl; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  int l = 1, r = n;
  while (true) {
    int pre = 0, lef = 0;
    int cur = ask(l);
    if (cur == pre) {
      answer(l);
      rt;
    }
    pre = cur;
    while (true) {
      int mid = (l + r + 1) / 2;
      cur = ask(mid);
      lef++;
      if (cur == pre) {
        answer(mid);
        rt;
      } else if (cur > pre) {
        l = mid;
        pre = cur;
      } else {
        // between l and mid
        int nl = l + 1, nr = mid - 1;
        while (cur != 0) {
          pre = cur;
          cur = ask(nr);
          if (cur == pre) {
            answer(nr);
            rt;
          }
          nr--;
        }
        l = nl, r = nr;
        break;
      }
    }
  }
}