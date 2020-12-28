#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,na,nb;
    scanf("%d %d %d",&n,&na,&nb);
    int a[na],b[nb];
    for(int i = 0 ; i < na ; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0 ; i < nb ; i++){
        scanf("%d",&b[i]);
    }
    int sa=0,sb=0;
    for(int i = 0 ; i < n ; i++){
        if(a[i%na]==0){
            if(b[i%nb]==0){
                continue;
            }
            else if(b[i%nb]==1){
                sb++;
            }
            else if(b[i%nb]==2){
                sa++;
            }
            else if(b[i%nb]==3){
                sa++;
            }
            else if(b[i%nb]==4){
                sb++;
            }
        }
        else if(a[i%na]==1){
            if(b[i%nb]==0){
                sa++;
            }
            else if(b[i%nb]==1){
                continue;
            }
            else if(b[i%nb]==2){
                sb++;
            }
            else if(b[i%nb]==3){
                sa++;
            }
            else if(b[i%nb]==4){
                sb++;
            }
        }
        else if(a[i%na]==2){
            if(b[i%nb]==0){
                sb++;
            }
            else if(b[i%nb]==1){
                sa++;
            }
            else if(b[i%nb]==2){
                continue;
            }
            else if(b[i%nb]==3){
                sb++;
            }
            else if(b[i%nb]==4){
                sa++;
            }
        }
        else if(a[i%na]==3){
            if(b[i%nb]==0){
                sb++;
            }
            else if(b[i%nb]==1){
                sb++;
            }
            else if(b[i%nb]==2){
                sa++;
            }
            else if(b[i%nb]==3){
                continue;
            }
            else if(b[i%nb]==4){
                sa++;
            }
        }
        else if(a[i%na]==4){
            if(b[i%nb]==0){
                sa++;
            }
            else if(b[i%nb]==1){
                sa++;
            }
            else if(b[i%nb]==2){
                sb++;
            }
            else if(b[i%nb]==3){
                sb++;
            }
            else if(b[i%nb]==4){
                continue;
            }
        }
    }
    printf("%d %d\n",sa,sb);
    return 0;
}