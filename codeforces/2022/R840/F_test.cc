#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=4e18;
const int N=500500,LOG=20;
int n,m;
vector<int> g[N];
int tot,dfn[N],low[N],bcc,bc[N],top,st[N];
void tarjan(int u,int fa){
	dfn[u]=low[u]=++tot,st[++top]=u;
	int cnt=0;
	for(int v:g[u]){
		if(v==fa){
			++cnt;
			if(cnt>=2)low[u]=min(low[u],dfn[v]);
			continue;
		}
		if(!dfn[v])
			tarjan(v,u),low[u]=min(low[u],low[v]);
		else
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]>=dfn[u]){
		++bcc;
		int v;
		do
			v=st[top],--top,bc[v]=bcc;
		while(v!=u);
	}
}
vector<int> ans[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
		scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	for(int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i,0);
	for(int i=1;i<=n;++i)
		ans[bc[i]].push_back(i);
	printf("%d\n",bcc);
	for(int i=1;i<=bcc;++i){
		// printf("%d ",(int)ans[i].size());
		for(int x:ans[i])
			printf("%d ",x);
		puts("");
	}
}
