
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
auto main()->int{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

int n,m,q;
cin >> n >> m >> q;
vector< vector<ii> > graph ( n+2, vector<ii>());
for(int i =0;i<m;i++){
int u,v,w;
cin >> u >> v >> w;
graph[u].emplace_back(v,w);
//graph[v].emplace_back(u,w);
}

while(q--){
    int x1,x2,x;
    cin >> x1 >> x2 >> x;
    vector<ll> dist(n+1, 2e9);
    vector<int> parent(n+1,-1);
    priority_queue<ii, vector<ii>, greater<ii> > pq;

    dist[x1]=x;
    pq.push(ii(x,x1));

    while(!pq.empty()){
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if(dist[u]!=d) continue;
        //cout << graph[u].size() << " " << u << "\n";
        for(int i=0; i< graph[u].size();i++){
            
            int v= graph[u][i].first, w = graph[u][i].second + x;

            if(dist[v] > dist[u] +w){
                parent[v]=u;
                dist[v] = dist[u]+ w;
                pq.push(ii(dist[v],v));
            }
        }
    }
    if(dist[x2]==2e9) cout << "-1\n";
    else cout << dist[x2] << "\n";
}

}
