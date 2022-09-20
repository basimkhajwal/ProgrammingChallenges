# easy bruteforce

import time
import itertools as it

def check(xs):
    s = 0
    for k in range(1,1+len(xs)):
        ss = [sum(ys) for ys in it.combinations(xs, k)]
        if min(ss)<= s: return False
        if len(set(ss)) < len(ss): return False
        s = max(ss)
    return True


def go(n, max_score):

    best_xs = None
    best_score = max_score
    xs = []

    def solve():
        nonlocal xs, best_xs, best_score
        if len(xs) == n:
            if sum(xs) < best_score:
                best_score = sum(xs)
                best_xs = [*xs]
            return

        l = 1 if xs == [] else xs[-1]+1
        u = (best_score - sum(xs)) // (n-len(xs))
        for i in range(l, u):
            xs.append(i)
            if check(xs): solve()
            xs.pop()

    solve()

    return best_xs

xs = go(7, 256)
print(*xs,sep="")
