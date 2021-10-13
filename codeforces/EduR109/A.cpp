#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        printf("%d\n",(100)/__gcd(k,100));
    }
}