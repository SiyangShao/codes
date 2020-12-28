#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<cstdio>
#include<algorithm>
#define debug(a) cout<<#a<<"="<<a<<endl;
using namespace std;
const int maxn=1e4+1000;
typedef long long LL;
inline LL read(){LL x=0,f=1;char ch=getchar();	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
return x*f;}
LL ask(LL t,LL i,LL j,LL x){
   cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
   LL num;cin>>num;
   cout.flush();
   return num;
}
LL ans[maxn];
int main(void){
   LL T;cin>>T;
   while(T--){
      LL n;cin>>n;
      for(LL i=0;i<n+10;i++) ans[i]=0;
      LL mxpos=n;
      for(LL i=1;i+1<=n;i+=2){
          LL num=ask(1,i,i+1,n-1);
          if(num==n){
             mxpos=i+1;break;
          }
          if(num==n-1){
             num=ask(1,i+1,i,n-1);
             if(num==n){
                mxpos=i;break;
             }
          }
      }
      ans[mxpos]=n;
      for(LL i=1;i<=n;i++){
          if(i==mxpos) continue;
          LL num=ask(2,i,mxpos,1);
          ans[i]=num;
      }
      cout<<"! ";
      for(LL i=1;i<=n;i++){
          cout<<ans[i]<<" ";
      }
      cout<<endl;
      cout.flush();
   }
   return 0;
}