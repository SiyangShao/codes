/***
#include <bits/stdc++.h>
using namespace std;
struct q{
    int n  , li;
};
bool cam1(q a , q b){
    return a.n > b.n;
}
bool cam2(q a , q b){
    return a.li < b.li;
}
int main(){
    q s[300];
    int len;
    int k;
    for(len = 0 ;; len++){
        int cc = getchar();
        if(cc == '\n') break;
        cc = cc - '0';
        s[len].n = cc;
        s[len].li=len;
    }
    cin >> k;

    sort(s,s+len,cam1);

    for(int i = 0 ; i < len-k ; i++){
        s[i].n = s[i+k].n;
    }
    sort(s,s+len-k,cam2);

    for(int i = 0 ; i < len - k ; i++){
        cout<<s[i].n;
    }
    cout << endl;
    return 0;
}
以上代码均为错误
但是对结构体的运用熟练掌握了2333
***/
#include <stdio.h>
#include <string.h>
char c[260];
int main(){
    int len,i,j,s;
    scanf("%s%d",c,&s);
    len=strlen(c);
    while(s--){
        for(i=0;i<=len-2;i++)
            if(c[i]>c[i+1]){
                for(j=i;j<=len-2;j++)
                    c[j]=c[j+1];
                break;
            }
        len--;//此处位置写错，之前写在if内部
    }
    i=0;
    while(i<=len-1&&c[i]=='0')i++;//处理前导0 
    if(i==len)printf("0");
    else
        for(j=i;j<=len-1;j++)
            printf("%c",c[j]); 
    return 0;
} 