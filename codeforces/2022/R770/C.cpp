#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void solve() {
	int n, k;
	cin >> n >> k;
	if (((n * k) / 2) % k != 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	int cnt = 0;
	for (int i = 2; i <= n * k; i += 2) {
		cout << i << " ";
		cnt++;
		if (cnt % k == 0) {
			cout << "\n";
		}
	}
    for(int i = 1; i<= n *k ; i+=2){
        cout << i << " ";
        cnt++;
        if(cnt % k == 0){
            cout << "\n";
        }
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}