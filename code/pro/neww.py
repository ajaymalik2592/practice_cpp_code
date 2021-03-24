f = open('ass.txt')
r = []
for x in f:
    y = x.split()
    for xx in y:
        r.append(xx)
r = [int(x) for x in r]
print(r, len(r))
