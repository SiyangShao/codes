#include <bits/stdc++.h>
using namespace std;
int t, n;
int h[200010];
int dic[200010];
inline void init() {
	for (int i = 1; i <= 200000; ++i) {
		h[i] = i;
		dic[i] = 0;
	}
}
int find(int x) {
	if (x != h[x]) {
		h[x] = find(h[x]);
	}
	return h[x];
}
inline void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	h[x] = y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	cin>>t;
	while (t--) {
		vector<pair<int, int>> sam, dif;
		init();
		cin>>n;
		bool flag = false;
        unordered_map<string,int> mp;
        string a , b;
        int ca = 1;
		for (int i = 1,  c; i <= n; ++i) {
			cin>>a>>b>>c;
            if(mp[a]==0){
                mp[a]=++ca;
            }
            if(mp[b]==0){
                mp[b]=++ca;
            }
			if (c == 1) {
				sam.push_back({mp[a],mp[b]});
			} else {
				dif.push_back({mp[a], mp[b]});
			}
		}
		for (auto i : sam) {
			unionSet(i.first, i.second);
		}
		for (auto i : dif) {
			int x = i.first;
			int y = i.second;
			if (find(x) == find(y)) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout<<"NO\n";
		} else {
			cout<<"YES\n";
		}
	}
}