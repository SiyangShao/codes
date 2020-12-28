#include <bits/stdc++.h>
using namespace std;
int _,a,b,sum;
set<int> st;
int main(){
    scanf("%d",&_);
    while(_--){
        scanf("%d%d",&a,&b);
        st.clear();
        if(a<=b){
            swap(a,b);
        }
        int j = (a+b)/2 , k = (a+b)-j , ans = a-j , add = a-k;
        for(int i = 0 ; i<=b ; ++i){
            st.insert(ans+i*2);
            st.insert(add+i*2);
        }
        printf("%ld\n",st.size());
        for(auto i:st){
            printf("%d ",i);
        }
        puts("");
    }
}