#include <bits/stdc++.h>
using namespace std;
void show(int n){
    if(n==0){
        return;
    }
    int y;
    for(y=0;y<=15;y++){
        if(pow(2,y)>n){
            y--;
            break;
        }
    }
    if(y==0){
        cout<<"2(0)";
    }
    else if(y==1){
        cout<<"2";
    }
    else{
        cout<<"2(";
        show(y);
        cout<<")";
    }
    if(n!=pow(2,y)){
        cout<<"+";
        show(n-pow(2,y));
    }
}
int main(){
    int n;
    cin>>n;
    show(n);
}