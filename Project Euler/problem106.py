def solve(n):
    to_check = 0
    for i in range(1, 2**n):
        for j in range(i+1, 2**n):
            if i & j != 0: continue

            a = []
            b = []
            for k in range(n):
                if (i >> k) & 1: a.append(k)
                if (j >> k) & 1: b.append(k)
            if len(a) != len(b): continue

            a_lt_b = True
            b_lt_a = True
            for x,y in zip(a,b):
                a_lt_b = a_lt_b and x <= y
                b_lt_a = b_lt_a and y <= x

            if not (a_lt_b or b_lt_a):
                to_check += 1

    return to_check

print(solve(12))
