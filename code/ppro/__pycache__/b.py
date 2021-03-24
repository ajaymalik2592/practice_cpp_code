n = int(input())
a1 = input()
a = int(a1)
sum = a * 100
i = 1
for x in range(n - 1):
    i = i * 10
    if a1[n - 1 - x] == '0':
        continue
    sum = min(a // i + a % i, sum)
print(sum)
