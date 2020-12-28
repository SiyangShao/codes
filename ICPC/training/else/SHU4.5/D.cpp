#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
queue<ll> q;
char tmp;
int main(){
    scanf("%lld",&n);
    getchar();
    while(n--){
        tmp = getchar();
        if(tmp=='-'){
            q.pop();
        }
    }
}