#include <bits/stdc++.h>
using namespace std;
const int maxn =100001;
int n , a[100001] , m;
map <int,int>mp;
struct TREE{
    int l ,r;
    int sum;
}tree[maxn<<2];
void pushup(int rt){
    tree[rt].sum=max(tree[rt*2].sum,tree[rt*2+1].sum);
}
void build(int l , int r , int rt){
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r){
        tree[rt].sum=a[l];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
int query(int l ,int r , int rt){
    if(tree[rt].r<l||tree[rt].l>r){
        return 0;
    }
    if(tree[rt].l>=l&&tree[rt].r<=r){
        return tree[rt].sum;
    }
    int ans = 0;
    int mid = (tree[rt].l+tree[rt].r)/2;
    if(l<=mid){
        ans = max(ans,query(l,r,rt*2));
    }
    if(r>mid){
        ans=max(ans,query(l,r,rt*2+1));
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1 ; i<= n ; i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    build(1,n,1);
    cin>>m;
    while(m--){
        int l , r;
        cin>>l>>r;
        int ans = query(l,r,1);
        cout<<mp[ans]<<"\n";
    }
}