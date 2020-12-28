#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  string s;
  cin >> s;
  vector<char> vec;
  vec.emplace_back('#');
  for (auto i : s) {
    vec.emplace_back(i);
    vec.emplace_back('#');
  }
  int n = (int)vec.size();
  vector<int> d(n);
  function<bool(int, int)> check = [&](int i, int j) {
    if (vec[i] == 'o' || vec[i] == 's' || vec[i] == 'x' || vec[i] == 'z' ||
        vec[i] == '#') {
      return vec[i] == vec[j];
    }
    switch (vec[i]) {
    case 'b':
      return vec[j] == 'q';
    case 'd':
      return vec[j] == 'p';
    case 'p':
      return vec[j] == 'd';
    case 'q':
      return vec[j] == 'b';
    case 'n':
      return vec[j] == 'u';
    case 'u':
      return vec[j] == 'n';
    default:
      return false;
    }
  };

  int beg = 0;
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    if (i < beg)
      continue;
    int k = (i > r) ? 0 : min(d[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && check(i - k, i + k)) {
      k++;
    }
    d[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
    if (i - d[i] + 1 <= beg) {
      beg = i + d[i];
      vec[beg - 1] = '?';
    }
  }
  if (beg >= n) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}