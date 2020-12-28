#include <bits/stdc++.h>
const double eps = pow(10, -5);
#define zero(x) ((fabs(x) < eps ? 1 : 0))
#define sgn(x) (fabs(x) < eps ? 0 : ((x) < 0 ? -1 : 1))
using namespace std;
struct point {
	double x, y;
	point(double a = 0, double b = 0) { x = a, y = b; }
	point operator-(const point &b) const { return point(x - b.x, y - b.y); }
	point operator+(const point &b) const { return point(x + b.x, y + b.y); }
	bool operator==(point &b) const { return zero(x - b.x) && zero(y - b.y); }
	double operator*(const point &b) const { return x * b.x + y * b.y; }
	double operator^(const point &b) const { return x * b.y - y * b.x; }
	void split(double &a, double &b) { a = x, b = y; }
};
point start, tend;
struct line {
	point s, e;
	line() {}
	line(point ss, point ee) { s = ss, e = ee; }
};
point h[1024];
vector<point> q[1024];
bool cmp(point a, point b) {
	double disa = (a - start).x * (a - start).x + (a - start).y * (a - start).y;
	double disb =
		((b - start).x) * ((b - start).x) + ((b - start).y) * ((b - start).y);
	return disa < disb;
}
// l1 zhixian l2 xianduan
bool segxline(line l1, line l2) {
	return sgn((l2.s - l1.e) ^ (l1.s - l1.e)) *
			   sgn((l2.e - l1.e) ^ (l1.s - l1.e)) <=
		   0;
}
point spoint(line l1, line l2) {
	point res = l1.s;
	double t =
		((l1.s - l2.s) ^ (l2.s - l2.e)) / ((l1.s - l1.e) ^ (l2.s - l2.e));
	res.x += (l1.e.x - l1.s.x) * t;
	res.y += (l1.e.y - l1.s.y) * t;
	return res;
}
int main() {
	int n, m;
	cin >> n >> m;
	cin >> start.x >> start.y >> tend.x >> tend.y;
	line base;
	base.s = start, base.e = tend;
	for (int i = 1; i <= n; i++) {
		cin >> h[i].x >> h[i].y;
	}
	line tmp;
	point tmpiont;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			tmp.s = h[i], tmp.e = h[j];
			if (segxline(tmp, base)) {
				tmpiont = spoint(tmp, base);
				q[i].push_back(tmpiont);
				q[j].push_back(tmpiont);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(q[i].begin(), q[i].end(), cmp);
	}
	int hi, ki;
	while (m--) {
		cin >> hi >> ki;
		if (q[hi].size() < ki) {
			cout << "-1\n";
		} else {
			cout << setiosflags(ios::fixed) << setprecision(10);
			cout << q[hi][ki - 1].x << " " << q[hi][ki - 1].y << "\n";
		}
	}
}