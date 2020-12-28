N, M = map(int, input().split())
es = []
inf = 10**18
for _ in range(M):
  a, b, c = map(int, input().split())
  es.append((a - 1, b - 1, c))

d = [[inf] * N for _ in range(N)]
for a, b, c in es:
  d[a][b] = c
  d[b][a] = c
for k in range(N):
  for i in range(N):
    for j in range(N):
      d[i][j] = min(d[i][j], d[i][k] + d[k][j])

answer = 0
for a, b, c in es:
  unused = 0
  for i in range(N):
    if d[a][i] + d[i][b] <= c:
      unused = 1
  answer += unused
print(answer)
