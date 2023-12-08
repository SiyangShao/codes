#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n, a;
  cin >> n >> a;
  vector<int> b(n), cnt(n, 0);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (b[i] == 0) {
      cnt[i]++;
      cnt[(i + 1) % n]++;
      cnt[(i + n - 1) % n]++;
    } else {
      res += 3;
    }
  }
  priority_queue<int> pq;
  for (auto i : cnt) {
    pq.emplace(i);
  }
  int can = n - a;
  while (!pq.empty() && can) {
    res += pq.top();
    pq.pop();
    can--;
  }
  cout << res << "\n";
}