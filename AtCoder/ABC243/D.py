# n = int(input())
# x = int(input())
tmp = input().split()
n = int(tmp[0])
x= int(tmp[1])
# input string
s = input()
for i in s:
    if i == 'U':
        x = x // 2
    elif i == 'L':
        x = x * 2
    else:
        x = x * 2 + 1
print(x)