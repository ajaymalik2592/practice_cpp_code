f = open('INPUTFILE.py', 'r')
g = open('outputfile.txt', 'w')
pointer = 0
for x in f:
    e = x.split()

    if e[0] == "***" and e[1] == "START":
        print('{0:6s}{1:10s}{2:10s}{3:10s}'.format("", e[0], e[1], e[2]))
        pointer = int(e[2])

    elif e[0] != "***":
        y = str(pointer)
        print('{0:6s}{1:10s}{2:10s}{3:10s}'.format(y, e[0], e[1], e[2]))
        u = [e[0], pointer]

        s = '{0:10s}'.format(e[0]) + "   " + str(pointer) + "\n"

        g.write(s)

        if e[1] == "WORD":
            pointer += 3
        elif e[1] == "RESW":
            pointer += int(e[2]) * 3
        elif e[1] == "RESB":
            pointer += int(e[2])
        else:
            pointer += 1
    elif e[0] == "***":
        y = str(pointer)
        print('{0:6s}{1:10s}{2:10s}{3:10s}'.format(y, e[0], e[1], e[2]))
        pointer += 3


g.close()
f.close()
