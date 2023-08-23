#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> a;
string ans;
map<pair<int, int>, int> mp;

bool CHE(int begin, int n) {
	vector<int> guess;
	for (int i = begin; i <= begin + n; ++i) {
		guess.emplace_back(a[i]);
		// cout << a[i] << " ";
	}
	// cout << "\n";
	while (guess[0] == a[begin]) {
		int no = 0;
		int now = begin;
		for (int i = 0; i < n; ++i) {
			if (mp[{guess[i], guess[i + 1]}] != 0) {
				if (mp[{guess[i], guess[i + 1]}] == -1) {
					no++;
					now = i;
				}
			} else {
				cout << "c " << guess[i] << " " << guess[i + 1] << endl;
				cin >> ans;
				if (ans[0] == 'n') {
					mp[{guess[i], guess[i + 1]}] = -1;
					mp[{guess[i + 1], guess[i]}] = -1;
					no++;
					now = i;
				} else {
					mp[{guess[i], guess[i + 1]}] = 1;
					mp[{guess[i + 1], guess[i]}] = 1;
				}
			}
			if (no > 2)
				break;
		}
		// cout << now << "\n";
		if (no == 2) {
			cout << "! " << guess[now] << endl;
			return true;
		}
		next_permutation(guess.begin(), guess.end());
	}
	return false;
}
inline void uni(int x, int y,bool t){
    if(t){
        mp[{x,y}]=1;
        mp[{y,x}]=1;
    }
}
bool check(int n) {
	if (n >= k)
		return false;
	// cout << n << " ";
	cout << "r " << a[0] << " " << a[n] << endl;
	cin >> ans;
	if (ans[0] == 'y') {
		return true;
	} else {
		if (n + 1 >= k)
			return false;
		cout << "r " << a[0] << " " << a[n + 1] << endl;
		cin >> ans;
		if (ans[0] == 'y') {
			if (n + n + 1 >= k)
				return true;
			cout << "r " << a[n + 1] << " " << a[n + n + 1] << endl;
			cin >> ans;
			if (ans[0] == 'y') {
				

				return true;
			} else {
				
			}
		}else{
            
        }
	}
	return false;
}
int main() {
	cin >> k;
	a.resize(k);
	for (auto &i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	int n = 2, m = (k - 1) / 2;
	bool flag = false;
	for (; n <= sqrt(k - 1); ++n) {
		if ((k - 1) % n == 0) {
			m = (k - 1) / n;
			if (check(n)) {
				flag = true;
				break;
			}
			// else if (check(m)) {
			// 	swap(m, n);
			// 	flag = true;
			// 	break;
			// }
		}
	}
	if (!flag) {
		cout << "! " << a[0] << "\n";
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		cout << "r " << a[0 + i * n] << " " << a[0 + i * n + n] << endl;
		cin >> ans;
		if (ans[0] == 'n') {
			int now = 0 + i * n;
			if (CHE(now, n)) {
				return 0;
			}
			cout << "! " << a[0 + i * n + n] << endl;
			return 0;
		}
	}
}