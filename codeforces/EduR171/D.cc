#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> pre(n + 1);
  for (ll i = 1; i <= n; ++i) {
    cin >> pre[i];
    pre[i] += pre[i - 1];
  }
  auto s = [&](ll l, ll r) {
    assert(l <= r);
    return pre[r] - pre[l - 1];
  };
  const ll sqrtN = (ll)sqrt(n);
  vector<ll> s_val(n + 1);
  vector<ll> len(n + 1, 0);
  for (ll i = 1; i <= n; ++i) {
    s_val[1] += s(1, i);
    len[i] = len[i - 1] + n + 1 - i;
  }
  for (ll i = 2; i <= n; ++i) {
    s_val[i] = s_val[i - 1] - s(i - 1, i - 1) * (n + 2 - i);
  }
  for (ll i = 1; i <= n; ++i) {
    s_val[i] += s_val[i - 1];
  }
  auto cal_len = [&](ll mid) { return len[mid - 1]; };
  // cout << "cal_len:";
  auto f = [&](ll x) {
    return lower_bound(len.begin(), len.end(), x) - len.begin();
  };
  vector<ll> block, block_val;
  auto pre_cal = [&](ll x) {
    if (x == 0) {
      return;
    }
    ll id = f(x);
    if (id < sqrtN) {
      block.emplace_back(x);
    }
    return;
  };
  auto cal = [&](ll x) {
    if (x == 0) {
      return 0LL;
    }
    ll id = f(x);
    auto base = cal_len(id);
    if (id < sqrtN) {
      auto it = lower_bound(block.begin(), block.end(), x) - block.begin();
      return block_val[it];
    }
    x -= base;
    x += id - 1;
    ll ans = s_val[id - 1];
    for (ll i = id; i <= x; ++i) {
      ans += s(id, i);
    }
    return ans;
  };
  ll q;
  cin >> q;
  vector<pair<ll, ll>> query(q);
  for (auto &[l, r] : query) {
    cin >> l >> r;
    pre_cal(r);
    pre_cal(l - 1);
  }
  ll cnt = 0, num = 0;
  sort(block.begin(), block.end());
  block.erase(unique(block.begin(), block.end()), block.end());
  auto it = block.begin();
  for (ll i = 1; i <= sqrtN; i++) {
    for (ll j = i; j <= n; ++j) {
      cnt += s(i, j);
      num++;
      if (it != block.end() && *it == num) {
        block_val.emplace_back(cnt);
        it++;
      }
      if (it == block.end()) {
        break;
      }
    }
  }
  for (auto [l, r] : query) {
    cout << cal(r) - cal(l - 1) << endl;
  }
}
