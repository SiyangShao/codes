import random
import time
import subprocess


def get_num(n, m):
    return [random.randint(1, m) for i in range(n)]


def get_ans(a, n, m):
    ans = -1
    for l in range(len(a)):
        hv = [0] * (m + 1)
        now_dist = 0
        now_mex = 0
        for r in range(l, len(a)):
            if hv[a[r] - 1] == 0:
                now_dist += 1
            hv[a[r] - 1] += 1
            while hv[now_mex] > 0:
                now_mex += 1
            # print(l, r, now_dist, now_mex)
            ans = max(ans, now_dist - now_mex - 1)
    return ans

if __name__ == "__main__":
    # n, m = 5, 4
    # a = [1, 2, 2, 3, 4]
    # print(get_ans(a, n, m))
    while True:
        n, m = 500000, 500000
        a = get_num(n, m)
        with open("my.in", "w") as f:
            print(1, file=f)
            print(n, m, file=f)
            for x in a:
                print(x, end=" ", file=f)
        now_time = time.time()
        subprocess.run("./I")
        print("time:", time.time() - now_time)
        # with open("my.out", "r") as f:
        #     my = int(f.read())
        #     ans = get_ans(a, n, m)
        #     if my != ans:
        #         print("WA")
        #         print("my:", my)
        #         print("std:", ans)
        #         break
        # print("AC")