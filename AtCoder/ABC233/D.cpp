#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll subarraySum(vector<ll> &nums, ll k) {
	unordered_map<ll, ll> mp;
	mp[0] = 1;
	ll count = 0, pre = 0;
	for (auto &x : nums) {
		pre += x;
		if (mp.find(pre - k) != mp.end()) {
			count += mp[pre - k];
		}
		mp[pre]++;
	}
	return count;
}
void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (auto &i : a) {
		cin >> i;
	}
	cout << subarraySum(a, k);
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