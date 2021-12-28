#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
// int n;
// vector<int> h, same;
// bool judge(const int x) {
// 	for (int i = 0; i < n; ++i) {
// 		// cout << "\n\n";
// 		// cout << i << " " << h[i] << " ";
// 		// for (auto j : h) {
// 		// 	cout << j << " ";
// 		// }
// 		// cout << "\n";
// 		if (h[i] >= x) {
// 			continue;
// 		} else {
// 			if (i == n - 1) {
// 				// cout << "\n!!!\n";
// 				// for (auto j : h) {
// 				// 	cout << j << " ";
// 				// }
// 				// cout << "\n";
// 				h = same;
// 				return false;
// 			} else if (i == n - 2) {
// 				int d = x - h[i];
// 				h[i + 1] -= d * 3;
// 				if (h[i + 1] >= x) {
// 					h = same;
// 					return true;
// 				} else {
// 					h = same;
// 					return false;
// 				}
// 			} else {
// 				// cout << x << " ";
// 				int d = ceil((x - h[i]) / 2.0);
// 				if (h[i + 2] < 3 * d) {
// 					if (i == 0) {
// 						h = same;
// 						return false;
// 					}
// 					int dx = h[i + 2] / 3;
// 					h[i + 2] -= 3 * dx;
// 					// h[i + 1] += dx;
// 					h[i] += dx * 2;
// 					d = x - h[i];
// 					h[i + 1] -= d * 3;
// 					if (h[i + 1] < 0) {
// 						h = same;
// 						return false;
// 					}
// 					h[i + 1] += dx;
// 					// return false;
// 				} else {
// 					h[i] += d * 2;
// 					// cout << d << "\n";
// 					h[i + 1] += d;
// 					h[i + 2] -= 3 * d;
// 				}
// 			}
// 		}
// 	}
// 	h = same;
// 	return true;
// }
// void solve() {
// 	int r = 0, l = 1000000010;
// 	cin >> n;
// 	h.resize(n);
// 	for (auto &i : h) {
// 		cin >> i;
// 		l = min(l, i);
// 		r = max(r, i);
// 	}
// 	same = h;
// 	int mid = (l + r) / 2, ans = l;
// 	// cout << judge(3) << "\n";
// 	// cout << n << ":!!!\n";
// 	// int jx = judge(6);
// 	// cout << "????1!" << jx;
// 	// cout << 6 << " " << judge(6) << "\n";

// 	while (l <= r) {
// 		mid = (l + r) / 2;
// 		// cout << mid << " " << judge(mid) << "\n";
// 		if (judge(mid)) {
// 			ans = max(ans, mid);
// 			l = mid + 1;
// 		} else {
// 			r = mid - 1;
// 		}
// 	}
// 	cout << ans << "\n";
// }
int n;
vector<int> h, a;
bool judge(int d) {
	// h_i - 3d >=0
	// h_i - d_i + d_(i+1) + 2d_(i+2) >= k
	// d_i <= h_i/3;
	// d_i <= (h_i + d_(i+1) + 2d_(i+2) - k )/3
	a = h;
	for (int i = a.size() - 1; i >= 2; --i) {
		if (a[i] < d) {
			return false;
		}
		int rem = min(a[i] - d, h[i]);
		a[i - 1] += rem / 3;
		a[i - 2] += (rem / 3) * 2;
	}
	return min(a[0], a[1]) >= d;
}
void solve() {
	cin >> n;
	h.resize(n);
	int l = 100000010, r = 0;
	for (auto &i : h) {
		cin >> i;
		l = min(l, i);
		r = max(r, i);
	}
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (judge(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}