    #include <algorithm>
    #include <iostream>
    #include <vector>
    #include <set>
    using ll = long long;
    using namespace std;
    const char EOLN = '\n';
    int n;
    vector<vector<int>> a;
    set<int> ids;
    int main()
    {
      cin >> n;
      for (int i = 0; i < n; i++)
      {
        int x, y;
        cin >> x >> y;
        a.emplace_back(vector<int>{x, y, i});
      }
      for (int k = 0; k < 2; k++)
      {
        sort(a.begin(), a.end());
        for (int i = 0; i < 2; i++)
        {
          ids.emplace(a[i][2]);
          ids.emplace(a[n - 1 - i][2]);
        }
        for (auto &v : a)
          swap(v[0], v[1]);
      }
      vector<pair<int, int>> b;
      for (auto v : a)
        if (ids.count(v[2]) != 0)
          b.emplace_back(v[0], v[1]);
      vector<ll> d;
      for (int i = 0; i < b.size(); i++)
        for (int j = i + 1; j < b.size(); j++)
          d.emplace_back(max(abs(b[i].first - b[j].first), abs(b[i].second - b[j].second)));
      sort(d.begin(), d.end());
      cout << d[d.size() - 2] << endl;
      return 0;
    }