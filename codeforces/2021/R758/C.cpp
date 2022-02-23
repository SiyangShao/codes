#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int n;
int a[100010], b[100010];
int vis[100010], can[100010], met[100010];
void solve() {
	int Na = 0, Nai = 0, Nb = 0, Nbi = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] > Na) {
			Na = a[i];
			Nai = i;
		}
		vis[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		if (b[i] > Nb) {
			Nb = b[i];
			Nbi = i;
		}
	}
	can[Nai] = 1;
	can[Nbi] = 1;
	met[Nai] = 1, met[Nbi] = 1;
	Na = min(a[Nai], a[Nbi]);
	Nb = min(b[Nai], b[Nbi]);
	int MA = 0;
	sort(vis + 1, vis + 1 + n,
		 [&](int x, int y) { return max(a[x], b[x]) > max(a[y], b[y]); });
	int NNA = Na, NNB = Nb;
	for (int i = 1; i <= n; ++i) {
		if (met[vis[i]])
			continue;
		if (max(a[vis[i]], b[vis[i]]) < min(Na, Nb)) {
			break;
		}
		NNA = min(a[vis[i]], NNA);
		NNB = min(b[vis[i]], NNB);
		if (a[vis[i]] >= Na || b[vis[i]] >= Nb) {
			can[vis[i]] = 1;
			met[vis[i]] = 1;
			Na = NNA;
			Nb = NNB;
			MA = i;
		}
	}
	for (int i = 1; i <= MA; ++i) {
		can[vis[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		cout << can[i];
		can[i] = 0;
		met[i] = 0;
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}