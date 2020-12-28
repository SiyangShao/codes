#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 410;
array<array<ll,N>,N> mpij, mpjk, mpik;
array<ll,N> d, ti, tj, tk;
array<ll,N> checkt1, checkt2;
array<ll, N*2> prei, prej, prek;
// pre[i]: time cost when ARRIVE i
ll n;
ll mod(ll x){
    return x >= n ? x - n : x;
}
bool judge(ll i, ll j,array<ll,N>& ti, array<ll,N>& tj ,array<ll,N*2>& prei, array<ll,N*2>& prej){
    for(ll t = i; t < i+n; ++t){
        checkt1[mod(t)] = prei[t] - prei[i];
    }
    for(ll t = j; t < j + n; ++t){
        checkt2[mod(t)] = prej[t] - prej[j];
    }
    for(ll t = 0 ; t < n; ++t){
        ll start1 = checkt1[t];
        ll end1 = start1 + ti[t];
        ll start2 = checkt2[t];
        ll end2 = start2 + tj[t];
        if(start1 >= end2 || end1 <= start2){
            continue;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin>>n;
    for(ll i = 0; i<n; ++i){
        cin>>d[i];
    }
    for(ll i = 0 ; i < n; ++i){
        cin>>ti[i];
    }
    for(ll i = 1; i < n*2; ++i){
        prei[i] = prei[i-1] + ti[mod(i-1)] + d[mod(i-1)]; 
    }
    for(ll i = 0; i < n; ++i){
        cin>>tj[i];
    }
    for(ll i = 1; i < n*2; ++i){
        prej[i] = prej[i-1] + tj[mod(i-1)] + d[mod(i-1)];
    }
    for(ll i = 0 ; i < n; ++i){
        cin>>tk[i];
    }
    for(ll i = 1; i < n*2; ++i){
        prek[i] = prek[i-1] + tk[mod(i-1)] + d[mod(i-1)];
    }
    for(ll i = 0 ; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            if(judge(i,j,ti,tj,prei,prej)){
                mpij[i][j] = 1;
            }else{
                mpij[i][j] = 0;
            }
        }
    }
    for(ll i = 0 ; i < n; ++i){
        for(ll k = 0 ; k < n; ++k){
            if(judge(i,k,ti,tk,prei,prek)){
                mpik[i][k] = 1;
            }else{
                mpik[i][k] = 0;
            }
        }
    }
    for(ll j = 0 ; j < n; ++j){
        for(ll k = 0 ; k < n; ++k){
            if(judge(j,k,tj,tk,prej,prek)){
                mpjk[j][k] = 1;
            }else{
                mpjk[j][k] = 0;
            }
        }
    }
    for(ll i = 0 ; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            for(ll k = 0 ; k < n; ++k){
                if(mpij[i][j] ==1 && mpjk[j][k] == 1&& mpik[i][k] == 1){
                    cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"impossible\n";
}