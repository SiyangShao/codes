import subprocess
import random

T = 1


def generate_random_permutation(n):
    permutation = list(range(1, n + 1))
    random.shuffle(permutation)
    return permutation


def check(p):
    for i in range(len(p)):
        num = 0
        for j in p:
            if j < p[i]:
                num += 1
        if i == num:
            return False
    return True


def get_ans(p):
    ans = 0
    for i in range(len(p)):
        for j in range(i, len(p)):
            if check(p[i: j + 1]):
                ans += 1
    return ans


def get_ans_ans(p):
    ans = 0
    for i in range(len(p)):
        for j in range(i, len(p)):
            if check(p[i: j + 1]):
                print(p[i: j + 1])
                ans += 1
    return ans


if __name__ == "__main__":
    while True:
        n = 200
        p = generate_random_permutation(n)
        with open("h.in", "w") as f:
            print(T, file=f)
            print(n, file=f)
            print(*p, file=f)
        subprocess.run(["./D"])
        with open("h.out", "r") as f:
            ans = int(f.read())
        if ans != get_ans(p):
            print("Wrong Answer")
            print("find:", ans)
            print("expect:", get_ans(p))
            get_ans_ans(p)
            exit(0)
        print("Accepted")
