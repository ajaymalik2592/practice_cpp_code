t = int(input())
for g in range(t):
    m = int(input())
    teams = []
    for x in range(1, m + 1):
        teams.append(x)
    arr = [[0 for y in range(m + 1)] for x in range(m + 1)]
    n = int(len(teams) / 2)

    stages = []

    for i in range(len(teams) - 1):
        t = teams[:1] + teams[-i:] + teams[1:-i] if i else teams
        stages.append(list(zip(t[:n], reversed(t[n:]))))
    j = 0

    def fun(a):
        return reversed(a)

    j = 2
    for a in stages:
        for c in a:
            u = fun(c)
            arr[c[0]][c[1]] = j
            arr[c[1]][c[0]] = j + m - 1
        j += 1
    for x in range(m):
        arr[x + 1][x + 1] = 1
    if m % 2 == 0 or m == 1:
        print("Hooray")
    else:
        print("Boo")
        continue
    for x in range(1, m + 1):
        for y in range(1, m + 1):
            print(arr[x][y], end=" ")
        print()
