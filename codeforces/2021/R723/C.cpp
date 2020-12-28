#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
priority_queue<int> q;
int sum;
int num;
signed main() {
    cin >> n;
    for (int i = 1, j; i <= n; i++) {
        cin >> j;
        if (sum + j >= 0) {
            sum += j;
            num++;
            if (j < 0) {
                q.push(-j);
            }
        } else {
            if (!q.empty() && -j < q.top()) {
                sum += q.top() + j;
                q.pop();
                q.push(-j);
            }
        }
    }
    cout << num;
}