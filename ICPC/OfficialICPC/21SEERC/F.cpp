#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll MAXN = 1e6 + 7;
bitset<MAXN> Reg;
ll N, X, R, P, K;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> N >> X >> R >> P >> K >> s;
	vector<pair<ll, ll>> greedy(N);
	for (int i = 0; i < N; ++i) {
		if (s[i] == '0') {
			greedy[i] = {(N - i) * P, i};
		} else {
			greedy[i] = {(N - i) * (P + R), i};
		}
	}
	sort(greedy.begin(), greedy.end(),
		 [](auto x, auto y) { return x.first > y.first; });
	ll ans = 0;
	for (int i = 0; i < K; ++i) {
		Reg[greedy[i].second] = 1;
	}
	ll p = 0, r = 0;
	for (int i = 0; i < N; ++i) {
		// cout << Reg[i] << " ";
		if (s[i] == '1') {
			r++;
		}
		if (Reg[i]) {
            if(r>0) r--;
			p++;
		}
		ans += p * P - r * R + X;
		// if (Reg[i] && r > 0) {
		// 	r--;
		// }
	}
	cout << ans;
}