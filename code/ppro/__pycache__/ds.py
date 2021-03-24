d = 0
for x in range(46):
    for x2 in range(46):
        for x3 in range(46):
            for x4 in range(46):
                if (x + x2 + x3 + x4) >= 90:
                    d += 1

print(d)
