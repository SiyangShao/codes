#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto check_valid(string &s) {
  if (s.length() > 1 && s[0] == '0')
    return false;
  return true;
}
auto check_single(string &s1, string &s2) {
  if (s2 == "try") {
    return s1 == "1";
  } else {
    return s1 != "1";
  }
}
bool div(string &s, int p, int q, int m) {
  ll solved = 0, penalty = 0;
  string solved_str = s.substr(0, p + 1);
  string penalty_str = s.substr(p + 1, q - p);
  if (!check_valid(solved_str) || !check_valid(penalty_str))
    return false;
  solved = stoll(solved_str);
  penalty = stoll(penalty_str);
  if (solved > m) {
    return false;
  }
  // divide the rest by tries
  vector<pair<string, string>> comp;
  string number = "", cur = "";
  for (int i = q + 1; i < s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      if (cur != "") {
        comp.emplace_back(number, cur);
        cur = "";
        number = "";
      }
      number += s[i];
    } else {
      cur += s[i];
    }
  }
  if (cur != "") {
    comp.emplace_back(number, cur);
    cur = "";
    number = "";
  }
  vector<tuple<string, string, string>> ans(comp.size());
  ll sum = 0, sol = 0;
  auto dfs = [&](auto self, auto layer) -> bool {
    if (layer == comp.size()) {
      if (sum == penalty && sol == solved) {
        return true;
      } else {
        return false;
      }
    }
    auto [num, cur] = comp[layer];
    // 1. not solved
    if (check_single(num, cur) && self(self, layer + 1)) {
      ans[layer] = {"n", num, cur};
      return true;
    }
    sol++;
    for (int i = 1; i < (int)num.size(); i++) {
      string t1 = num.substr(0, i);
      string t2 = num.substr(i);
      if (!check_valid(t1) || !check_valid(t2)) {
        continue;
      }
      if (!check_single(t2, cur)) {
        continue;
      }
      ll time1 = stoll(t1);
      ll time2 = stoll(t2);
      if (time1 >= 300 || time2 > 100) {
        continue;
      }
      sum += time1 + (time2 - 1) * 20;
      if (self(self, layer + 1)) {
        ans[layer] = {t1, t2, cur};
        return true;
      }
      sum -= time1 + (time2 - 1) * 20;
    }
    sol--;
    return false;
  };
  if (dfs(dfs, 0)) {
    cout << solved_str << " " << penalty_str;
    for (auto [a, b, c] : ans) {
      if (a != "n")
        cout << " " << a << " " << b << " " << c;
      else
        cout << " " << b << " " << c;
    }
    cout << "\n";
    return true;
  }
  return false;
}
auto check(string &s, int m) {
  int ed = 0;
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == 't') {
      ed = i - 1;
      break;
    }
  }
  for (int i = 0; i < ed; i++) {
    for (int j = i + 1; j < ed; j++) {
      if (div(s, i, j, m)) {
        return;
      }
    }
  }
}
auto solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    check(s, m);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n = 1;
  // cin >> n;
  while (n--) {
    solve();
  }
}
