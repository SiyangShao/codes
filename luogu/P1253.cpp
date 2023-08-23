#include <bits/stdc++.h>
using namespace std;
struct a{
    long long i;
    long long d;
}b[10000];
long long n;
bool cmp(a x , a y){
    return x.d>y.d;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i = 1 , t1 ,t2 ; i<= n ; i++){
        cin>>t1>>t2;
        b[i].i=i;
        b[i].d=t1*t2;
    }
    sort(b+1,b+1+n,cmp);
    for(long long i = 1 ;i<= n ; i++){
        cout<<b[i].i;
        if(i!=n){
            cout<<" ";
        }else{
            cout<<"\n";
        }
    }
}