#include <bits/stdc++.h>
using namespace std;
int _ , n;
int a[101] , sum[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin>>_;
    while(_--){
        cin>>n;
        memset(sum , 0 , sizeof(sum));
        for(int i = 1 ; i<=n ; i++){
            cin>>a[i];
            sum[a[i]]++;
        }
        for(int i = 1 ; i<=100 ; i++){
            if(sum[i]!=0){
                cout<<n-sum[i]<<"\n";
                break;
            }
        }
    }
}