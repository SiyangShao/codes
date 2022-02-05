#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll saved[25][25][25];//记忆化搜索？递归的多次输入省时间
ll func(ll a , ll b , ll c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    else if(saved[a][b][c]!=0){
        return saved[a][b][c];
    }
    else if(a>20||b>20||c>20){
        saved[a][b][c]=func(20,20,20);
    }
    else if(a<b&&b<c){
        saved[a][b][c] = func(a,b,c-1)+func(a,b-1,c-1)-func(a,b-1,c);
    }
    else{
        saved[a][b][c]=func(a-1,b,c)+func(a-1,b-1,c)+func(a-1,b,c-1)-func(a-1,b-1,c-1);
    }
    return saved[a][b][c];
}
int main(){
    ll a,b,c;
    while(cin>>a>>b>>c){
        if(a==-1&&b==-1&&c==-1){
            return 0;
        }
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
        if(a>20){
            a=21;
        }
        if(b>20){
            b=21;
        }
        if(c>20){
            c=21;
        }
        cout<<func(a,b,c)<<endl;
    }
    return 0;
}