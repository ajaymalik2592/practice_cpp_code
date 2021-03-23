n = int(input())
a = []
for x in range(n):
  b = [int(xx) for xx in input().split()]
  a.append(b)
a.sort(key = lambda x : x[1])
#print(a)

i = 0
k = 1
for x in a:
  if(i + x[0] > x[1]):
    k = 0
    break
  i = i + x[0]
if(k == 1):print("Yes")
else:print("No")
