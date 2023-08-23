#include <algorithm>
#include <iostream> //头文件头文件头文件
#include <queue>
#include <vector>
using namespace std;
struct edge { //存边结构体
    int u, v;
};
vector<int> e[100001]; //两个vector刚才已经详细讲过了
vector<edge> s;
bool vis1[100001] = {0}, vis2[100001] = {0}; //标记数组
bool cmp(edge x, edge y) {                   //排序规则
    if (x.v == y.v)
        return x.u < y.u;
    else
        return x.v < y.v;
}
void dfs(int x) { //深度优先遍历
    vis1[x] = 1;
    cout << x << " ";
    for (int i = 0; i < e[x].size(); i++) {
        int point = s[e[x][i]].v;
        if (!vis1[point]) {
            dfs(point);
        }
    }
}
void bfs(int x) { //广度优先遍历
    queue<int> q;
    q.push(x);
    cout << x << " ";
    vis2[x] = 1;
    while (!q.empty()) {
        int fro = q.front();
        for (int i = 0; i < e[fro].size(); i++) {
            int point = s[e[fro][i]].v;
            if (!vis2[point]) {
                q.push(point);
                cout << point << " ";
                vis2[point] = 1;
            }
        }
        q.pop();
    }
}
int main() {
    int n, m; //输入，存边
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int uu, vv;
        cin >> uu >> vv;
        s.push_back((edge){uu, vv});
    }
    sort(s.begin(), s.end(), cmp); //排序
    for (int i = 0; i < m; i++)
        e[s[i].u].push_back(i);
    dfs(1); //从1号顶点开始深搜
    cout << endl;
    bfs(1); //广搜亦同理
}