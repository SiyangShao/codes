#include <bits/stdc++.h>
using namespace std;
int _, n, a[1010];
void solve(int i, int j) {
    printf("1 %d %d\n", i, j);
    printf("2 %d %d\n", i, j);
    printf("1 %d %d\n", i, j);
    printf("1 %d %d\n", i, j);
    printf("2 %d %d\n", i, j);
    printf("1 %d %d\n", i, j);
}
int main(){
    scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        for(int i = 1 ; i<=n ; ++i){
            scanf("%d",&a[i]);
        }
        printf("%d\n",n*3);
        for(int i = 1 ; i<=n ;i+=2){
            solve(i,i+1);
        }
    }
}