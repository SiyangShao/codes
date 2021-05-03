#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n;
vector<int>q[N];
int num[N];
map<pair<int,int>,int>mp;
int main(){
    scanf("%d",&n);
    for(int i = 1 , j , k , l ; i < n ; i++){
        scanf("%d %d %d" , &j , &k , &l);
        mp[make_pair(j,k)] = mp[make_pair(k,j)] = l;
        q[j].push_back(k);
        q[k].push_back(j);
    }
}