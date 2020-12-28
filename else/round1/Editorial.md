# Problem 1. [最古の遺跡 3 (Ruins 3)](https://www.ioi-jp.org/camp/2020/2020-sp-tasks/day2/ruins3.pdf)

+ Submit: [atcoder](https://atcoder.jp/contests/joisc2020/tasks/joisc2020_f) or [loj](https://loj.ac/p/3276)
+ Official Editorial: https://www.ioi-jp.org/camp/2020/2020-sp-tasks/day2/ruins3-review.pdf
+ $N\leq 600$
+ 给出$2N$个数，其中$1$到$N$各出现两边。$\forall k \in [1,N]$,取编号最大的$a_j == k$ 不变，其余数字均减1. 给出最终剩余的$N$ 个数，求原始方案个数。

>  observation:
>
> + 第$i$轮后，前$N-i$个数均有两个，而后$i$个数均只有一个（已经确定，不可更改）
>
> + 对每一个高度，最后保留的为曾经**到过**该高度的石柱中编号最大的
>
>   + 假设已经知道初始局面，如何O(n) 求出保留石柱？
>
>     考虑一个集合，内包含所有到过$k$的点的下标。对$k = n, n-1, \cdots, 1$, 取**值**为$k$的两个下标加入集合。取集合中下标最大的点，该点即为**最终状态**为$k$的石柱。

做法：

令$dp_{i,j}$表示考虑石柱$[i, 2N]$, 最终状态存在值$[1, j]$. 由$dp_{i+1, j}$ 向$dp_{i,j}$转移

+ 则根据定义可得， 对给定的方案$dp_{i,j}$, 若$i \not\in A$, $h_i \leq j$, 若 $i \in A$, $h_i > j$.

+ 令$cnt$表示$[i,2N]$中不在$A$中元素个数。

+ 若$i \not\in A$ , $j$内元素被填入了$j+cnt$个。此时， $dp[i][j] = dp[i+1][j] * (j*2-(j+cnt))$

+ 若$i \in A$, 假设其最终高度为$j$. 考虑枚举填入$h_j$前存在$[1, j-k]$. 新填入的后$k-1$个元素高度一定为$[j-k+1, j]$. 当前点有$k+1$种方案，令其余点（扩展后新填入点）方案数为$pre_{k-1}$， 由$j-k$转移而来，转移方程为
  $$
  \sum_{k=1}^{j} dp[i+1][j-k] \times C(key - (j-k), k-1) \times pre_{k-1} \times (k+1)
  $$
  $pre_{k}$表示$k$个**关键**位置，填入$\leq k$的数的合法方案数。令$pre_{i,j}$表示放完了$[1,i]$, 每种最多$2$个，总共$j$个，且值为$[1,i]$的个数不超过$i$个（即保证合法，否则这些位置不全为关键位置）。
  $$
  pre[i][j] = pre[i-1][j] + pre[i-1][j-1] \times j \times 2 +pre[i-1][j-2]\times j \times (j-1)
  $$

# Problem 2. [动态直径](https://loj.ac/p/3163)

+ 题意：树动态直径，强制在线，点数和询问次数均为$1e5$
+ 做法：

# Problem 3. [G. Weighed Tree Radius](https://codeforces.com/contest/1783/problem/G)

+ 题意：一棵树，有点权无边权。令$w_v(u) = d_v(u) + a_u$, 求$\min (\max_{u \in n} w_v(u))$
+ 定义$w(u,v) = a_u + a_v + d(u,v)$. 以此计算树的直径