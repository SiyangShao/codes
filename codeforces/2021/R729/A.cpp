#include <bits/stdc++.h>
using namespace std;
int t , n , a[201];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int num = 0;
        for(int i = 1 ; i<=2*n; ++i){
            scanf("%d",&a[i]);
            if(a[i]%2==1){
                num++;
            }
        }
        if(num==n){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}