#include <bits/stdc++.h>

using namespace std;
int n, m1, m2;
const int N = 1010;

int p1[N], p2[N];
int find(int p[], int x) {
    if (p[x] != x)
        p[x] = find(p, p[x]);
    return p[x];
}

int main() {
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= n; i++)
        p1[i] = p2[i] = i;

    for (int i = 1; i <= m1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        p1[find(p1, a)] = find(p1, b);
    }

    for (int i = 1; i <= m2; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        p2[find(p2, a)] = find(p2, b);
    }
    cout << n - max(m1, m2) - 1 << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int a1 = find(p1, i);
            int a2 = find(p2, i);
            int b1 = find(p1, j);
            int b2 = find(p2, j);
            if (a1 != b1 && a2 != b2) {
                cout << i << " " << j << endl;
                p1[a1] = b1;
                p2[a2] = b2;
            }
        }

    return 0;
}
