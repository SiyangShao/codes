#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>m>>n;
    int sch[m],stu[n];
    for(int i = 0 ; i < m ; i++){
        cin>>sch[i];
    }
    for(int i = 0 ; i < n ; i++){
        cin>>stu[i];
    }
    sort(sch,sch+m);
    sort(stu,stu+m);
}