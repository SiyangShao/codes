#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
void solve() {
    int n,m;
    cin >> n >> m;
    int col[m];
    int row[n];
    for(int i=0;i<m;i++){
        col[i] = INF;
    }
    for(int i=0;i<n;i++) row[i]=INF;
    int M[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin >> M[i][j];
            row[i] = min(M[i][j],row[i]);
            col[j] = min(M[i][j], col[j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j] == min(row[i],col[j])) ans++;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}