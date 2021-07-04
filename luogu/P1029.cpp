#include <bits/stdc++.h>
using namespace std;
int x, y;
int breakdown(int N) {
	list<int> result;
	for (int i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			while (N % i == 0)
				N /= i;
			result.push_back(i);
		}
	}
	if (N != 1) {
		result.push_back(N);
	}
	return result.size();
}
int main() {
	while (cin >> x >> y) {
		if (y % x != 0) {
			cout << "0\n";
			continue;
		}
		int z = y / x;
		z = breakdown(z);
        cout<<pow(2,z);
	}
}