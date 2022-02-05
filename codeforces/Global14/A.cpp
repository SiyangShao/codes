#include <bits/stdc++.h>
using namespace std;
int _, n, x, ans;
vector<int>a;
int main() {
	cin >> _;
	while (_--) {
        a.clear();
		cin >> n >> x;
        ans=0;
		for (int i = 1, tmp; i <= n; i++) {
			cin >> tmp;
			ans += tmp;
			a.push_back(tmp);
		}
		if (ans == x)
			cout << "NO\n";
		else {
			sort(a.begin(), a.end());
			ans = 0;
			cout << "YES\n";
			for (int i = 0; i < n-1; i++) {
				ans += a[i];
				if (ans == x) {
					swap(a[i],a[i+1]);
                    break;
				}
			}
            for(auto i :a){
                cout<<i<<" ";
            }
			cout << "\n";
		}
	}
}