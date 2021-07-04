#include <bits/stdc++.h>
using namespace std;
int a[1010][1010] , b[1010][1010],r;
int main(){
    scanf("%d",&r);
    for(int i = 1 ; i<=r ; i++){
        for(int j = 1 ; j<=i ; j++){
            scanf("%d",&a[i][j]);
            b[i][j]+=a[i][j];
        }
    }
    for(int i = r ; i>= 1 ; i--){
        for(int j = i ; j>=1 ; j--){
            b[i][j]=max(b[i+1][j],b[i+1][j+1])+a[i][j];
        }
    }
    printf("%d\n",b[1][1]);
    return 0;
}