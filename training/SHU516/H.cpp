#include <bits/stdc++.h>
using namespace std;
int t,n;
char mp[310][310];
int x[3] , o[3] , X , O;
int main(){
	scanf("%d",&t);
	while(t--){
		memset(x,0,sizeof(x));
		memset(o,0,sizeof(o));
		scanf("%d",&n);
		X=0x3f3f3f3f,O=0x3f3f3f3f;
		char tmp;
		getchar();
		for(int i = 1 ; i<= n ; i++){
			for(int j = 1 ; j<=n ; j++){
				tmp = getchar();
				mp[i][j]=tmp;
				if(mp[i][j]=='X'){
					x[(i+j)%3]++;
				}else if(mp[i][j]=='O'){
					o[(i+j)%3]++;
				}
			}
			getchar();
		}
		int xi , oi;
		for(int i = 0 ; i<3 ;i++){
			if(X!=min(X,x[i])){
				X = x[i];
				xi = i;
			}
			if(O!=min(O,o[i])){
				O = o[i];
				oi = i;
			}
		}
		if(xi==oi){
			int absx = 0x3f3f3f3f , absy=0x3f3f3f3f;
			for(int i = 0 ; i<3 ; i++){
				if(i!=xi){
					absx = min(absx , x[i] - X);
				}
				if(i!=oi){
					absy=min(absy,o[i]-O);
				}
			}
			if(absx>absy){
				for(int i = 0 ;i<3 ;i++){
					if(i!=oi){
						if(absy == o[i]-O){
							oi = i;
							break;
						}
					}
				}
			}else{
				for(int i = 0 ;i<3 ;i++){
					if(i!=xi){
						if(absx == x[i]-X){
							xi = i;
							break;
						}
					}
				}
			}
		}
		for(int i = 1 ; i<= n ; i++){
			for(int j = 1 ;j<=n ; j++){
				if(mp[i][j]=='.'){
					printf(".");
				}else if(mp[i][j]=='X'){
					if((i+j)%3==xi){
						printf("O");
					}else{
						printf("X");
					}
				}else if(mp[i][j]=='O'){
					if((i+j)%3==oi){
						printf("X");
					}else{
						printf("O");
					}
				}
			}
			printf("\n");
		}
	}
}