#include <bits/stdc++.h>
using namespace std;
int t , n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool flag = false;
        for(int i = 1 ,tmp ; i<=n ; ++i){
            scanf("%d",&tmp);
            if(tmp<0){
                flag = true;
            }
        }
        if(flag){
            printf("NO\n");
        }else{
            printf("YES\n101\n");
            for(int i = 0 ; i<=100;++i){
                printf("%d ",i);
            }
            printf("\n");
        }
    }
}