#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N];
vector<int> q[N];
int n;
int dp1[N] , dp2[N];
void dfs1(int x , int fa){
    dp1[x] = a[x];
    for(auto i : q[x]){
        if(i!=fa){
            dfs1(i,x);
            dp1[x] += max(0 , dp1[i]);
        }
    }
}
void dfs2(int x , int fa ){
    for(auto i : q[x]){
        if(i!=fa){
            dp2[i] = max(0 , dp1[x]+dp2[x]-max(0,dp1[i]));
            dfs2(i,x);
        }
    }
}
int main(){
    cin>>n;
    for(int i = 1 , tmp ; i<= n ; i++){
        cin>>tmp;
        if(tmp==1){
            a[i] = 1;
        }else{
            a[i] = -1;
        }
    }
    for(int i = 1 , j , k ; i < n ; i++){
        cin>>j>>k;
        q[j].push_back(k);
        q[k].push_back(j);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i = 1 ; i<= n ; i++){
        cout<<dp1[i]+dp2[i]<<" ";
    }
}