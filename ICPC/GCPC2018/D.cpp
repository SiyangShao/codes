#include <bits/stdc++.h>
using namespace std;
int n;
int maxi = 0x3f3f3f3f, mini;
int b[1000010];
int main() {
    cin>>n;
    for(int i =1  ; i<=n;i++){
        cin>>b[i];
    }
    int tmp = 0;
    for(int i = 1 ; i<= n ; i++){
        tmp = b[i] - tmp;
        if(i%2!=0){
            maxi = min(maxi , tmp);
        }else{
            mini = max(mini , -tmp);
        }
        // cout<<maxi<<" "<<mini<<"\n";
    }
    if(maxi >= mini){
        cout<<maxi - mini + 1;
    }else{
        cout<<0;
    }
}