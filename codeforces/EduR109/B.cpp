#include <bits/stdc++.h>
using namespace std;
int t , n;
int a[51];
bool flag = true;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        flag = true;
        for(int i =1 ; i<=n ; ++i){
            scanf("%d",&a[i]);
            if(a[i]!=i){
                flag = false;
            }
        }
        if(flag){
            printf("0\n");
        }else{
            if(a[1]==1||a[n]==n){
                printf("1\n");
            }else if(a[1]==n&&a[n]==1){
                printf("3\n");
            }else{
                printf("2\n");
            }
        }
    }
}