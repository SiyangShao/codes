
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto main()->int{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

string s;
ll ans =0;
while(cin>>s){
    ans=0;
    if(s == "-1") break;
    int n = s.size();
    for(int k = 0; k<n; k++){
        
        //cout << s << " " << ans << "\n";
        int len = 0;
        vector<int> p(s.size());

        for(int i = 1; i<s.size(); i++){
            int j = p[i-1];
            while(j >0 && s[i]!=s[j]) j = p[j-1];
            if(s[i]==s[j])j++;
            p[i]=j;
            ans+=j;
        }
s = s.substr(1,s.size()-1);
    }
    cout << ans << "\n";
}
}
