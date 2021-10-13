#include <bits/stdc++.h>
using namespace std;
int _ , n;
double a[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>_;
    while(_--){
        cin>>n;
        double sum = 0;
        for(int i = 1 ; i<=n ; i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a+1,a+1+n);
        cout<<fixed<<setprecision(9)<<a[n] + (sum-a[n])/(n-1.0)<<"\n"; 
    }
}