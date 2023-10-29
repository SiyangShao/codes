#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull reverse(ull x) {
  ull ans = 0;
  for (int i = 0; i < 8; ++i) {
    ull res = (x >> (i * 8)) & 255;
    ans = ans * 256 + res;
  }
  return ans;
}

bool f(ull x) { return reverse(x) > x; }

void encode() {
  int n;
  cin >> n;
  vector<ull> a(1000, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<ull> b, bits;
  for (int i = 0; i < 1000; i += 64) {
    ull cur = 0;
    for (int j = 0; j < 64; ++j) {
      if ((i + j < 1000) && f(a[i + j])) {
        cur |= (1ull << (63 - j));
      }
    }
    b.emplace_back(cur);
    bits.emplace_back(f(cur));
  }
  ull x = 0;
  for (auto e : bits) {
    x = x * 2 + e;
  }
  cout << 1018 << "\n";
  for (auto i : a) {
    cout << i << " ";
  }
  for (auto i : b) {
    cout << i << " ";
  }
  cout << x << " " << n << "\n";
}

void decode() {
  int len;
  cin >> len;
  assert(len == 1018);
  vector<ull> a(1018);
  for (auto &e : a)
    cin >> e;
  ull n = a[1017] > 1000 ? reverse(a[1017]) : a[1017];
  assert(n <= 1000);
  ull x = f(a[1016]) ? a[1016] : reverse(a[1016]);
  vector<bool> bits;
  for (int i = 1000; i <= 1015; ++i) {
    ull bit = (x >> (1015 - i)) & 1;
    if (bit != f(a[i])) {
      a[i] = reverse(a[i]);
    }
    for (int j = 63; j >= 0; --j) {
      bits.emplace_back((a[i] >> j) & 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (bits[i] != f(a[i])) {
      a[i] = reverse(a[i]);
    }
    if (i != 0)
      cout << " ";
    cout << a[i];
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  string mode;
  cin >> mode;
  assert(mode == "encode" || mode == "decode");
  if (mode[0] == 'e') {
    encode();
  } else {
    decode();
  }
}
