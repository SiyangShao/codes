#include <bits/stdc++.h>
using namespace std;
int a[1000010],n,_,b[1000010],c[1000010];
int main(){
    scanf("%d",&_);
    while(_--){
        scanf("%d",&n);
        for(int i = 1 ; i<=n ; ++i){
            scanf("%d",&a[i]);
            a[i+n]= a[i];
            b[i+n] = b[i] = 0;
            c[i+n] = c[i] = 0;
        }
        c[n+n+1] = 0 , b[n+n+1] = 0 , b[0] = 0 , c[0] = 0; 
        for(int i = 1 ;i<=n+n;++i){
            b[i]=b[i-1]+a[i];
        }
        for(int i = n+n ; i>=0 ; --i){
            c[i]= c[i+1]+a[i];
        }
        int ans = 0,sum=0;;
        for(int i = 1 ; i<=n ;++i){
            ans += b[i];
        }
        sum = ans;
        for(int i = 2 ; i<=n ;++i){
            ans -= a[i-1]*n;
            ans += b[i+n]-b[i-1];
            sum = min(sum,ans);
        }
        ans = 0;
        for(int i = n+n ; i>n ; --i){
            ans+=c[i];
        }
        for(int i = n+n-1; i>n ; --i){
            ans -= a[i+1]*n;
            ans += c[i-n]-c[i];
            sum = min(sum,ans);
        }
        printf("%d\n",sum);
    }
}