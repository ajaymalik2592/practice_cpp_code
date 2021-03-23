import math
def order(A, B):
        arr = []
        a = []
        a1 = []
        a2 = []
        for x in range(len(A)):
            arr.append([A[x], B[x]])
            a.append(0)
            a1.append(0)
            a2.append(0)
        arr = sorted(arr)
        h = 0
        j = int(math.sqrt(len(A))) + 1;
        k = j
        for x in arr:
            l = x[1]
            l1 = 0
            for y in range(j):
                if(l1 + k - a1[y] < l):
                    l1 += k - a1[y]
                else:
                    a1[y]+=1
                    g = k * y 
                    for v in range(g, g + k):
                        if(l1 + a2[v] < l1):
                            l1 += 1
                        else:
                            a[v] = x[0]
                            a2[v] = 1
                            break
                    break
            
            

        return a
                    
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

print(order(A,B))
