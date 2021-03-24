vec = [[] for x in range(1000001)]
for x in range(1, 1000001):
    for y in range(x, 1000001, x):
        vec[y].append(x)
for x in range(int(input())):
    n = int(input())
    arr = [int(m) for m in input().split()]
    pop = [0] * 1000001
    ans = 0
    for y in arr:
        ans = max(ans, pop[y])
        for g in vec[y]:
            pop[g] += 1
    print(ans)
