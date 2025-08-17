def solve(n):
    M = 10**n
    a = 2
    total = 0
    while a * a < M:
        k = 1 # no b digits
        while (N := 10**k) * a < M:
            l = 10**(k-1)
            u = N
            while u-l > 1:
                m = (l + u) // 2
                lhs = (a + m) ** 2
                rhs = N * a + m
                if lhs <= rhs: l = m
                else: u = m

            lhs = (a + l) ** 2
            rhs = N * a + l
            if lhs == rhs: total += lhs
            k += 1
        a += 2
    return total

if __name__ == "__main__":
    print(solve(4))
    print(solve(16))