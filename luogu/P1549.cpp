#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct node{
    int a,b;
    int w;
    bool operator <(const struct node &n)const{
        return w>n.w;
    }
};
priority_queue<node> edge;
vector<node> G[maxn];
bool visted[maxn];
int main(){
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int tmp;
            cin>>tmp;
            if(tmp==0){
                continue;
            }else{
                G[i].push_back(node{i,j,tmp});
                G[j].push_back(node{j,i,tmp});
            }
        }
    }
    visted[1]=true;
    for(int i = 0 ; i < G[1].size() ; i++){
        edge.push(G[1][i]);
    }
    int all=0,cnt=0;
    while(cnt<n-1){
        int w = edge.top().w;
        int q = edge.top().b;
        edge.pop();
        if(visted[q]==true){
            continue;
        }
        visted[q]=true;
        all+=w;
        cnt++;
        for(int i = 0 ; i < G[q].size() ; i++){
            if(!visted[G[q][i].b]){
                edge.push(G[q][i]);
            }
        }
    }
    cout<<all<<"\n";
}