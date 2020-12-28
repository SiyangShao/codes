#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 50000;
ll N, D;
bool lef[MAXN], rig[MAXN];
int main() {
	cin >> N >> D;
	vector<pair<ll, ll>> a(N + 1);
	for (int i = 1, x, h; i <= N; ++i) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a.begin(), a.end(), [](pair<ll, ll> dx, pair<ll, ll> dy) {
		return dx.second < dy.second;
	});
	priority_queue<pair<ll, ll>> q, p;
	q.push(a[1]);
	for (int i = 2; i <= N; ++i) {
		while ((!q.empty()) && a[i].second - q.top().second > D) {
			q.pop();
		}
		q.push(a[i]);
		if (q.top().first >= 2ll * a[i].first) {
			lef[i] = true;
		}
	}
	p.push(a[N]);
	for (int i = N - 1; i >= 1; --i) {
		while ((!p.empty()) && p.top().second - a[i].second > D) {
			p.pop();
		}
		p.push(a[i]);

		if (p.top().first >= 2ll * a[i].first) {
			rig[i] = true;
		}
	}
	ll num = 0;

	for (int i = 1; i <= N; ++i) {

		if (rig[i] && lef[i]) {
			++num;
		}
	}
	cout << num << "\n";
}