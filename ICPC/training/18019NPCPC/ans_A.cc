#include<bits/stdc++.h>

#define fi first
#define sd second
#define lson (nd<<1)
#define rson (nd+nd+1)
#define PB push_back
#define mid (l+r>>1)
#define MP make_pair
#define SZ(x) (int)x.size()

using namespace std;

typedef long long LL;

typedef vector<int> VI;

typedef pair<int,int> PII;

inline int read(){
    int res=0, f=1;char ch=getchar();
    while(ch<'0'|ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){res=res*10+ch-'0';ch=getchar();}
    return res*f;
}

const int MAXN = 200'005;

const int MOD = 1000000007;

void addmod(int& a, int b){a+=b;if(a>=MOD)a-=MOD;}
int mulmod(int a, int b){return 1ll*a*b%MOD;}

int st[MAXN][20], lg[MAXN];

int h[MAXN], ans[MAXN], dep[MAXN];

int n, m;

int query(int L, int R){
    int k=lg[R-L+1];
    if(h[st[L][k]]>=h[st[R-(1<<k)+1][k]])return st[L][k];
    else return st[R-(1<<k)+1][k];
}

int dfs(int L, int R, int d){
    if(L>R)return -1;

    int all=0;
    int p=query(L, R);
    dep[p]=d;
    ans[p]=dfs(L,p-1,d+1)+1;
    all=max(all,ans[p]);

    while(p<R){
        int q=query(p+1,R);
        if(h[p]!=h[q])break;

        int t=dfs(p+1,q-1,d+1)+1;
        ans[p]=max(ans[p],t);
        all=max(all,ans[p]);
        dep[q]=d;
        ans[q]=t;
        p=q;
    }

    ans[p]=max(ans[p],dfs(p+1,R,d+1)+1);
    all=max(all,ans[p]);

    return all;
}

int main(){
    n=read();m=read();

    for(int i=1;i<=n;++i)h[i]=read(), st[i][0]=i;
    for(int i=2;i<=n;++i)lg[i]=lg[i/2]+1;

    for(int j=1;j<=20;++j){
        for(int i=1;i+(1<<j)-1<=n;++i){
            if(h[st[i][j-1]]>=h[st[i+(1<<j-1)][j-1]])st[i][j]=st[i][j-1];
            else st[i][j]=st[i+(1<<j-1)][j-1];
        }
    }

    dfs(1,n,0);

    while(m--){
        int l, r;
        l=read();
        r=read();

        if(!r){
            cout<<ans[l]<<endl;
        }else{
            if(h[l]==h[r]){
                cout<<"0"<<endl;
            }else{
                if(h[l]>h[r])swap(l,r);/*ºÃ¶àbug*/
                int t;
                if(l<r)t=query(l,r-1);
                else t=query(r+1,l);

                if(h[t]>=h[r]){
                    cout<<"0"<<endl;
                }else{
                    cout<<dep[l]-dep[r]<<endl;
                }
            }
        }
    }
    for(int i = 1 ; i <= n; ++i){
      cout<<ans[i]<<" "<<dep[i]<<"\n";
    }
    return 0;
}

/*
12 8
2 3 4 4 4 3 3 3 1 2 5 2
3 0
4 0
5 0
7 0
7 11
7 9
11 1
9 12
*/