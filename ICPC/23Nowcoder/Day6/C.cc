#include <bits/stdc++.h>
using namespace std;
using ll = __int128;
void printInt128(__int128 num) {
    if(num < 0){
        std::cout << '-';
        num = -num;
    }
    if (num > 9) {
        printInt128(num/10);
    }
    std::cout << (char)('0' + (num%10));
}
ll cal(ll i, ll x) {
  ll num = x / i;
  if (num == 0)
    return 0;

  return (num * x - i * (1 + num) * num / 2 -
          (x % 2 == 1 ? num / 2 : (num + 1) / 2)) /
             2 +
         num;
}
int main() {
  ll x;
  long long y;
  cin >> y;
  x = y;
  ll ans = 0;
  for (ll i = 5; i <= x; i *= 5) {
    ans += cal(i, x);
  }
  printInt128(ans);
}