#include <bits/stdc++.h>

using namespace std;
#define el '\n'
#define cl putchar('\n')
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define ceil(a, b) (a + (b - 1)) / b
#define ms(a, x) memset(a, x, sizeof(a))
#define inf 0x3f3f3f3f
#define db double

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<db, db> PDD;
typedef vector<int> vci;

inline int read() {
	int f = 1, d = 0;
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		d = (d << 1) + (d << 3) + (ch ^ 48), ch = getchar();
	return d * f;
}

const int N = 2e5 + 10, M = 2e6 + 10, E = 1e3 + 10, md = 1e9 + 7;
const double PI = acos(-1), eps = 1e-8;

int T, n, m;
map<int, LL> zt, nd;
LL ans, tmp, sum, tmp2;
PII b[N];

LL cn3(LL n) { return n * (n - 1) * (n - 2) / 6; }
int main() {
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		zt.clear();
		nd.clear();
		cin >> n;
		ans = cn3(n);
		rep(i, 1, n) {
			cin >> b[i].x >> b[i].y;
			zt[b[i].x]++;
			nd[b[i].y]++;
		}
		tmp = 0;
		rep(i, 1, n) { tmp += (zt[b[i].x] - 1) * (nd[b[i].y] - 1); }
		ans -= tmp;
		cout << ans << el;
	}
}
