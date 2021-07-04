#include <bits/stdc++.h>
using namespace std;
unordered_map<string , vector<int>> a;
int N , M , L;
bool ans[1010];
string tmp;
int main(){
    cin>>N;
    for(int i = 1 ; i<=N ; ++i){
        cin>>L;
        for(int j = 1 ; j<=L ; ++j){
            cin>>tmp;
            a[tmp].push_back(i);
        }
    }
    cin>>M;
    for(int i = 1 ; i<=M ; ++i){
        cin>>tmp;
        memset(ans,0,sizeof(ans));
        for(auto j : a[tmp]){
            if(ans[j]==0){
                cout<<j<<" ";
                ans[j] = 1;
            }
        }
        cout<<"\n";
    }
}