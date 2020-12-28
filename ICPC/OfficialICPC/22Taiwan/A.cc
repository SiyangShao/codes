#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<string, string> mp;
void init() {
  mp["UUU"] = mp["UUC"] = "F";
  mp["UUA"] = mp["UUG"] = mp["CUU"] = mp["CUC"] = mp["CUA"] = mp["CUG"] = "L";
  mp["AUU"] = mp["AUC"] = mp["AUA"] = "I";
  mp["AUG"] = "M";
  mp["GUU"] = mp["GUC"] = mp["GUA"] = mp["GUG"] = "V";
  mp["UCU"] = mp["UCC"] = mp["UCA"] = mp["UCG"] = mp["AGU"] = mp["AGC"] = "S";
  mp["CCU"] = mp["CCC"] = mp["CCA"] = mp["CCG"] = "P";
  mp["ACU"] = mp["ACC"] = mp["ACA"] = mp["ACG"] = "T";
  mp["GCU"] = mp["GCC"] = mp["GCA"] = mp["GCG"] = "A";
  mp["UAU"] = mp["UAC"] = "Y";
  mp["CAU"] = mp["CAC"] = "H";
  mp["CAA"] = mp["CAG"] = "Q";
  mp["AAU"] = mp["AAC"] = "N";
  mp["AAA"] = mp["AAG"] = "K";
  mp["GAU"] = mp["GAC"] = "D";
  mp["GAA"] = mp["GAG"] = "E";
  mp["UGU"] = mp["UGC"] = "C";
  mp["UGG"] = "W";
  mp["CGU"] = mp["CGC"] = mp["CGA"] = mp["CGG"] = mp["AGA"] = mp["AGG"] = "R";
  mp["GGU"] = mp["GGC"] = mp["GGA"] = mp["GGG"] = "G";
  mp["UAA"] = mp["UAG"] = mp["UGA"] = "-1";
}
auto solve() {
  string s;
  cin >> s;
  int n = (int)s.length();
  for (int i = 0; i < n; i += 3) {
    auto str = s.substr(i, 3);
    string x = mp[str];
    if (x == "-1") {
      cout << "\n";
      return;
    } else {
      cout << x;
    }
  }
  cout << "\n";
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  init();
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
}