#include <bits/stdc++.h>
using namespace std;
int t , n;
int a[2010];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int> odd;
        for(int i = 1 ; i<=n ; ++i){
            scanf("%d",&a[i]);
            if(a[i]%2==1){
                odd.push_back(a[i]);
            }
        }
        sort(odd.begin(),odd.end());
        int ans = 0;
        for(int i = 1 ; i<=n-odd.size();i++){
            ans+=n-i;
        }
        for(int i = 0 ; i < odd.size(); i++){
            for(int j = i+1 ; j<odd.size();j++){
                if(__gcd(odd[i],odd[j])!=1){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}