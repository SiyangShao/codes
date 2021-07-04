#include <bits/stdc++.h>
using namespace std;
int a[33][33];
int n;
void dfs(int i , int j){
    if(a[i][j]!=0||i<0||j<0||i>=n||j>=n) return;
    a[i][j]=2;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}
int main(){
    cin>>n;
    int i_inti , j_inti;
    bool flag = false, flag2 = true,flag3 = false;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                flag = true;
            }
            if(flag&&flag2&&flag3){
                if(a[i][j]==0){
                    i_inti = i;
                    j_inti = j;
                    flag2 = false;
                }
            }
        }
        if(flag){
            flag3 = true;
        }
        flag = false;
    }
    dfs(i_inti,j_inti);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n; j++){
            cout<<a[i][j];
            if(j!=n-1){
                cout<<" ";
            }
            else{
                cout<<endl;
            }
        }
    }
    return 0;
}