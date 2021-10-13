#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 100 * 100000 + 1;
int n, cnt, x, y;
int vis[MAXN];
vector<int> pri;
void init() {
	for (int i = 2; i < MAXN; ++i) {
		if (!vis[i]) {
			pri.push_back(i);
		}
		for (auto j : pri) {
			if (1ll * i * j >= MAXN)
				break;
			vis[i * j] = 1;
		}
	}
}
void judge() {
    //cout<<x<<" "<<y<<"\n";
    if(x==y){
        cout<<"2 2\n";
        return;
    }
    if(x==1||y==1){
        cout<<"impossible\n";
        return;
    }
    int tmp = __gcd(x,y);
    x/=tmp;
    y/=tmp;
	if (!vis[x] && !vis[y]) {
		cout << x << " " << y << "\n";
	} else {
		cout << "impossible\n";
	}
}
signed main() {
	cin >> n;
	init();
    vis[1]=1;
	string a, b;
	while (n--) {
		cin >> a >> b;
		x = 0, y = 0;
		int flag1 = -1, flag2 = -1;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '.') {
				flag1 = i;
				break;
			}
		}
		for (int i = 0; i < b.length(); i++) {
			if (b[i] == '.') {
				flag2 = i;
				break;
			}
		}
		int t = 1;
		for (int i = a.length() - 1; i >= 0; i--) {
			if (a[i] != '.') {
				x += (a[i] - '0') * t;
				t *= 10;
			}
		}
		t = 1;
		for (int i = b.length() - 1; i >= 0; i--) {
			if (b[i] != '.') {
				y += (b[i] - '0') * t;
				t *= 10;
			}
		}
		if ((flag1 == -1 && flag2 == -1) || (flag1 != -1 && flag2 != -1)) {
			if (a.length() - 1 - flag1 > b.length() - 1 - flag2) {
				y *= pow(10, a.length() - 1 - flag1 - b.length() + 1 + flag2);
			} else {
				x *= pow(10, b.length() - 1 - flag2 - a.length() + 1 + flag1);
			}
		} else {
			if (flag1 == -1) {
				x *= pow(10, b.length() - 1 - flag2);
			} else {
				y *= pow(10, a.length() - 1 - flag1);
			}
		}
		// cout << x << " " << y << "\n";
		judge();
	}
}