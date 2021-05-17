#include <bits/stdc++.h>
using namespace std;
int a[6];
string s[6];
map<string,int>mp;
int main(){
    mp["purple"]=0;
    mp["green"]=1;
    mp["blue"]=2;
    mp["orange"]=3;
    mp["red"]=4;
    mp["yellow"]=5;
    s[0]="Power";
    s[1]="Time";
    s[2]="Space";
    s[3]="Soul";
    s[4]="Reality";
    s[5]="Mind";
    int n;
    cin>>n;
    for(int i = 1 ; i<= n ; i++){
        string tmp;
        cin>>tmp;
        a[mp[tmp]]=1;
    }
    cout<<6-n<<"\n";
    for(int i = 0 ; i<6 ; i++){
        if(a[i]==0){
            cout<<s[i]<<"\n";
        }
    }
}