#include <bits/stdc++.h>
using namespace std;
int main(){
    int len;
    cin >> len;
    int a[len];
    for(int i = 0 ; i < len ; i++){
        cin>>a[i];
    }
    int j = 0, gap = 0;
    for (gap = len / 3; gap > 0; gap /= 3){
        for (j = gap; j < len; j++){//从数组第gap个元素开始
            if (a[j] < a[j - gap])//每个元素与自己组内的数据进行直接插入排序
            {
                int temp = a[j];
                int k = j - gap;
                while (k >= 0 && a[k] > temp)
                {
                    a[k + gap] = a[k];
                    k -= gap;
                }
                a[k + gap] = temp;
            }
        }
    }
    for(int i = 0 ; i < len ; i++){
        cout<<a[i];
        if(i!=len-1) cout<<" ";
        else cout << endl;
    }
    return 0;
}