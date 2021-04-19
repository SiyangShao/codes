#include <bits/stdc++.h>
using namespace std;
int ok[100010];
int main(){
	int n;
	cin>>n;
	int ans= 1 , sum=0;
	for(int i = 1 ; i<n ; i++){
		if(__gcd(i,n)==1){
			ans*=i;
			ok[i]=1;
			sum++;
			ans%=n;
		}
	}
	if(ans!=1){
		ok[ans]=0;
		sum--;
	}
	cout<<sum<<"\n";
	for(int i = 1 ; i< n ; i++){
		if(ok[i]){
			cout<<i<<" ";
		}
	}
	//cout<<ans;
}