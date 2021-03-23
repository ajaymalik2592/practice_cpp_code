def gcd(a,b):
    if(b == 0): return a
    else: return gcd(b, a%b)

for index in range(int(input())):
    n , l = [int(x) for x in input().strip().split()]
    li = [int(x) for x in input().strip().split()]

    pre = 0
    for x in range(len(li) -1):
        if (li[x] != li[x+1]):
            pre = x
            break
    
        
    d = gcd(li[pre], li[pre+1])
    find1 = [d]
    for x in range( pre, -1 , -1):
        d = li[x] // d
        find1.append(d)
    d = gcd(li[pre], li[pre+1])
    find = []
    for x in find1[::-1]:
        find.append(x)
     
    for x in range(pre+1,len(li)):
        find.append(li[x] // find[-1] )
    

    se = set()
    di = dict()
    for x in find:
        se.add(x)
    lis = []
    for x in se:
        lis.append(x)
    lis = sorted(lis)

    i = 0
    for x in lis:
        di.update({x : i})
        i += 1
    s = ": "
    for x in find:
        s += chr(65 + di[x])
    print("Case #"+str(index + 1)+s )
    
        
