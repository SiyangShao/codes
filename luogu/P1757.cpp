#include <bits/stdc++.h>
using namespace std;
int m , n , g;
int f[1001];
vector<int>c[1001];
vector<int>v[1001];
int main(){
    cin>>m>>n;
    for(int i = 0 , t1 , t2 ,t3 ; i < n ; i++){
        cin>>t1>>t2>>t3;
        c[t3].push_back(t1);
        v[t3].push_back(t2);
        g = max(g,t3);
    }
    for(int i = 1 ; i <= g ; i++ ){
        for(int j = m ; j > 0 ; j--){
            for(int k = 0 ; k < c[i].size() ; k++){
                if(j >= c[i][k]){
                    f[j]=max(f[j],f[j-c[i][k]]+v[i][k]);
                }
            }
        }
    }
    cout<<f[m]<<"\n";
}