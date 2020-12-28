#include <bits/stdc++.h>
#define int long long
using namespace std;
int H, W;
string mp[510];
int q[1010] , p[1010];
long long binpow(long long a, long long b, long long mod) {
	a %= mod;
	long long res = 1;
	while (b > 0) {
		if (b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>H>>W;
    for(int i = 1 ; i<= H ; i++){
        cin>>mp[i];
        for(int j = 1 ; j<= W ; j++){
            if(mp[i][j-1]=='B'){
                q[i+j] = 1;
            }else if(mp[i][j-1]=='R'){
                p[i+j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 2 ; i<=H+W ; i++){
        if(q[i]==1&&p[i]==1){
            cout<<"0\n";
            return 0;
        }
        if(q[i]==0&&p[i]==0){
            ans++;
        }
    }
    cout<<binpow(2,ans,998244353);
}