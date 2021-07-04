#include <bits/stdc++.h>
using namespace std;
int a[1000020];
int findpos(int a[], int l, int r, int k)
{
	if (l == r)
	{
		if (a[l] == k)
			return l;
		else
			return -1;
	}
	int mid = (l + r) / 2;
	if (k <= a[mid])
		findpos(a, l, mid, k);
	else
		findpos(a, mid + 1, r, k);
}
int main()
{
	int n, m, k;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	while (m--)
	{
		cin >> k;
		cout << findpos(a, 1, n, k) << " ";
	}
	return 0;
}
