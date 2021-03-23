import csv
import random
import xlsx

file = open("solu.csv","w+")
data = []
with open ("d_a.xlsx", "rt") as test:
    for x in test:
        x = x[0].split(",")


with open("test.csv", "rt") as tes:
    tes = csv.reader(tes, delimiter = ' ')
    u = 1
    for x in tes:
        r = ""
        if(u != 1):
            r = 1
        file.write(str(x[0]) + str(r) +"\n")
        u +=1

file .close()