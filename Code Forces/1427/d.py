
def solve(n, xs):
    if xs == sorted(xs):
        return []

    n_idx = [0] * (n+1)
    for i in range(n): n_idx[xs[i]] = i

    pos = None
    for i in range(n-1):
        if xs[i]+1==xs[i+1]:
            pos = i
            break

    if pos is None:
        pos = 1
        while n_idx[pos+1] >= n_idx[pos]: pos += 1
        a = n_idx[pos+1]
        b = n_idx[pos]

        op = [a, b-a, 1, n-b-1]
        op = [o for o in op if o > 0]

        ys = xs[b+1:] + xs[b:b+1] + xs[a:b] + xs[:a]
        return [op] + solve(n, ys)

    ys = xs.copy()
    for j in range(xs[pos]+1, n+1): ys[n_idx[j]] = j-1
    del ys[pos]

    ops = []
    for o in solve(n-1, ys):
        p = []
        t = 0
        new_pos = 0
        for x in o:
            if t <= pos < t+x:
                new_pos = pos-t
                x += 1
            else:
                new_pos += x
            p.append(x)
            t += x
        pos = new_pos
        ops.append(p)

    return ops

ops = solve(int(input()), list(map(int,input().split())))
print(len(ops))
for op in ops: print(len(op), *op)
