#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, x[5010];
char tmp;
signed main() {
    cin >> n;
    for (int i = 1, j; i <= 2 * n; i++) {
        cin >> tmp >> j;
        if (j)
            if (tmp == 'I') {
                x[j]++;
            } else {
                x[j]--;
            }
        else {
            
        }
    }
}