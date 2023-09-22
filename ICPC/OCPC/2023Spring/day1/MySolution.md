# B
Observation:
$$
f_{i+1} - f_{i} = a_{i+k} - a_{i}
$$
There are totally $\gcd(n,k)$ cycles, $a_i, a_{i+k}, a_{i+k+k}, \cdots, a_{i}$. Then we take $k = \gcd(n,k)$. The two arrays are the same iff all the difference and the first element is the same. Then we enumerate non-zero differnce, each has $(x-1)$ ways, in which $x = 2^{n/k} - 1$. For all zero difference rounds, (suppose there are $y$ all-zero cycles), the specific way is $y + 1$ (the sum of first $y$ elements is from $0$ to $y$).
$$
\sum_0^{k} (x-1)^{i} \times C(k,i) \times (k-i+1)
$$
and we should calculate it in $O(\log n)$.
$$
(x-1)^i \times C(k,i) \times (k-i+1) = (k+1) \times (x-1)^i - i \times \frac{k!}{i! \times (k-i)} = \\
(x-1)^i\times C(k,i) \times(k+1) - (x-1) \times (x-1)^{i-1}\times \frac{k \times (k-1)!}{(i-1)! \times (k-1 - (i-1))!}
$$
Calcualte them seperately
$$
\sum_{0}^{n} (x-1)^i\times C(k,i) \times(k+1) = (k+1) \times (x-1+1)^k
$$
$$
\sum_{0}^{n} (x-1) \times (x-1)^{i-1}\times \frac{k \times (k-1)!}{(i-1)! \times (k-1 - (i-1))!} = 0 + (x-1)\times k\times\sum_{1}^{n} (x-1)^{i-1}\times C(k-1,i-1)
$$
It equals to
$$
(x-1) \times k \times (x-1+1)^{k-1}
$$
Both of them can be calculated through quick pow in $\log n$
# D
Take all edges$\{u,v\} = 1$ if $d[u][v] = 1$, then use floyd (传递凸包) and dsu to check whether it satisfy the requirement.
# F
If has square in graph, answer is 2, or it's 3.
# I
dp. Implement hard. Start from $dp[n][0]$ and ends at $dp[0][m]$.
# J
Observation 1: The answer for the question would only become $-1, n, n-1, n-2$.
+ answer is $-1$: the array is sorted
+ answer is $n$: the number of inversions is odd

We take $a[i]$ as number of inversions for value $i$.
+ answer is $n-1$: exist $a[i]\%2==1$, choose the subsequence without that $i$.
+ answer is $n-2$: Delete one $a[i] > 0$. Obviously, all $a[i] \%2 == 0$. After deletion, some $a[j]$ connected with $i$ would become odd. Delete the odd one. The answer is $n-2$.

We could precalculate the $a[i]$ in $n\log n$. We only care the odd/even of $a[i]$.
+ When we swap $l,r$, for $i \in (l,r)$, there $a[i]$ won't change.
  Assume $val[l] > val[r]$. If $val[l] < val[i] < val[r]$, $a[i] = a[i] + 2$, or if $val[i] > val[l] > val[r]$, $a[i]$ remains no change.
+ When we swap $l,r$, for $i < l$ and $i > r$, $a[i]$ won't change.
+ For $l,r$, they would change only if $(r-l)\%2=1$.
  For elements outside $l,r$, there's no change. Suppose there are $x$ elements in $l,r$ which is less then $l$, thus, there are $r - l - 1 - x$ elements in $l,r$ which is larger then $l$. After swap, $a[l] = a[l] - x + (r - l - 1 - x) \pm 1$. (Consider the inversion $l-r$) As we only care the odd/even of $a[l]$, we've found that it would change iff $(r-l) \%2 =1$.
+ Totally, the inversion would change $\pm 1$ when we swap $l,r$.

Thus, we could answer the query in $O(1)$.
``` C++
int l, r;
cin >> l >> r;
l--, r--;
int u = a[l], v = a[r];
update(l, u, v, abs(r - l));
update(r, v, u, abs(r - l));
// cout << odd << " " << even << " ";
tot ^= 1;
if (same == n) {
  cout << "-1\n";
} else {
  if (tot % 2 == 1) {
    cout << n << "\n";
  } else {
    if (odd > 0) {
      cout << n - 1 << "\n";
    } else {
      cout << n - 2 << "\n";
    }
  }
}
```
# K
If in SCC, Yes. Else NO.