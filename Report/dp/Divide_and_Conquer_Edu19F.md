[Educational Codeforces Round 19](https://codeforces.com/contest/797) F

考虑$dp[j][i]$为前$j$个hole里共有$i$个人，如何从$dp[j-1][k]$转移。显然，第$k$到第$i$个人必然都去第$j$个hole（假设hole和人都已经排序过了）。对同一层（同一个$j$），可以通过前缀和预处理，得到第$k$到第$i$个人都去hole $j$的代价。

则有朴素转移方程

``` C++
    for (int j = 1; j <= n; ++j) {
     for (int k = max(0, j - h[i].second); k <= j; ++k) {
        dp[i][j] = min(dp[i][j], presum[j] - presum[k] + dp[i - 1][k]);
      }
    }
```

其中，presum为

``` C++
 presum[0] = 0;
 for (int i = 1; i <= n; ++i) {
   presum[i] = presum[i - 1] + abs(x[i] - h[j].first);
 }
```

复杂度为$O(mn^2)$。

考虑分治优化。显然，如果$k$到$i$个人去hole $j$， 则$i$后面的所有人至少在$j+1$，即转移点必然是不下降的。因此，将其改写为分治写法

``` C++
function<void(int, int, int, int, int)> cal = [&](int l, int r, int L, int R,
                                                    int j) {
    if (l > r || L > R)
      return;
    int mid = (l + r) / 2;
    int pos = min(R, mid);
    dp[j][mid] = dp[j - 1][mid];
    for (int i = max(L, mid - h[j].second); i <= min(R, mid); ++i) {
      if (dp[j][mid] > dp[j - 1][i] + presum[mid] - presum[i]) {
        dp[j][mid] = dp[j - 1][i] + presum[mid] - presum[i];
        pos = i;
      }
    }
    cal(l, mid - 1, L, pos, j);
    cal(mid + 1, r, pos, R, j);
  };
```

改写后复杂度变为$mn\log n$, 仍然需要推$m$层。答案即为$dp[m][n]$.

需要注意的是，此处由于利用了前缀和，需要先设$dp[i][0]=0$，且初始的$L,R$为$0,n$.

代码：https://codeforces.com/contest/797/submission/192640544

