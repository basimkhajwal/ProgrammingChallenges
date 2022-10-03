for t in range(int(input())):
    n = int(input())
    d = list(map(int,input().split()))

    a = [d[0]]
    ambig = False
    for di in d[1:]:
        if di > 0 and di <= a[-1]: ambig = True
        a.append(a[-1]+di)
    print(*([-1] if ambig else a))
