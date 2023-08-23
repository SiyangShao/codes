#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=300013,mod=998244353;
ll a[N];
mt19937 rng(time(0));
ll p[N];
void solve(){
    int k;
    cin>>k;
    for(int i=1;i<=1<<(1+k);i++)cin>>a[i];
    for(int i=1;i<=1<<(1+k);i++)p[i]=p[i-1]^a[i];
    if(k==0){
        cout<<"1 1 2 2\n";
        return;
    }
    map<ll,pair<int,int>>mp;
    while(1){
        remake:
        int u=(int)(rng()%((1<<(k+1))+1)),v=u;
        while(u==v)v=(int)(rng()%((1<<(k+1))+1));
        if(u>v)swap(u,v);
        if(mp.count(p[u]^p[v])){
            auto[x,y]=mp[p[u]^p[v]];
            if(x==u&&y==v)goto remake;
            if(x!=u&&y!=v){
                vector<int>vv={u,v,x,y};
                sort(vv.begin(), vv.end());
                cout<<vv[0]+1<<' '<<vv[1]<<' '<<vv[2]+1<<' '<<vv[3]<<'\n';
                return;
            }else{
                int uu,vv;
                if(x==u)uu=min(y,v),vv=max(y,v);
                if(y==v)uu=min(x,u),vv=max(x,u);
                u=uu,v=vv;
                if(mp.count(0)){
                    auto[x,y]=mp[0];
                    if(x==u&&y==v)goto remake;
                    if(x!=u&&y!=v){
                        vector<int>vv={u,v,x,y};
                        sort(vv.begin(),vv.end());
                        cout<<vv[0]+1<<' '<<vv[1]<<' '<<vv[2]+1<<' '<<vv[3]<<'\n';
                        return;
                    }else if(x==u){
                        vector<int>vv={u,v,y,min(v,y)};
                        sort(vv.begin(),vv.end());
                        cout<<vv[0]+1<<' '<<vv[1]<<' '<<vv[2]+1<<' '<<vv[3]<<'\n';
                        return;
                    }else if(y==v){
                        vector<int>vv={u,v,x,max(u,x)};
                        sort(vv.begin(),vv.end());
                        cout<<vv[0]+1<<' '<<vv[1]<<' '<<vv[2]+1<<' '<<vv[3]<<'\n';
                        return;
                    }
                }else mp[0]={u,v};
            }
        }else mp[p[u]^p[v]]={u,v};
    }
    cout<<-1<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout<<fixed<<setprecision(15);
    int T=1;
    cin>>T;
    while(T--)solve();
}