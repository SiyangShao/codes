#include <bits/stdc++.h>
using namespace std;
int ex_gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = ex_gcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
bool liEu(int a, int b, int c, int& x, int& y) {
  int d = ex_gcd(a, b, x, y);
  if (c % d != 0) return 0;
  int k = c / d;
  x *= k;
  y *= k;
  return 1;
}
int main(){
    int a , b , x , y , c;
    cin>>a>>b;
    c = 1;
    x = 1 , y=0;
    ex_gcd(a,b,x,y);
    cout<<(x%b+b)%b;
}