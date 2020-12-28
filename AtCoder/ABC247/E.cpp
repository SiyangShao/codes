#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main() -> int {
    int N, MAX, MIN;
    cin >> N >> MAX >> MIN;
    ll ans{0};
    ll min_pos{-1}, max_pos{-1}, left_pos{-1};
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == MIN)
            min_pos = i;
        if (a == MAX)
            max_pos = i;
        if (!(MIN <= a && a <= MAX))
            left_pos = i;
        ans += max(0LL, min(min_pos, max_pos) - left_pos);
    }
    cout << ans << endl;
}