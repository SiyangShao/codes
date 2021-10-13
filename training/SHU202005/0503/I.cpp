#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, fa[200010], fb[200010], n;
int fas[200010] , fbs[200010],ans;
void init() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		fb[i] = i;
	}
}
int finda(int x) {
	if (x != fa[x]) {
		fa[x] = finda(fa[x]);
	}
	return fa[x];
}
void uniona(int x, int y) {
	x = finda(x);
	y = finda(y);
	fa[x] = y;
}
int findb(int x) {
	if (x != fb[x]) {
		fb[x] = findb(fb[x]);
	}
	return fb[x];
}
void unionb(int x, int y) {
	x = findb(x);
	y = findb(y);
	fb[x] = y;
}
signed main(){
    cin>>n;
    init();
    for(int i =1 ,j,k,l; i<n ; i++){
        cin>>j>>k>>l;
        if(l==0){
            uniona(j,k);
        }else{
            unionb(j,k);
        }
    }
    for(int i = 1 ; i<=n ; i++){
        fas[finda(i)]++;
        fbs[findb(i)]++;
    }
    for(int i = 1 ; i<=n ; i++){
        int a = finda(i) , b = findb(i);
        // cout<<a<<":"<<fas[a]<<" "<<b<<":"<<fbs[b]<<"\n";
        ans += fas[a]-1+ fbs[b] -1;
        if(fas[a]>1&&fbs[b]>1){
            ans+=(fas[a]-1)*(fbs[b]-1);
        }
    }
    cout<<ans<<"\n";
}