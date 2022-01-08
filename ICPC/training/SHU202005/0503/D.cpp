#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, c, d[N] , d2[N] , d1[N];
vector<int> E[N];
void dfs(int u, int fa) {
	for (int v : E[u]) {
		if (v == fa)
			continue;
		d[v] = d[u] + 1;
		if (d[v] > d[c])
			c = v;
		dfs(v, u);
	}
}
void dfss(int u, int fa) {
	for (int v : E[u]) {
		if (v == fa)
			continue;
		d2[v] = d2[u] + 1;
		if (d2[v] > d2[c])
			c = v;
		dfss(v, u);
	}
}
void dfsss(int u, int fa) {
	for (int v : E[u]) {
		if (v == fa)
			continue;
		d1[v] = d1[u] + 1;
		if (d1[v] > d1[c])
			c = v;
		dfsss(v, u);
	}
}
struct node{
    int x , y;
};
bool cmp(node a , node b){
    return a.y > b.y;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		E[u].push_back(v), E[v].push_back(u);
	}
	dfs(1, 0);
    int lef , rig;
    lef = c;
    dfss(c, 0);
    rig = c;
    dfsss(c,0);
    vector<node> qqq;
    for(int i = 1 ; i<=n ; i++){
        if(i==lef||i==rig) continue;
        node tmp;
        tmp.x=i;
        tmp.y=(d1[i]+d2[i]-d1[c])/2;
        qqq.push_back(tmp);
    }
    sort(qqq.begin(),qqq.end(),cmp);
    int mid = qqq[0].x;
    cout<<(d1[mid]+d2[mid]-d1[c])/2+d1[c]<<"\n";
    cout<<lef<<" "<<rig<<" "<<mid;
	return 0;
}