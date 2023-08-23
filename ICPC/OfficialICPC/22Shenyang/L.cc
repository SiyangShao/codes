#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
array<ll, 2> p;
array<vector<ll>, 2> attack;
pair<ld, ld> dfs(ll cur, array<vector<ll>, 2> life,
                 array<vector<ll>, 2> chance) {
  ll enemy = cur ^ 1;
  ll enemy_num = 0, my_num = 0;
  for (ll i = 0; i < p[enemy]; ++i) {
    if (life[enemy][i] > 0) {
      enemy_num++;
    }
  }
  for (ll i = 0; i < p[cur]; ++i) {
    if (life[cur][i] > 0) {
      my_num++;
    }
  }
  if (enemy_num == 0 && my_num == 0) {
    return {0, 1};
  } else if (enemy_num == 0) {
    return {enemy, 0};
  } else if (my_num == 0) {
    return {cur, 0};
  }
  ll cur_attack_chance = 1e16;
  for (int i = 0; i < p[cur]; ++i) {
    if (life[cur][i] > 0) {
      cur_attack_chance = min(cur_attack_chance, chance[cur][i]);
    }
  }
  ll attack_id = 0;
  for (int i = 0; i < p[cur]; ++i) {
    if (life[cur][i] > 0) {
      if (chance[cur][i] == cur_attack_chance) {
        attack_id = i;
        break;
      }
    }
  }
  chance[cur][attack_id]++;
  ld win = 0, peace = 0;
  for (int i = 0; i < p[enemy]; ++i) {
    if (life[enemy][i] > 0) {
      life[enemy][i] -= attack[cur][attack_id];
      life[cur][attack_id] -= attack[enemy][i];
      auto [w, pe] = dfs(cur ^ 1, life, chance);
      win += w / (ld)enemy_num;
      peace += pe / (ld)enemy_num;
      life[enemy][i] += attack[cur][attack_id];
      life[cur][attack_id] += attack[enemy][i];
    }
  }
  return {win, peace};
}
auto solve() {
  cin >> p[0] >> p[1];
  attack[0].resize(p[0]), attack[1].resize(p[1]);
  for (auto &i : attack) {
    for (auto &j : i) {
      cin >> j;
    }
  }
  auto life = attack;
  auto chance = attack;
  for (auto &i : chance) {
    for (auto &j : i)
      j = 0;
  }
  if (p[0] < p[1]) {
    auto [w, pe] = dfs(1, life, chance);
    ld lose = 1 - w - pe;
    cout << fixed << setprecision(16) << w << "\n"
         << lose << "\n"
         << pe << "\n";
  } else if (p[0] > p[1]) {
    auto [w, pe] = dfs(0, life, chance);
    ld lose = 1 - w - pe;
    cout << fixed << setprecision(16) << w << "\n"
         << lose << "\n"
         << pe << "\n";
  } else {
    auto [w1, pe1] = dfs(1, life, chance);
    auto [w2, pe2] = dfs(0, life, chance);
    ld w = (w1 + w2) / 2, pe = (pe1 + pe2) / 2;
    ld lose = 1 - w - pe;
    cout << fixed << setprecision(16) << w << "\n"
         << lose << "\n"
         << pe << "\n";
  }
}
auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int _ = 1;
  // cin >> _;
  while (_--) {
    solve();
  }
}