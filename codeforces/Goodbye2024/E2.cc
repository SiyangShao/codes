#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
  int n;
  cin >> n;
  vector<vector<int>> E(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> special(n), leaf(n);
  ll leafnum = 0;
  for (int i = 0; i < n; i++) {
    if (E[i].size() == 1) {
      leaf[i] = 1;
      leafnum++;
      for (auto v : E[i]) {
        special[v] = 1;
      }
    }
  }
  // set all leaf to not special
  for (int i = 0; i < n; i++) {
    if (leaf[i]) {
      special[i] = 0;
    }
  }
  // case 1: all leaf-nonleaf
  ll base = leafnum * (n - leafnum);
  cout << leafnum << " " << base << endl;
  // find all non special and non leaf point
  ll normal = n - leafnum - count(special.begin(), special.end(), 1);
  // if a point go anywhere is speical or leaf, it can be q
  for (int i = 0; i < n; i++) {
    bool can = true;
    for (auto v : E[i]) {
      if (special[v] || leaf[v]) {
        continue;
      } else {
        can = false;
        break;
      }
    }
    if (special[i]) {
      cout << i + 1 << " SPECIAL!\n";
    }
    if (leaf[i]) {
      cout << i + 1 << " LEAF!\n";
    }
    if (!special[i] && !leaf[i]) {
      cout << i + 1 << " NORMAL!\n";
    }
    if (can && !leaf[i]) {
      cout << i + 1 << " CAN!\n";
      if (!special[i] && !leaf[i]) {
        base += normal - 1;
      } else {
        base += normal;
      }
    }
  }
  cout << base << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
