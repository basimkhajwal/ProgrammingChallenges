import itertools as it

def check(xs):
    s = 0
    for k in range(1,1+len(xs)):
        ss = [sum(ys) for ys in it.combinations(xs, k)]
        if min(ss)<= s: return False
        if len(set(ss)) < len(ss): return False
        s = max(ss)
    return True

t = 0

with open("p105_sets.txt", "r") as file:
    for line in file:
        xs = list(map(int,line.split(",")))
        if check(xs):
            t += sum(xs)

print(t)
