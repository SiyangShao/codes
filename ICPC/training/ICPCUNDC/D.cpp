#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve(){
    string s;
    cin >> s;
    vector<string> v;
    
    ll pos[103];
    ll neg[103];
    memset(pos,0,sizeof pos);
    memset(neg,0, sizeof neg);
    int n = s.size();
    int coe = 0;
    int sign = 1;
    int exp = 0;
    int expsign = 0;
    bool left = true;
    bool power = false;
    for(int i =0;i<n;i++){
        if(!power && (s[i]=='+'|| s[i]=='-')){
            //cout << sign << " " << coe << " " << expsign <<  " " << exp << "\n";
            if(expsign>=0) {
                pos[exp] += sign*coe;
            }
            else{
                neg[exp]+=sign*coe;
            }
            coe = 0;
            sign = ((s[i]=='+')?1:-1);
            exp = 0;
            expsign = 0;
            left = true;
            power = false;
        }
        else if(power && s[i]=='-'){
            expsign = -1;
            power = false;
        }
        else if(s[i]=='x'){
            if(coe == 0) coe =1;
            exp=1;
            expsign=1;
        }
        else if(s[i]=='^'){
            power=true;
            left= false;
            exp = 0;
            continue;
        }
        else{
            //if(s[i]-'0' <0 || s[i]-'0' >9) cout <<" ASDASD";
            if(left){
                coe*=10;
                coe +=s[i]-'0';
            }
            else{
                exp*=10;
                exp+=s[i]-'0';
            }
        }
        power = false;
    }
    if(expsign>=0) {
        pos[exp] += sign*coe;
    }
    else{
        neg[exp]+=sign*coe;
    }
    

    bool first = true;
    bool output = false;
    for(int i = 100;i>0;i--){
        if(neg[i]==0)continue;
        output =true;
        neg[i]*=-1*i;
        first = false;
        if(neg[i]==-1) cout << "-x^-"<< i+1;
        else if (neg[i]==1) cout << "x^-" << i+1;
        else cout << neg[i] << "x^-" << i+1;
    }
    if(pos[1]!=0){
        if(!first && pos[1]>0) cout << "+";
        output =true;
        first = false;
        cout << pos[1];
    }
    for(int i =2;i<=100;i++){
        if(pos[i]==0) continue;
        if(!first && pos[i]>0) cout << "+";
        first = false;
        output =true;
        pos[i]*=i;
        if(i==2 && pos[i]==1) cout << "x";
        if(i==2) cout << pos[i] << "x";
        else if (pos[i]==1) cout << "x" << i-1;
        else cout << pos[i] << "x^" << i-1;
    }
    if(!output) cout << "0\n";
}
auto main()->int{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while(_--){
        solve();
    }
}