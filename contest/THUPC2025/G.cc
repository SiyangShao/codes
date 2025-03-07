#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define ALL(x) begin(x), end(x)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)

using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

const ll INF = 1e9;
const ll EPS = 1e-9;
const ll MOD = 1e9 + 7;

void solve() {
  string s;
  cin >> s;

  int w = 0, m = 0;
  int st = 0;
  while (st != s.size() && s[st] == 'X') {
    st++;
  }
  if (st == s.size()) {
    cout << "Draw\n";
    return;
  }

  int fi = s.find('X', st);
  int num[] = {0, 0, 0, 0, 0};
  while (fi != -1) {

    bool hasw = false, hasm = false;
    rep(i, st, fi) {
      if (s[i] == 'W')
        hasw = true;
      if (s[i] == 'M')
        hasm = true;
    }

    if (hasw && hasm) {
      w++, m++;
      if (s[st] != s[fi - 1])
        num[4]++;
      else if (s[st] == 'W')
        num[2]++;
      else
        num[3]++;
    } else if (hasw) {
      num[0]++;
      w++;
    } else {
      num[1]++;
      m++;
    }

    st = fi + 1;
    while (st != s.size() && s[st] == 'X') {
      st++;
    }
    if (st == s.size())
      break;
    fi = s.find('X', st);
  }

  bool hasw = false, hasm = false;
  fi = s.size();
  rep(i, st, fi) {
    if (s[i] == 'W')
      hasw = true;
    if (s[i] == 'M')
      hasm = true;
  }

  if (hasw && hasm) {
    w++, m++;
    if (s[st] != s[fi - 1])
      num[4]++;
    else if (s[st] == 'W')
      num[2]++;
    else
      num[3]++;
  } else if (hasw) {
    num[0]++;
    w++;
  } else if (hasm) {
    num[1]++;
    m++;
  }

  // cout << w << " " << m << '\n';
  // rep(i,0,5) cout << num[i] << " ";
  // cout << "\n";
  int W = num[0] + num[4] + num[2];
  int M = num[1] + num[4] + num[3];
  if (W == M) {
    if (num[3] != 0) {
      cout << "Draw\n";
    } else {
      cout << "Water\n";
    }
  } else if (abs(W - M) <= 1) {
    if (W == M - 1) {
      cout << "Water\n";
    } else {
      // W = M + 1
      if (num[2] != 0) {
        cout << "Draw\n";
      } else {
        cout << "Menji\n";
      }
    }
  } else if (W > M) {
    cout << "Menji\n";
  } else {
    cout << "Water\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
