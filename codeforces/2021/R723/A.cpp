#include <bits/stdc++.h>
using namespace std;
int t , n;
int a[51];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 1 , j ; i<=2*n ; i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+2*n);
        for(int i = 1 , j = 2*n ; i<j ; i++ , j--){
            printf("%d %d ",a[i],a[j]);
        }
        printf("\n");
    }
}