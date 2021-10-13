#include <bits/stdc++.h>
using namespace std;
int m,s,t,s1,s2;
int main(){
    scanf("%d %d %d",&m,&s,&t);
    for(int i = 1 ; i <= t ; i++){
        s1+=17;
        if(m/10!=0){
            m-=10;
            s2+=60;
        }
        else{
            m+=4;
        }
        if(s1<s2){
            s1 = s2;
        }
        if(s1>=s||s2>=s){
            printf("Yes\n");
            printf("%d\n",i);
            return 0;
        }
    }
    printf("No\n");
    printf("%d",max(s1,s2));
}