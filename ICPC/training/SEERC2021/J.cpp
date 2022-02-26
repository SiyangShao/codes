#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
string s;
vector<int> A, B, C;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> N >> s;
	for (int i = 0; i < N * 2; ++i) {
		if (s[i] == 'A') {
			A.emplace_back(i);
		} else if (s[i] == 'B') {
			B.emplace_back(i);
		} else {
			C.emplace_back(i);
		}
	}
	int a = A.size(), b = B.size(), c = C.size();
	int x = a + b - c, y = a + c - b, z = b + c - a;
	if (x % 2 == 1 || y % 2 == 1 || z % 2 == 1 || x < 0 || y < 0 || z < 0) {
		cout << "NO\n";
		return 0;
	}
	x /= 2, y /= 2, z /= 2;
	// "AB": x, "AC": y, "BC": z
	int cnt = 0;
	vector<int> Crest;
	vector<pair<int, int>> ans;
	for (int i = 0; i < z; ++i) {
		while (cnt < c && B[i] > C[cnt]) {
			Crest.emplace_back(C[cnt]);
			cnt++;
		}
		if (cnt == c) {
			cout << "NO\n";
			return 0;
		}
		ans.push_back({B[i], C[cnt]});
		cnt++;
	}
	for (int i = cnt; i < c; ++i) {
		Crest.emplace_back(C[i]);
	}
	cnt = a - 1;
	vector<int> Arest;
	for (int i = b - 1; i >= z; --i) {
		while (cnt >= 0 && A[cnt] > B[i]) {
			Arest.emplace_back(A[cnt]);
			cnt--;
		}
		if (cnt == -1) {
			cout << "NO\n";
			return 0;
		}
		ans.push_back({A[cnt], B[i]});
		cnt--;
	}
	for (int i = cnt; i >= 0; --i) {
		Arest.emplace_back(A[i]);
	}
	reverse(Arest.begin(), Arest.end());
	assert(Arest.size() == Crest.size());
	for (int i = 0; i < Arest.size(); ++i) {
		if (Arest[i] > Crest[i]) {
			cout << "NO\n";
			return 0;
		}
		ans.push_back({Arest[i], Crest[i]});
	}
	cout << "YES\n";
	for (auto &&[x, y] : ans) {
		cout << x + 1 << " " << y + 1 << "\n";
	}
}
