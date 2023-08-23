#include <bits/stdc++.h>
using namespace std;
int _ , m , n , x;
inline void solve(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    cin>>n>>m>>x;
    for(int i = 1 ; i<= m ; i++){
        q.push({0,i});
    }
    cout<<"YES\n";
    for(int i = 1,tmp ; i<= n ; i++){
        cin>>tmp;
        auto j = q.top();
        q.pop();
        cout<<j.second<<" ";
        q.push({j.first+tmp,j.second});
    }
    cout<<"\n";
}
int main(){
    cin>>_;
    while(_--){
        solve();
    }
}