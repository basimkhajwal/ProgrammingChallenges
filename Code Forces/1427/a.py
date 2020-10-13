for _ in range(int(input())):
    n = int(input())
    a = [*map(int,input().split())]
    v = sum(a)

    if v==0:
        print("NO")
    else:
        print("YES")
        a.sort()
        if v > 0: print(*a[::-1])
        else: print(*a)
