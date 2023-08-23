#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> evl;
  if (n % 2 == 0) {
    map<int, vector<int>> mp;
    vector<int> a(n + 1);
    for (int i = 1; i < n; ++i) {
      cout << "? " << i << " " << n << endl;
      int val;
      cin >> val;
      a[i] = val;
      mp[val].emplace_back(i);
    }
    int half = n / 2;
    int real = -1;
    for (auto &&[x, v] : mp) {
      if (v.size() >= half) {
        real = x;
        break;
      }
    }
    assert(real != -1);
    for (int i = 1; i < n; ++i) {
      if (a[i] != real) {
        evl.emplace_back(i);
      }
    }
    int dest = 1;
    if (mp[real][0] == 1) {
      dest = 2;
    }
    int x, y;
    cout << "? " << mp[real][0] << " " << dest << endl;
    cin >> x;
    cout << "? " << n << " " << dest << endl;
    cin >> y;
    if (x != y) {
      evl.emplace_back(n);
    }
  } else {
    map<int, vector<int>> mp;
    vector<int> a(n + 1);
    for (int i = 1; i < n; ++i) {
      cout << "? " << i << " " << n << endl;
      int val;
      cin >> val;
      a[i] = val;
      mp[val].emplace_back(i);
    }
    int half = n / 2;
    int real = -1;
    int cnt = 0;
    for (auto &&[x, v] : mp) {
      if (v.size() >= half) {
        real = x;
        cnt++;
      }
    }
    assert(real != -1);
    if (cnt != 2) {
      for (int i = 1; i < n; ++i) {
        if (a[i] != real) {
          evl.emplace_back(i);
        }
      }
      int dest = 1;
      if (mp[real][0] == 1) {
        dest = 2;
      }
      int x, y;
      cout << "? " << mp[real][0] << " " << dest << endl;
      cin >> x;
      cout << "? " << n << " " << dest << endl;
      cin >> y;
      if (x != y) {
        evl.emplace_back(n);
      }
    } else {
      assert(mp.size() == 2);
      int dest = 1;
      if (mp[real][0] == 1)
        dest = 2;
      int x, y;
      cout << "? " << mp[real][0] << " " << dest << endl;
      cin >> x;
      cout << "? " << n << " " << dest << endl;
      cin >> y;
      if (x != y) {
        for (int i = 1; i < n; ++i) {
          if (a[i] == real) {
            evl.emplace_back(i);
          }
        }
      } else {
        for (int i = 1; i < n; ++i) {
          if (a[i] != real) {
            evl.emplace_back(i);
          }
        }
      }
    }
  }
  cout<<"! ";
  cout << evl.size() << " ";
  for(auto i : evl){
    cout << i << " ";
  }
  cout << endl;
}