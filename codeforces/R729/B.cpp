#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, a, b;
inline bool judge() {
    if(x==1||b==1||x%b==1) return true;
    if(a==1){
        if(x%b==1) return true;
        else return false;
    }
    for (int base = 1 , i = 1; i<=30,base <= x; ++i,base *= a) {
        if ((x - base) % b == 0) {
            return true;
        }
    }
    return false;
}
signed main() {
    int _;
    scanf("%lld",&_);
    while (_--) {
        scanf("%lld %lld %lld", &x, &a, &b);
        if (judge()) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
}