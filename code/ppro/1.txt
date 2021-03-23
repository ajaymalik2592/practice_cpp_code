primes = []
ma = 1000000000
for x in range(ma):
    primes.append(0)
se = []
for x in range(2,ma):
    if(primes[x] == 0):
        se.append(x)
        for y in range(x + x , ma, x):
            primes[y] = 1
d = ["3", "7", "109", "673"]
for x in se :
    s = str(x)
    l = 0
    for y in d:
        u = s + y
        u1 = y + s
        u1, u = int(u1), int(u)
        if(u < ma and u1 < ma and primes[u1] == 0 and primes[u] == 0):
          l+=1
    if(l == 4):
        d.append(s)
        break
print(d)
      
          
