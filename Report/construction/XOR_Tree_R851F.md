https://codeforces.com/contest/1788/problem/F

给一棵树，构造边权，使得对给出的$q$组$u-v-x$,有路径$u-v$上XOR和为$x$。同时，使得树的边权XOR和最小。

对$u-v$而言，定义$p[u]$为从$root$到$u$路近上XOR和。则对$u-v-x$, 显然有$p[u] \oplus p[v] = x$。通过dfs可以构建出。

问题：如何使得边权XOR和最小？

考虑原树。易得，原树的边权XOR和为
$$
\bigoplus_{deg[i]\%2=1} p[i]
$$
即我们只需要考虑原树中奇数度数的点。

根据给的$q$组$u-v$关系建立新树。显然，新树（森林）的每一个连通分量都是独立的。在每一个连通分量中对任意一个点修改，如令$p[k] = p[k]\oplus x$, 就需要对该连通分量中其余所有点都做该操作，才能保证原本性质$p[u]\oplus p[v] = x$不变。

那么，如果存在一个连通分量，使得其奇数度数（原树中度数）点为奇数个，对其中每个点均XOR原本的边权XOR和，即可使得新的树中边权XOR和为$0$。若不存在，则显然，无论做什么操作，最终边权XOR和不变。