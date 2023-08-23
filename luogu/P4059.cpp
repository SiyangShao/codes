#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3010;
string a, b;
int A, B;
// A T G C
int mp[4][4];
inline int d(char x, char y) {
    int X, Y;
    if (x == 'A')
        X = 0;
    else if (x == 'T')
        X = 1;
    else if (x == 'G')
        X = 2;
    else
        X = 3;
    if (y == 'A') {
        Y = 0;
    } else if (y == 'T') {
        Y = 1;
    } else if (y == 'G') {
        Y = 2;
    } else {
        Y = 3;
    }
    return mp[X][Y];
}
int dp[N][N][3];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> a >> b;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> mp[i][j];
        }
    }
    cin >> A >> B;
    auto lenA = a.length(), lenB = b.length();
    for (auto i = N - 1; i > 0; --i) {
        dp[0][i][0] = dp[i][0][0] = dp[0][i][2] = dp[i][0][1] = -0x3f3f3f3f;
        dp[0][i][1] = dp[i][0][2] = -A - B * (i - 1);
    }
    for (size_t i = 1; i <= lenA; ++i) {
        for (size_t j = 1; j <= lenB; ++j) {
            dp[i][j][0] = max(dp[i - 1][j - 1][0],
                              max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2])) +
                          d(a[i - 1], b[j - 1]);
            dp[i][j][1] = max(max(dp[i][j - 1][0] - A, dp[i][j - 1][1] - B),
                              dp[i][j - 1][2] - A);
            dp[i][j][2] = max(max(dp[i - 1][j][0] - A, dp[i - 1][j][2] - B),
                              dp[i - 1][j][1] - A);
        }
    }
    cout << max(dp[lenA][lenB][0], max(dp[lenA][lenB][1], dp[lenA][lenB][2]));
}