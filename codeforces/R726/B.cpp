#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m, i, j, a, b, c, d , f , g;
inline int cal(int x, int y , int z , int e) { return abs(x - z) + abs(y - e); }
inline int MAX(){
    return max(a,max(b,max(c,max(d,max(f,g)))));
}
signed main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld %lld %lld %lld", &n, &m, &i, &j);
        a = cal(1,m,i,j) + cal(1,m,1,1) + cal(1,1,i,j);
        b = cal(1,m,i,j) + cal(1,m,n,1) + cal(n,1,i,j);
        c = cal(1,m,i,j) + cal(1,m,n,m) + cal(n,m,i,j);
        d = cal(1,1,i,j) + cal(1,1,n,1) + cal(n,1,i,j);
        f = cal(1,1,i,j) + cal(1,1,n,m) + cal(n,m,i,j);
        g = cal(n,1,i,j) + cal(n,1,n,m) + cal(n,m,i,j);
        if(a == MAX()){
            printf("1 %lld 1 1\n",m);
        }else if(b == MAX()){
            printf("1 %lld %lld 1\n",m,n);
        }else if(c == MAX()){
            printf("1 %lld %lld %lld\n",m,n,m);
        }else if(d == MAX()){
            printf("1 1 %lld 1\n",n);
        }else if(f == MAX()){
            printf("1 1 %lld %lld\n",n,m);
        }else{
            printf("%lld 1 %lld %lld\n",n,n,m);
        }
    }
}