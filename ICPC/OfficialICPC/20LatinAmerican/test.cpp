#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
    auto c = getchar();
    ll x = 0, tmp = 1;
    while (c < '0' || c > '9') {
        if (c == '-')
            tmp = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * tmp;
}
int main(){
    
}