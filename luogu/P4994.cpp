#include <bits/stdc++.h>
using namespace std;
int main(){
    int m , now = 2 , last = 1 , last2=1 , i = 2;
    cin>>m;
    while(!(now%m==1&&last%m==0)){
        last2 = last;
        last = now;
        now = (last+last2)%m;
        i++;
    }
    cout<<i<<endl;
}