#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    priority_queue<pair<int,int> > coll;
    pair<int,int> a(3,4);
    pair<int,int> b(3,5);
    pair<int,int> c(4,3);
    coll.push(c);
    coll.push(b);
    coll.push(a);
    while(!coll.empty())
    {
        cout<<coll.top().first<<"\t"<<coll.top().second<<endl;
        coll.pop();
    }
    return 0;
}