#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i<= n; i++) {
        cin>>a[i];
    }
    vector<set<int>> num(3);
    for(int i = 1 ; i <= n; ++i){
        num[a[i]].emplace(i);
    }
    vector<pair<int,int>> op;
    for(int i = n; i>=1; --i) {
        if(a[i] == 2) {
            num[2].erase(i);
            continue;
        }
        if(a[i] == 0) {
            // must move 1 here
            num[0].erase(i);
            if(num[2].size() != 0) {
                assert(num[1].size() != 0);
            }
            if(num[1].size() != 0) {
                auto j = *num[1].begin();
                num[1].erase(j);
                num[0].emplace(j);
                op.emplace_back(i,j);
                a[i]++;
                a[j]--;
            }
        }
        if(a[i] == 1) {
            num[1].erase(i);
            if(num[2].size() == 0) {
                continue;
            }
            // swap a num[2] here
            auto j = *num[2].begin();
            num[2].erase(j);
            op.emplace_back(i, j);
            num[1].emplace(j);
            a[i]++;
            a[j]--;
        }

    }
    assert(op.size() <= n);
    cout<<op.size()<<"\n";
    for(auto [u,v]:op){
        cout<<u<<" "<<v<<"\n";
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin>>_;
    while(_--){
        solve();
    }
}
