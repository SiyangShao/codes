#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 7;
int prime[MAXN];
bool vis[MAXN];
int _ , a , b , c, d , cnt;
void init() {
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < MAXN; i++) {
		if (!vis[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt && i * prime[j] < MAXN; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) 
				break;
		}
	}
}
int get(int x , int p){
    int ans = 0;
    long long now = p;
    while(x/now){
        ans += x/now;
        now=now*p;
    }
    return ans;
}
void solve(){
    for(int i = 0 ; i < cnt ; i++){
        int p = prime[i];
        int ans1 = get(d,p)+get(a-1,p);
        int ans2 = get(b,p)+get(c-1,p);
        if(ans1<ans2){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}
int main() {
    init();
    scanf("%d",&_);
    while(_--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        solve();
    }
}