i = int("0b" + input(), 2)
import math

i1 = 0
j = 0
for x in range(1000):
    j = pow(4, x)
    if j < i:
        i1 += 1
    else:
        break
print(i1)
