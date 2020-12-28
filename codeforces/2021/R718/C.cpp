#include <bits/stdc++.h>
using namespace std;
int mp[510][510];
int vis[510][510];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> mp[i][i];
		vis[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		vis[0][i] = 1;
		vis[n + 1][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int k = mp[i][i], t = mp[i][i];
		t--;
		int x = i, y = i;
		while (t) {
			if (vis[x - 1][y] == 0) {
				x--;
				vis[x][y] = 1;
				mp[x][y] = k;
			} else if (vis[x][y + 1] == 0) {
				y++;
				vis[x][y] = 1;
				mp[x][y] = k;
			}
			t--;
		}
	}
    for(int i = 1 ; i<= n ; i++){
        for(int j = 1 ; j<= i ; j++){
            cout<<mp[j][i]<<" ";
        }
        cout<<"\n";
    }
}