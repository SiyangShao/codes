 #include<bits/stdc++.h>
    using namespace std;
    int a[100000];
    int main(){
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(1){
        int j=1;
        while(a[j]==0)
        j++;
        if(j==n) break;
        else {
            a[j]+=a[j+1];
            sum+=a[j];
            for(int l=j+1;l<n;l++)
             {
                a[l]=a[l+1];
            }
            n--;
        }
        for(int l=j;l<n;l++)
        {
            if(a[l]>a[l+1])
            {
                swap(a[l],a[l+1]);
            }
        }
    }
    cout<<sum<<endl;
    return 0;
    }