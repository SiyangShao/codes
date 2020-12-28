#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}

void compute_automaton(string s, vector<vector<int>> &aut) {
  //   s += '#';
  int n = s.size();
  vector<int> pi = prefix_function(s);
  aut.assign(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && 'a' + c != s[i])
        aut[i][c] = aut[pi[i - 1]][c];
      else
        aut[i][c] = i + ('a' + c == s[i]);
    }
  }
}
auto solve() {
  string s;
  cin >> s;
  vector<vector<int>> aut;
  auto pi = prefix_function(s);
  compute_automaton(s, aut);
  int q;
  int n = s.length();
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    s += t;
    int m = t.length();
    for (int i = n; i < n + m; ++i) {
      aut.emplace_back(vector<int>(26, 0));
      for (int c = 0; c < 26; ++c) {
        if ('a' + c != s[i]) {
          aut[i][c] = aut[pi[i - 1]][c];
        } else {
          aut[i][c] = i + ('a' + c == s[i]);
        }
      }
      pi.emplace_back(aut[pi[i - 1]][s[i] - 'a']);
      cout << pi[i] << " ";
    }
    cout << "\n";
    while (m) {
      aut.pop_back();
      pi.pop_back();
      s.pop_back();
      m--;
    }
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}