#include <bits/stdc++.h>
using namespace std;
struct node {
	int i;
	long long a, b, d;
	bool operator<(const node &x) const {
		if (d == x.d) {
			if (d <= 0) {
				return a < x.a;
			} else {
				return b > x.b;
			}
		}
		return d < x.d;
	}
} a[1010];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].b;
		a[i].i = i;
		if (a[i].a > a[i].b) {
			a[i].d = 1;
		} else if (a[i].a < a[i].b) {
			a[i].d = -1;
		} else
			a[i].d = 0;
	}
	sort(a + 1, a + 1 + n);
	long long fa = a[1].a, fb = a[1].a + a[1].b;
	for (int i = 2; i <= n; i++) {
		fb = max(fa + a[i].a, fb) + a[i].b;
		fa += a[i].a;
	}
    cout<<fb<<"\n";
    for(int i = 1 ; i<= n ; i++){
        cout<<a[i].i<<" ";
    }
}