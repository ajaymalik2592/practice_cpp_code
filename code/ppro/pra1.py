n , m = [int(x) for x in raw_input().split()]
arr = [int(x) for x in raw_input().split()]
ans = 1
for x in arr:
  ans =ans *  x
f, l = 1, ans
i = ans
index  = 1
for y in range(n):
  f = f * arr[y]
  l = l / arr[y]
  po = abs(l - f )
  if( po < i ):
    index = y + 1
    i = po
  else:
    f = f / arr[y]
    l = l * arr[y]
    break


for x in range(m):
  a = [int(x1) for x1 in raw_input().split()]
  if(a[0] == 2):
    if( f > l):
      po= abs(f-l)
      f1 , l1 = f ,l
      index1 = index
      while(f1 >= l1):
        f1 = f1/arr[index1-1]
        l1 = l1 * arr[index1-1]
        index1 -= 1
        z = abs(f1-l1)
        if( z <= po):
          po = z
          index = max(1, index1)
          l, f = l1, f1
    else:
      po= abs(f-l)
      f1 , l1 = f ,l
      index1 = index
      while(f1 <= l1 and index1 < n):
        f1 = f1*arr[index1]
        l1 = l1 / arr[index1]
        index1 += 1
        z = abs(f1-l1)
        if( z <= po):
          po = z
          index = min(n, index1)
          l, f = l1, f1

    print(index)
      
  else:
    arr[a[1]-1] = arr[a[1] -1] * a[2]
    if(a[1] > index):
      l = l * a[2]
    else:
      f = f * a[2]
    
    
