#include <bits/stdc++.h>
using namespace std;
int f[10010], c[10010], w[10010], m[10010], val, n, ans;
int tah, tbh, tam, tbm;
void ZeroOnePack(int i) {
	for (int v = val; v >= c[i]; v--) {
		f[v] = max(f[v], f[v - c[i]] + w[i]);
	}
}
void CompletePack(int i) {
	for (int v = c[i]; v <= val; v++) {
		f[v] = max(f[v], f[v - c[i]] + w[i]);
	}
}
void MultiplePack(int i) {
	if (c[i] * m[i] >= val) {
		CompletePack(i);
		return;
	}
	int k = 1;
	while (k < m[i]) {
		for (int v = val; v >= k * c[i]; v--) {
			f[v] = max(f[v], f[v - k * c[i]] + k * w[i]);
		}
		m[i] = m[i] - k;
		k = 2 * k;
	}
	for (int v = val; v >= c[i] * m[i]; v--) {
		f[v] = max(f[v], f[v - c[i] * m[i]] + m[i] * w[i]);
	}
}
void MixinPack() {
	for (int i = 1; i <= n; i++) {
		if (m[i] == 1) {
			ZeroOnePack(i);
		} else if (m[i] == 0) {
			CompletePack(i);
		} else if (m[i] > 1) {
			MultiplePack(i);
		}
	}
}
void GetTime() {
	scanf("%d:%d %d:%d", &tah, &tam, &tbh, &tbm);
	val = (tbh - tah) * 60 + tbm - tam;
}
int main() {
	GetTime();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i] >> w[i] >> m[i];
	}
	MixinPack();
	for (int i = 1; i <= val; i++) {
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
}