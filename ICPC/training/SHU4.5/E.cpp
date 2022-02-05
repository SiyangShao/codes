#include <bits/stdc++.h>
using namespace std;
int n;
int j = 0 , q = 0;
int main(){
    scanf("%d",&n);
    getchar();
    while(n--){
        char c = getchar();
        int i = c - '0';
        if(i==j&&j==0){
            printf("0");
        }else if(i!=j&&j==0){
            printf("1");
        }else if(i==j&&j==1){
            printf("0");
        }else{
            printf("1");
        }
        j|=i;
    }
    
}