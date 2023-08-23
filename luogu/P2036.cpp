#include <bits/stdc++.h> //非常稳健的万能头
using namespace std;
long long int s[20], b[20], f[20];					 //s表示酸度，b表示甜度，f记录是否查找
long long int n, j, c = 1, y = 0, ans = 99999999999; //ans记录最小值
void dfs(int x)
{
	if (x > n) //最多选n种调料，超过不做操作
	{
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (f[i] == 0) //没有查找过的才操作
			{
				c *= s[i];
				y += b[i];
				ans = min(ans, abs(c - y)); //取最小值
				f[i] = 1;					//记录
				dfs(x + 1);
				f[i] = 0; //取消记录 (撤回到上一节点)
				c /= s[i];
				y -= b[i];
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i] >> b[i];
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}