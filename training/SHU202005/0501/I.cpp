#include <bits/stdc++.h>
using namespace std;
vector<int>q[200000];
int main(){
    int n;
    cin>>n;
    int cm=0;
    for(int i = 1 ,a , c ; i<= n ; i++){
        cin>>a>>c;
        cm=max(cm,c);
        q[c].push_back(a);
    }
    for(int i = 1 ; i<= cm ; i++){
        if(q[i].size()<=1) continue;
        else{
            for(int j = 1 ; j<q[i].size() ; j++){
                if(q[i][j]<q[i][j-1]){
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
    }
    cout<<"YES\n";
}