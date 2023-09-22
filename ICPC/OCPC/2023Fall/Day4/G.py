t = int(input())
for i in range(0, t):
    n, m = map(int, input().split())
    average = n // m
    if n % m == 0:
        print(average)
    else:
        print(average | (average + 1))
