#include <bits/stdc++.h>
using namespace std;
int ans[10010];
int _, n,tmp,pos,maxi;
inline int ask(int t, int i, int j, int x) {
	printf("? %d %d %d %d\n", t, i, j, x);
	int num;
	fflush(stdout);
	scanf("%d", &num);
	return num;
}
inline void output() {
	printf("!");
	for (int i = 1; i <= n; ++i) {
		printf(" %d", ans[i]);
		ans[i] = 0;
	}
	printf("\n");
	fflush(stdout);
}
int main() {
	scanf("%d", &_);
	while (_--) {
		scanf("%d", &n);
		tmp = n - 1 , pos=1 , maxi=0;
		for (int i = 1, j = n; i <= j; ++i, --j) {
            maxi = ask(1,i,j,tmp);
            if(maxi==n){
                pos = j;
                ans[pos]=n;
                break;
            }
            if(maxi==n-1){
                maxi = ask(1,j,i,tmp);
                if(maxi==n){
                    pos = i;
                    ans[pos]=n;
                    break;
                }
            }
		}
        for(int i = 1 ; i<=n ; ++i){
            if(i==pos) continue;
            maxi = ask(2,i,pos,1);
            ans[i]=maxi;
        }
        output();
	}
}