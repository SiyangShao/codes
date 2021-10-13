#include <bits/stdc++.h>
using namespace std;
int _ , n , mi,j;
int a[100010];
int main(){
    scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        mi=0x3f3f3f3f;
        for(int i = 1 ;i<=n ; i++){
            scanf("%d",&a[i]);
            if(mi>a[i]){
                mi=a[i];
                j=i;
            }
        }
        printf("%d\n",n-1);
        for(int i = 1 ; i<= n ; i++){
            if(i==j) continue;
            printf("%d %d %d %d\n",i,j,mi+abs(i-j),mi);
        }
    }
}