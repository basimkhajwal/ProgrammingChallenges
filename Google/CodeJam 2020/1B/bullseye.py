from random import randrange
import sys
import math

L = 1000000000
hitFound = False
numQueries = 0

def dist2(p1, p2): return (p1[0]-p2[0])**2+(p1[1]-p2[1])**2

def add(p1, p2): return (p1[0]+p2[0],p1[1]+p2[1])

def mul(p1, x): return (p1[0]*x, p1[1]*x)

def midpoint(p1, p2): return mul(add(p1, p2), 0.5)

def perp(v):
    d = math.sqrt(v[0]**2+v[1]**2)
    return (v[1] / d, -v[0] / d)

def query(p):
    global numQueries, hitFound
    print(int(p[0]), int(p[1]), flush=True)
    k = input()
    numQueries += 1
    if k == "CENTER" or numQueries == 300:
        debug("Done")
        hitFound = True
    return k

def debug(msg):
    #print(msg, file=sys.stderr)
    pass

def getPoints(numHits, numMisses):
    global hitFound
    hits = []
    misses = []
    while len(hits) < numHits or len(misses) < numMisses:
        p = (randrange(-L,L+1), randrange(-L,L+1))
        if query(p) == "MISS": misses.append(p)
        else: hits.append(p)
        if hitFound: return [[],[]]
    return [hits[:numHits], misses[:numMisses]]

def findBoundary(hit, miss):
    global hitFound
    while dist2(hit, miss) > 2:
        mid = midpoint(hit, miss)
        if query(mid) == "MISS":
            miss = mid
        else:
            hit = mid
        if hitFound: return hit
    return hit

def solve_eqn(A, B, C):
    det = A[0]*B[1]-A[1]*B[0]
    t = B[1] * C[0] - B[0] * C[1]
    debug("Det")
    debug(det)
    return t / det

def solve(A, B):
    global hitFound
    debug("Solving...")
    H, M = getPoints(1, 3)
    if hitFound: return
    bounds = []
    for m in M:
        bounds.append(findBoundary(H[0], m))
        if hitFound: return

    m1 = midpoint(bounds[0], bounds[1])
    m2 = midpoint(bounds[0], bounds[2])
    p1 = perp(add(bounds[0], mul(bounds[1], -1)))
    p2 = perp(add(bounds[0], mul(bounds[2], -1)))
    t = solve_eqn(p1, mul(p2, -1), add(m2, mul(m1, -1)))
    pt = add(m1, mul(p1, t))

    debug("Calc")
    debug(m1)
    debug(p1)
    debug(m2)
    debug(p2)
    debug(t)
    debug("Done:")
    debug(pt)
    for r in range(0,1000,2):
        x,y=int(pt[0])-r//2,int(pt[1])-r//2
        for i in range(r+1):
            for q in set([(x+i, y), (x+r,y+i), (x+r-i,y+r), (x, y+r-i)]):
                debug(q)
                query(q)
                if hitFound:
                    return

if __name__ == "__main__":
    T, A, B = map(int,input().split())
    for t in range(1,T+1):
        solve(A, B)
        hitFound = False
        numQueries = 0
