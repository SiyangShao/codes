#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
bool vis[maxn];
ll prime[maxn];
int f[maxn];
int n,m;
void Euler_prime() {
	for (ll i = 2; i <= n; i++) {
		if (!vis[i]) {
			prime[++prime[0]] = i;
            f[i]=f[i-1]+1;
		}else{
            f[i]=f[i-1];
        }
		for (ll j = 1; j <= prime[0] && i * prime[j] <= n; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>m>>n;
    Euler_prime();
    while(m--){
        int l , r;
        cin>>l>>r;
        if(l<1||r>n){
            cout<<"Crossing the line\n";
        }else{
            cout<<f[r]-f[l-1]<<"\n";
        }
    }
}