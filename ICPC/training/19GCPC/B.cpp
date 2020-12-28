#include <bits/stdc++.h>
using namespace std;
struct point {
	double x, y;
};
inline double dis(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline double accos(double A, double B, double C) {
	return acos((A * A + B * B - C * C) / (2 * A * B));
}
int T;
double r , r2;
inline double sua(double dis) { return sqrt(dis * dis - r * r); }
point o, s, t , out;
int main() {
	cin >> s.x >> s.y >> t.x >> t.y;
    cin >> out.x >> out.y >> r2;
	cin >> o.x >> o.y >> r;
	double disa = dis(o, s), disb = dis(o, t), disc = dis(s, t);
	double all = accos(disa, disb, disc);
	double left = acos(r / disa), right = acos(r / disb);
	// cout<<disa<<" "<<disb<<" "<<disc<<" "<<all<<" "<<left<<" "<<right<<"\n";
	if (all < left + right) {
		cout << setiosflags(ios::fixed) << setprecision(10) << disc << "\n";
	} else {
		double angle = all - left - right;
		double length = angle * r;
		cout << setiosflags(ios::fixed) << setprecision(10)
			 << sua(disa) + sua(disb) + length << "\n";
	}
}