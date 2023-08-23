#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c;
  cin >> c;
  set<string> st;
  while (c--) {
    string s;
    cin >> s;
    st.emplace(s);
  }
  for (int i = 1; i < n; ++i) {
    int c;
    cin >> c;
    set<string> st2;
    set<string> inter;
    while (c--) {
      string s;
      cin >> s;
      st2.emplace(s);
    }
    std::set_intersection(st.begin(), st.end(), st2.begin(), st2.end(),
                          std::inserter(inter, inter.begin()));
    swap(st, inter);
  }
  cout << st.size() << endl;
  for (auto &s : st) {
    cout << s << endl;
  }
}