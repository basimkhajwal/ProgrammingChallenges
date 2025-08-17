def solve(n, M = 1234567891):
    # t = sum( 2^(n-1) - 2^(n-n//k) for k in range(1, n+1))

    # transposed for unique values of q = n//k : 
    p = pow(2, n-1, M)
    t = 0
    next_k = 1
    while (q := n // next_k) > 1:
        l = next_k
        u = n
        # u = min s.t. n // u < q
        while u-l > 1:
            m = (u+l) // 2
            if n // m < q : u = m
            else : l = m
        A = u*(u-1)//2 - next_k*(next_k-1)//2
        t0 = (A % M) * (p - pow(2, n-q, M))
        t = (t + t0) % M
        next_k = u
    return t


if __name__ == "__main__":
    print(solve(10))
    print(solve(10**14))