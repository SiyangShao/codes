#include <bits/stdc++.h>
using namespace std;
long long _ , a , b,tmp;
int main(){
    scanf("%lld",&_);
    while(_--){
        scanf("%lld%lld",&a,&b);
        if(b==1){
            printf("NO\n");
        }else{
            printf("YES\n%lld %lld %lld\n",a*(b-1) , a*(b+1),a*b*2);
        }
    }
}