#include <bits/stdc++.h>
using namespace std;
int n;
int _;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        vector<int> q;
        int tmp;
        while (n--) {
            scanf("%d", &tmp);
            if (tmp == 1) {
                q.push_back(1);
            } else {
                while (q.back() != tmp - 1 && q.size()) {
                    q.pop_back();
                }
                q.pop_back();
                q.push_back(tmp);
            }
            printf("%d", q[0]);
            for (int i = 1; i < q.size(); i++) {
                printf(".%d", q[i]);
            }
            printf("\n");
        }
    }
}