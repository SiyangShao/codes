#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	a.push_back({});
	a.push_back({1, 1});
	a.push_back({1, 1, 1, 2});
	a.push_back({1, 1, 2, 2});
	a.push_back({1, 1, 1, 2, 2, 3});
	a.push_back({1, 1, 1, 2, 3, 3});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4});
	a.push_back({1, 1, 2, 2, 4, 4});
	a.push_back({1, 1, 1, 2, 3, 3, 3, 6});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6});
	a.push_back({1, 1, 1, 2, 2, 3, 3, 5, 5, 8});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10});
	a.push_back({1, 1, 2, 2, 4, 4, 8, 8});
	a.push_back({1, 1, 2, 2, 4, 4, 1, 8, 8, 9});
	a.push_back({1, 1, 1, 2, 3, 3, 3, 6, 9, 9});
	a.push_back({1, 1, 1, 2, 1, 3, 4, 4, 3, 8, 8, 11});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 7, 14});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 11, 11});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 3, 10, 10, 13});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6, 12, 12});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10, 10, 15});
	a.push_back({1, 1, 1, 2, 2, 3, 3, 5, 5, 8, 13, 13});
	a.push_back({1, 1, 1, 2, 3, 3, 3, 6, 9, 9, 9, 18});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 14, 14});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 7, 11, 11, 18});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10, 15, 15});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 3, 14, 14, 17});
	a.push_back({1, 1, 2, 2, 4, 4, 8, 8, 16, 16});
	a.push_back({1, 1, 2, 2, 4, 4, 8, 8, 1, 16, 16, 17});
	a.push_back({1, 1, 2, 2, 4, 4, 1, 8, 8, 9, 17, 17});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 7, 14, 14, 21});
	a.push_back({1, 1, 1, 2, 3, 3, 3, 6, 9, 9, 18, 18});
	a.push_back({1, 1, 1, 2, 2, 3, 3, 5, 8, 8, 5, 16, 16, 21});
	a.push_back({1, 1, 1, 2, 1, 3, 4, 4, 3, 8, 8, 11, 19, 19});
	a.push_back({1, 1, 1, 2, 2, 3, 3, 5, 5, 8, 13, 13, 13, 26});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 20, 20});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 1, 20, 20, 21});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 7, 14, 21, 21});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 3, 20, 20, 23});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 11, 11, 22, 22});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10, 15, 15, 15, 30});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 3, 10, 10, 13, 23, 23});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 3, 7, 10, 10, 7, 20, 20, 27});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6, 12, 12, 24, 24});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6, 12, 12, 1, 24, 24, 25});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10, 10, 15, 25, 25});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6, 12, 12, 3, 24, 24, 27});
	a.push_back({1, 1, 1, 2, 2, 3, 3, 5, 5, 8, 13, 13, 26, 26});
	a.push_back({1, 1, 1, 2, 2, 3, 1, 5, 6, 6, 12, 12, 5, 24, 24, 29});
	a.push_back({1, 1, 1, 2, 3, 3, 3, 6, 9, 9, 9, 18, 27, 27});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 11, 11, 11, 22, 22, 33});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 14, 14, 28, 28});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 14, 14, 1, 28, 28, 29});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 7, 11, 11, 18, 29, 29});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 14, 14, 3, 28, 28, 31});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10, 15, 15, 30, 30});
	a.push_back({1, 1, 1, 2, 2, 3, 2, 5, 7, 7, 14, 14, 5, 28, 28, 33});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 3, 14, 14, 17, 31, 31});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 7, 14, 21, 21, 21, 42});
	a.push_back({1, 1, 2, 2, 4, 4, 8, 8, 16, 16, 32, 32});
	a.push_back({1, 1, 2, 2, 4, 4, 8, 8, 16, 16, 1, 32, 32, 33});
	a.push_back({1, 1, 2, 2, 4, 4, 8, 8, 1, 16, 16, 17, 33, 33});
	a.push_back({1, 1, 1, 2, 1, 3, 4, 4, 8, 8, 16, 16, 3, 32, 32, 35});
	a.push_back({1, 1, 2, 2, 4, 4, 1, 8, 8, 9, 17, 17, 34, 34});
	a.push_back({1, 1, 1, 2, 2, 3, 3, 5, 8, 8, 16, 16, 5, 32, 32, 37});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 7, 14, 14, 21, 35, 35});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 1, 7, 8, 8, 16, 16, 7, 32, 32, 39});
	a.push_back({1, 1, 1, 2, 3, 3, 3, 6, 9, 9, 18, 18, 36, 36});
	a.push_back({1, 1, 1, 2, 3, 3, 3, 6, 9, 9, 18, 18, 1, 36, 36, 37});
	a.push_back({1, 1, 1, 2, 2, 3, 3, 5, 8, 8, 5, 16, 16, 21, 37, 37});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10, 10, 15, 25, 25, 25, 50});
	a.push_back({1, 1, 1, 2, 1, 3, 4, 4, 3, 8, 8, 11, 19, 19, 38, 38});
	a.push_back({1, 1, 2, 2, 1, 4, 4, 5, 9, 9, 18, 18, 5, 36, 36, 41});
	a.push_back({1, 1, 1, 2, 2, 3, 3, 5, 5, 8, 13, 13, 13, 26, 39, 39});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 2, 7, 9, 9, 18, 18, 7, 36, 36, 43});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 20, 20, 40, 40});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 20, 20, 1, 40, 40, 41});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 1, 20, 20, 21, 41, 41});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 20, 20, 3, 40, 40, 43});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 7, 14, 21, 21, 42, 42});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 20, 20, 5, 40, 40, 45});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 10, 10, 3, 20, 20, 23, 43, 43});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 3, 7, 10, 10, 20, 20, 7, 40, 40, 47});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 11, 11, 22, 22, 44, 44});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 11, 11, 22, 22, 1, 44, 44, 45});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10, 15, 15, 15, 30, 45, 45});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 11, 11, 22, 22, 3, 44, 44, 47});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 3, 10, 10, 13, 23, 23, 46, 46});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 7, 7, 3, 14, 14, 17, 31, 31, 31, 62});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 3, 7, 10, 10, 7, 20, 20, 27, 47, 47});
	a.push_back({1, 1, 1, 2, 1, 3, 3, 4, 4, 7, 11, 11, 22, 22, 7, 44, 44, 51});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6, 12, 12, 24, 24, 48, 48});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6, 12, 12, 24, 24, 1, 48, 48, 49});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6, 12, 12, 1, 24, 24, 25, 49, 49});
	a.push_back({1, 1, 1, 2, 3, 3, 6, 6, 12, 12, 24, 24, 3, 48, 48, 51});
	a.push_back({1, 1, 1, 2, 2, 3, 5, 5, 5, 10, 10, 15, 25, 25, 50, 50});
	int m, n;
	cin >> m >> n;
	if (m != 1) {
		cout << "*";
		return 0;
	}
	n--;
	for (auto i : a[n]) {
		cout << 1 << " " << i << "\n";
	}
}