#include <bits/stdc++.h>
#define pii pair<int, int>
#define x first
#define y second
using namespace std;
int _, n;
string s;
int numD[500010], numK[500010];
map<pii,int>mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> _;
    while (_--) {
        mp.clear();
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            numD[i] = numD[i - 1] + (s[i - 1] == 'D');
            numK[i] = numK[i - 1] + (s[i - 1] == 'K');
        }
        for(int i = 1 ; i<=n ; i++){
            pii cur = {numD[i]/__gcd(numD[i],numK[i]),numK[i]/__gcd(numD[i],numK[i])};
            mp[cur]++;
            cout<<mp[cur]<<" ";
        }
        cout<<endl;
    }
}