for _ in range(int(input())):
    n = int(input())
    s = input()
    x = s.count("1")
    p = None
    l = 0
    max_l = 0
    for c in s:
        if c == p: l += 1
        else: l = 1
        p = c
        max_l = max(l, max_l)
    print(max(x*(n-x), max_l**2))
