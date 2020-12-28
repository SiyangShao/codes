def factorial_last_nine_digits(n):
    factorial = 1
    for i in range(1, n + 1):
        factorial *= i
    last_nine_digits = factorial % 10**9
    formatted_last_nine_digits = f"{last_nine_digits:09d}"
    return formatted_last_nine_digits

n = int(input())
if n >= 100:
    n = 100
print(factorial_last_nine_digits(n))
