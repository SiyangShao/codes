#include<cstdio>
long long n,m,high[1000000+10];
long long tmp,left,right;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&high[i]);
		if(high[i]>right) right=high[i];
	}
	while(left<=right){
		int mid=(left+right)/2;
		tmp=0;
		for(int i=1;i<=n;i++) 
		    if(high[i]>mid) tmp+=high[i]-mid;
		if(tmp<m) right=mid-1;
		else left=mid+1;
	}
	printf("%lld",right);
	return 0;
}