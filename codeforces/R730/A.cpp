#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll t , a , b;
void judge(){
    if(a==b){
        printf("0 0\n");
    }else{
        ll tmp = abs(a-b);
        printf("%lld %lld\n",tmp,min(a%tmp, tmp-a%tmp));
    }
}
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&a,&b);
        judge();
    }
}