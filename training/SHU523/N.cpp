#include <iostream>
#include <string.h>
using namespace std;
int f[100010], c[1010], w[1010], m[1010], val;
void ZeroOnePack(int i) {
	for (int v = val; v >= c[i]; v--) {
		f[v] = max(f[v], f[v - c[i]] + w[i]);  //01背包问题状态转移方程
	}
}
void CompletePack(int i) {
	for (int v = c[i]; v <= val; v++) {
		f[v] = max(f[v], f[v - c[i]] + w[i]);  //完全背包问题
	}
}
void MultiplePack(int i) {	//多重背包问题，二进制区分
	if (c[i] * m[i] >= val) {
		CompletePack(i);
		return;
	}
	int k = 1;
	while (k < m[i]) {
		for (int v = val; v >= k * c[i]; v--) {
			f[v] = max(f[v], f[v - k * c[i]] + k * w[i]);
		}
		m[i] = m[i] - k;
		k = 2 * k;
	}
	for (int v = val; v >= c[i] * m[i]; v--) {
		f[v] = max(f[v], f[v - c[i] * m[i]] + m[i] * w[i]);
	}
}
void MixinPack(int n) {	 //混合背包问题
	for (int i = 1; i <= n; i++) {
		if (m[i] == 1) {
			ZeroOnePack(i);
		} else if (m[i] == 0) {
			//CompletePack(i);
            continue;
		} else if (m[i] > 1) {
			MultiplePack(i);
		}
	}
}
int main(){
    int n;
    while(cin>>val>>n){
        for(int i = 1 ; i<=n ; i++){
            cin>>m[i]>>c[i];
            w[i] = c[i];
        }
        memset(f,0,sizeof(f));
        MixinPack(n);
        int ans = 0;
        for(int i = 1 ; i<=val ; i++){
            ans = max(ans,f[i]);
        }
        cout<<ans<<"\n";
    }
}