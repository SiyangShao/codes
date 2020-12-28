import math


def ksm(a, b):
    res = 1
    while b:
        if b & 1:
            res *= a
            if res > 15625000000000000000000:
                return -1
        a = a**2
        if a > 15625000000000000000000:
            return -1
        b >>= 1
    return res


if __name__ == "__main__":
    n, m = map(int, input().split())
    for v in range(2, 5001):
        for u in range(v - 1, 0, -1):
            if math.gcd(u, v) != 1:
                continue
            vv = ksm(v, n)
            uu = ksm(u, n)
            if vv == -1 or uu == -1:
                continue
            if m * (v - u) % (vv - uu) == 0:
                assert math.gcd(v, v - u) == 1
                print(v - u, v)
                exit(0)
    print("impossible")
