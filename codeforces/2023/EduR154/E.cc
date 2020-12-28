#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<array<ll, 4>> a(n);
  ll sum = 0;
  for (auto &i : a)
    for (auto &j : i)
      cin >> j, sum += j;
  array<ll, 4> b;
  for (auto &i : b)
    cin >> i, sum += i;
  sum /= n;
}