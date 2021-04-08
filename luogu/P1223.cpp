#include <bits/stdc++.h>
using namespace std;
struct lis{
    int a;
    int b;
};
void selectionsort(lis d[] , int len){
    for(int i = 0 ; i < len ; i++){
        for(int t = i+1 ;t < len ; t++ ){
            if(d[i].a > d[t].a){
                int q,p;
                q = d[t].a;
                p = d[t].b;
                d[t].a = d[i].a;
                d[t].b = d[i].b;
                d[i].a = q;
                d[i].b = p;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    lis t[n];
    int len = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> t[i].a;
        t[i].b = i + 1;
        len++;
    }
    selectionsort(t,len);
    double s=0;
    for(int i = 0 ; i < n ; i++){
        cout<<t[i].b;
        if(i!=n-1)cout<<" ";
        else cout<<endl;
        s += t[i].a*(len-i-1);
    }
    s = double(s / len);
    cout<<fixed<<setprecision(2)<<s<<endl;
    return 0;
}