#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define chkmax(x, a) x = max(x, a)

struct Queries {
  int l, r;
  int id;

  Queries(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
};

std::vector<ll> execute(const std::vector<ll> &a,
                        const std::vector<std::pair<ll, ll>> &queries) {
  std::vector<Queries> q;
  for (int i = 0; i < queries.size(); ++i) {
    const auto [l, r] = queries[i];
    if (l <= r) {
      q.emplace_back(l, r, i);
    }
  }
  const int kuai = 700;
  std::sort(q.begin(), q.end(), [&](const Queries &a, const Queries &b) {
    int ll = a.l / kuai, rr = b.l / kuai;
    if (ll != rr) {
      return ll < rr;
    }
    if (ll & 1) {
      return rr > ll;
    } else {
      return ll < rr;
    }
  });
  std::vector<ll> ans(queries.size());
  std::vector<int> tong(a.size() + 2);
  int now_ans = 0;
  auto add = [&](int x) {
    if (tong[x] == 0) {
      now_ans++;
    }
    tong[x]++;
  };
  auto remove = [&](int x) {
    if (tong[x] == 1) {
      now_ans--;
    }
    tong[x]--;
  };
  int now_l = 0, now_r = -1;
  for (const Queries &qq : q) {
    int l = qq.l;
    int r = qq.r;
    while (now_r < r) {
      now_r++;
      add(a[now_r]);
    }
    while (now_l > l) {
      now_l--;
      add(a[now_l]);
    }
    while (now_r > r) {
      remove(a[now_r]);
      now_r--;
    }
    while (now_l < l) {
      remove(a[now_l]);
      now_l++;
    }
    ans[qq.id] = now_ans;
  }
  return ans;
}
void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (auto &e : a)
    cin >> e;

  vector<ll> disc = a;
  vector<ll> ad = a;
  sort(disc.begin(), disc.end());
  for (ll i = 0; i < n; ++i) {
    ad[i] = lower_bound(disc.begin(), disc.end(), ad[i]) - disc.begin();
  }

  vector<ll> prevIdx(n + 2, -1);
  vector<pair<ll, ll>> queries;
  for (ll i = 0; i < n; ++i) { // whole array at the end
    if (a[i] <= n + 1) {
      ll u = prevIdx[a[i]];
      queries.emplace_back(u + 1, i - 1);
      prevIdx[a[i]] = i;
    } else {
      // mex as this is impossible; skip
      queries.emplace_back(0, -1);
    }
  }

  for (ll x = 0; x <= n + 1; ++x)
    if (prevIdx[x] != -1) {
      queries.emplace_back(prevIdx[x] + 1, n - 1);
    }

  // dbg(queries);

  vector<ll> answers = execute(ad, queries);
  // dbg(answers);

  ll ans = -1e18;
  for (ll i = 0; i < n; ++i)
    if (a[i] <= n + 1) {
      chkmax(ans, answers[i] - a[i]);
      // cout << "i = " << i << " " << ans << endl;
    }

  ll idx = n;
  for (ll x = 0; x <= n + 1; ++x)
    if (prevIdx[x] != -1) {
      // queries.emplace_back(prevIdx[x] + 1, n - 1);
      chkmax(ans, answers[idx] - x);
      idx++;
    }
  // last, we consider the whole array;
  set<ll> s;
  for (ll i = 0; i < n; ++i)
    s.emplace(a[i]);
  ll currAns = s.size();
  for (ll i = 1; i <= n + 1; ++i)
    if (s.find(i) == s.end()) {
      currAns -= i;
      break;
    }
  // dbg(currAns);
  chkmax(ans, currAns);

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  // freopen("my.in", "r", stdin);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}