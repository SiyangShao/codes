#include <bits/stdc++.h>
#define F(i, l, r) for (int i = (l), _end_ = (int)(r); i <= _end_; ++i)
#define f(i, r, l) for (int i = (r), _end_ = (int)(l); i >= _end_; --i)
#define Set(a, v) memset(a, v, sizeof(a))
using namespace std;
auto chkmin(int &a, int b) -> bool { return b < a ? a = b, true : false; }
auto chkmax(int &a, int b) -> bool { return b > a ? a = b, true : false; }

inline auto read() -> long long {
    long long x = 0, fh = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            fh = -1;
    for (; isdigit(ch); ch = getchar())
        x = (x << 1) + (x << 3) + (ch ^ '0');
    return x * fh;
}
int n;
string s;
int top;
array<int,5000005>ans;
void solve() {
    cin >> n;
    cin >> s;
    int tot = 0;
    top = 0;
    for (char i : s) {
        ans[++top] = i;
        if (top == 1)
            continue;
        if (ans[1] == '(' || ans[1] == ans[top]) {
            top = 0;
            tot++;
        }
    }
    printf("%d %d\n", tot, top);
}
auto main() -> int {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
