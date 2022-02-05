#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> q;
vector<int> p;
signed main() {
	cin >> n;
	n /= 2;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n != i*i) {
				q.push_back(i);
				p.push_back(n / i);
			}else{
                q.push_back(i);
            }
		}
	}
	cout << q.size() + p.size() << "\n";
	for (auto i : q) {
		cout << i << " ";
	}
	if(p.size()!=0)for (int i = p.size() - 1; i >= 0; i--) {
		cout << p[i] << " ";
	}
}