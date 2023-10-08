from collections import deque


def cal(x):
    cnt = 0
    while x:
        cnt += 1
        x //= 2
    return cnt


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = [0] * n
    E = [[] for _ in range(n)]
    id = []
    in_degree = [0] * n

    for _ in range(m):
        u, v = map(int, input().split())
        u, v = u - 1, v - 1
        E[u].append(v)
        in_degree[v] += 1

    Q = deque()
    for i in range(n):
        if in_degree[i] == 0:
            Q.append(i)

    while Q:
        u = Q.popleft()
        id.append(u)
        for v in E[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                Q.append(v)

    end = id[-1]
    for t in range(1, n + 1):
        flag = True
        for i in range(n):
            if a[i] != 0:
                flag = False
            b[i] = a[i]
            a[i] = 0

        if flag:
            print(t - 1)
            return

        for i in id:
            for j in E[i]:
                a[j] += b[i]

        a[end] += b[end] // 2

    print(n + cal(a[end]))


if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
