from sys import stdin, stdout

n = int(stdin.readline())
arr = []
row = [[0, 0] for x in range(n + 2)]
col = [[0, 0] for x in range(n + 2)]

for x in range(n):
    a = [int(a1) for a1 in stdin.readline().split()]
    arr.append(a)
q = int(stdin.readline())
while q > 0:
    q -= 1
    a = [int(a1) for a1 in stdin.readline().split()]
    if a[0] == 1:
        row[a[1]][1] ^= a[-1]
        row[a[2]][0] ^= a[-1]
    else:
        col[a[1]][1] ^= a[-1]
        col[a[2]][0] ^= a[-1]
i = 0
for x in range(1, n + 1):
    arr[x - 1][x - 1] ^= col[x][1] ^ row[x][1]
    col[x + 1][1] ^= col[x][1] ^ col[x][0]
    row[x + 1][1] ^= row[x][1] ^ row[x][0]

    i = i + arr[x - 1][x - 1]

print(i)
