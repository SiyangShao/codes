#include <bits/stdc++.h>
using namespace std;
int t , n , tmp , qa;
int a[2001];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		tmp=0;
		for(int i = 1 ; i<= n ; i++){
			cin>>qa;
			tmp^=qa;
			a[i]=a[i-1]^qa;
		}
		// for(int i = 1 ; i<=n ; i++){
		// 	cout<<(a[i]^a[i-1])<<" ";
		// }
		if(tmp==0){
			cout<<"YES\n";
		}else{
			for(int i = 1 ; i< n ; i++){
				for(int j = i+1 ;j<= n ; j++){
					if(int(a[n]^a[j]) == int(a[j]^a[i]) &&  int(a[j]^a[i]) == int(a[i]^a[0])){
						cout<<"YES\n";
						goto flag;
					}
				}
			}
			cout<<"NO\n";
			flag:;
		}
	}
}