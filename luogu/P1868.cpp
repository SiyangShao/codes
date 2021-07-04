#include <bits/stdc++.h>
using namespace std;
vector<int> q[3000010];
int f[3000010];
int n, mx;
int main(){
    cin>>n;
    for(int i = 1 ; i<= n ; i++){
        int tmpa , tmpb;
        cin>>tmpa>>tmpb;
        mx=max(mx,tmpb);
        q[tmpb].push_back(tmpa);
    }
    for(int i = 1 ; i<= mx ; i++){
        int size = q[i].size();
        f[i]= f[i-1];
        for(int j = 0 ; j < size ; j++){
            f[i] = max(f[i],f[q[i][j]-1]+i-q[i][j]+1);
        }
    }
    cout<<f[mx]<<"\n";
}