arr = [int(x) for x in input().split()]
neg, po = 0, 0
for x in arr:
  if(x > 0):po+=1
  elif(x < 0):neg += 1
print("negative count " , neg, "positive count ", po)
