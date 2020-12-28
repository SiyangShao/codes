#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
const int N = 1e6 + 1;
int b[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]]++;
    }
    int ans = 0;
    for (int i = N - 1; i >= 1; --i) {
        int tmp = 0;
        int k = 0;
        for (int j = i; j < N; j += i) {
            tmp += b[j];
            if (b[j]) {
                k = gcd(k, j / i);
            }
        }
        if (b[i] == 0 && tmp > 1 && k == 1) {

            b[i] = 1;
            ans++;
        }
    }
    cout << ans;
    return 0;
}