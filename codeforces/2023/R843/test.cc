#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3e5;
bitset<N> lef, rig;
int main() {
  cout << N << endl;
  for (int i = 0; i < N; ++i) {
    if (i > rand()) {
      lef[i] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    rig = rig >>= 1;
    if (rig[rand() % N])
      ans++;
    rig = lef;
  }
  cout << ans;
}
