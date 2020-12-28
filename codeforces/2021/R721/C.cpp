#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> s;
		int cnt = 0;
		int cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i]=='1'){
                continue;
            }
            if(s[i]==s[n-i-1]){
                cnt++;
            }else{
                cnt1++;
            }
		}
        if(cnt1>=2||!cnt){
            cout<<"ALICE\n";
        }else if(cnt1==1){
            if(cnt==1){
                cout<<"DRAW\n";
            }else{
                cout<<"ALICE\n";
            }
        }else if(cnt==1){
            cout<<"BOB\n";
        }else if(cnt&1){
            cout<<"ALICE\n";
        }else{
            cout<<"BOB\n";
        }
	}
}