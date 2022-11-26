for _ in range(int(input())):
    n, a, b = map(int, input().split())
    c = (a == n and b == n) or (a + b < n-1)
    print("Yes" if c else "No")
