d,k = map(int,input().spilt())
def gcd(x,y):
    if x== 0:
        return y
    return gcd(y%x,x)
ans = gcd(d,k)
def quickPow(x, n, m):
    if n == 0:
        return 1
    if n % 2 == 0:
        return quickPow(x * x % m, n // 2, m)
    else:
        return x * quickPow(x * x % m, n // 2, m) % m
def millerRabin(n):
    if n < 3 or n % 2 == 0:
        return n == 2
    a, b = n - 1, 0
    while a % 2 == 0:
        a = a // 2
        b = b + 1
    for i in range(1, 8 + 1):
        x = random.randint(0, 32767) % (n - 2) + 2
        v = quickPow(x, a, n)
        if v == 1:
            continue
        j = 0
        while j < b:
            if v == n - 1:
                break
            v = v * v % n
            j = j + 1
        if j >= b:
            return False
    return True
if millerRabin(ans):
    while k%ans == 0 and k != 0:
        k = k//ans
    if k == 0:
        print(ans * d)
    else:
        print(d)
else:
    print(d)