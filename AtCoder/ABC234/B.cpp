#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
void solve() {
	ll n;
	cin >> n;
	vector<pii> x(n);
	vector<ll> dis;
	for (auto &i : x) {
		cin >> i.first >> i.second;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ll d = (x[i].first - x[j].first) * (x[i].first - x[j].first) +
				   (x[i].second - x[j].second) * (x[i].second - x[j].second);
			dis.emplace_back(d);
		}
	}
	sort(dis.begin(), dis.end(), greater<ll>());
	printf("%.10lf", sqrt(dis[0]));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin>>_;
	while (_--) {
		solve();
	}
}