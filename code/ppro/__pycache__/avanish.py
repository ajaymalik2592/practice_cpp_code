from sys import stdin, stdout  
bi = [0] * 100005
pr = [0] * 100005
def sum(a):
    ans = 0
    while(a > 0):
        ans += bi[a]
        a -= a&(-a)
    return ans
def set(a):
    while(a < 100001):
        bi[a] += 1
        a += a & (-a)
pr[1] = 1
for x in range(2, 100001):
    if(pr[x] == 0):
        for y in range(x, 100001, x):
            if(pr[y] == 0):
                pr[y] = x

for _ in range(int(input())):
    a = [int(x) for x in stdin.readline().split()]
    if(a[0] == 1):
        a1 = a[1]
        while(a1 > 1):
            first = pr[a1]
            while(a1 % first == 0):
                a1 //= first
            set(first)
    else:
        l , r = a[1], a[2]
        print(sum(r) -  sum(l-1))
            
