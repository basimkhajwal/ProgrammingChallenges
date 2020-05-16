def solve():
     u = int(input())
     d = {}
     c = set()
     for i in range(10000):
         q,r=input().split()
         c = c.union(set(r))
         d[r[0]] = d.get(r[0],0) + 1
     return ''.join(x for x in sorted(c,key=lambda x: -d.get(x,10000)))

for t in range(1,int(input())+1):
    print("Case #" + str(t) + ": " + solve())
