#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

bool greaterr (int bit[],int minus[]){
    for(int i=32;i>=0;i--){
        if(bit[i]>minus[i]) return true;
        else if(bit[i]<minus[i]) return false;
    }
    return true;
}

void minuss(int bit[], int minus[]){
    int carry=0;
    for(int i=0;i<=32;i++){
        
        if(bit[i]==0){
            bit[i]=minus[i];
            carry=minus[i];
        }
        else if(bit[i]==1 && carry==1){
            bit[i] =minus[i];
        }
        else {
            bit[i]-=(minus[i]+carry);
            carry=0;
        }
    
    }
}

int solve() {

    int bit[33];
    
    int minus[33];
    
    for(int i=0;i<=32;i++){
        minus[i]=1;
        bit[i]=0;
    }

    int n;cin >> n;
    ll a;
    for(int i=0;i<n;i++){
        cin >> a;
        int idx=0;
        while(a!=0){
            bit[idx++]+= a%2;
            a/=2;
        }
    }
    int ans=0;
    for(int modi=32;modi>=0;modi--){
        while(greaterr(bit,minus)){
            //cout << modi;
            minuss(bit,minus);
            ans++;
        }
        minus[modi]=0;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _ ;
    while (_--) {
        cout << solve() << "\n";
    }
}