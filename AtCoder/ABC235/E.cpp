#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1e6 + 1;
int size1[M];
int parent[M];
void make(int v) {
	parent[v] = v;
	size1[v] = 1;
}
int find(int v) {
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = find(parent[v]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (size1[a] < size1[b]) {
			swap(a, b);
		}
		parent[b] = a;
		size1[a] += size1[b];
	}
}
void solve() {
	int n, m, q;
	cin >> n >> m >> q;
	vector<pair<int, vector<int>>> v1;
	for (int i = 1; i <= n; i++) {
		make(i);
	}
	for (int i = 0; i < m; i++) {
		int num1, num2, num3;
		cin >> num1 >> num2 >> num3;
		v1.push_back({num3, {num1, num2, 1, 0}});
		// Union(num1,num2);
	}
	for (int i = 0; i < q; i++) {
		int num1, num2, num3;
		cin >> num1 >> num2 >> num3;
		v1.push_back({num3, {num1, num2, -1, i}});
		// Union(num1,num2);
	}
	vector<int> fans(q, 0);
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++) {
		if (find(v1[i].second[0]) == find(v1[i].second[1])) {
			if (v1[i].second[2] == -1) {
				fans[v1[i].second[3]] = -1;
			}
			continue;
		} else if (v1[i].second[2] == 1) {
			Union(v1[i].second[0], v1[i].second[1]);
		} else {
			fans[v1[i].second[3]] = 1;
		}
	}
	for (auto e : fans) {
		if (e == 1) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}