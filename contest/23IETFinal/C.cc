#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

struct Point{
    double x,y;
};
double dis(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double xmulti(Point p1,Point p2,Point p0)    //求p1p0和p2p0的叉积,如果大于0,则p1在p2的顺时针方向
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int graham(std::vector<Point> &p,int n,int pl[])    //求凸包，返回凸包中点的个数+1
{
    //找到纵坐标（y）最小的那个点，作第一个点
    int i;
    int t = 1;
    for(i=1;i<=n;i++)
        if(p[i].y < p[t].y)
            t = i;
    pl[1] = t;
    //顺时针找到凸包点的顺序，记录在 int pl[]
    int num = 1;    //凸包点的数量
    do{    //已确定凸包上num个点
        num++; //该确定第 num+1 个点了
        t = pl[num-1]+1;
        if(t>n) t = 1;
        for(int i=1;i<=n;i++){    //核心代码。根据叉积确定凸包下一个点。
            double x = xmulti(p[i],p[t],p[pl[num-1]]);
            if(x<0) t = i;
        }
        pl[num] = t;
    } while(pl[num]!=pl[1]);
    return num-1;
}
double getS(Point a,Point b,Point c)    //返回三角形面积
{
    return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y)*(c.x - a.x))/2;
}
double getPS(std::vector<Point> &p,int pl[],int n)    //返回多边形面积。必须确保 n>=3，且多边形是凸多边形
{
    double sumS=0;
    for(int i=2;i<=n-1;i++)
        sumS+=fabs(getS(p[pl[1]],p[pl[i]],p[pl[i+1]]));
    return sumS;
}

double get_ans(std::vector<Point> &v) {
    int *pl = new int[9];
    int num = graham(v, 8, pl);
    return getPS(v, pl, num);
}

Point project(int a, int b, int c, int x, int y, int z) {
    double x1 = x - (double) z * (double) (x - a) / (double) (z - c);
    double y1 = y - (double) z * (double) (y - b) / (double) (z - c);
    return {x1, y1};
}

void solve() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int x, y, z;
    std::cin >> x >> y >> z;
    std::vector<Point> v = {
        project(0, 0, 0, x, y, z),
        project(0, 0, 0, x, y, z),
        project(a, 0, 0, x, y, z),
        project(a, b, 0, x, y, z),
        project(0, b, 0, x, y, z),
        project(0, 0, c, x, y, z),
        project(a, 0, c, x, y, z),
        project(a, b, c, x, y, z),
        project(0, b, c, x, y, z),
    };
    std::cout << std::fixed << std::setprecision(10) << get_ans(v) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}