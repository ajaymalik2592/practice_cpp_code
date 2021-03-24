n = int(input())
a = list(map(int, input().split()))
a.sort(reverse=True)
cp = 0
cn = 0
for i in range(n):
    if a[i] >= 0:
        cp += 1
    elif a[i] < 0:
        cn += 1


if len(a) % 2 == 0:
    if cp % 2 == 0 and cn % 2 == 0:
        for i in range(n):
            if a[i] > 0:
                a[i] = -a[i] - 1
    elif cp % 2 != 0 and cn % 2 != 0:
        for i in range(cp + 1, n):
            if a[i] < 0:
                a[i] = -a[i] - 1
        k = -a[cp - 1] - 1
        if k > a[cp]:
            a[cp - 1] = -a[cp - 1] - 1
            a[cp] = -a[cp] - 1
else:
    if cp % 2 == 0 and cn % 2 != 0:
        for i in range(cp + 1, n):
            if a[i] < 0:
                a[i] = -a[i] - 1
        k = -a[cp - 1] - 1
        if k > a[cp]:
            a[cp - 1] = -a[cp - 1] - 1
            a[cp] = -a[cp] - 1
    elif cp % 2 != 0 and cn % 2 == 0:
        for i in range(cp - 1):
            if a[i] > 0:
                a[i] = -a[i] - 1

for i in range(n):
    print(a[i], end=" ")
