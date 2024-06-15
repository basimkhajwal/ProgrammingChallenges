def solve(n, k):
    m = n - k 
    a = t = k
    for b in range(60,-1,-1):
        x = 1 << b
        if m & x:
            a += x
            t += a
    return t

print(solve(10**17, 9**17))
