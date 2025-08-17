memo = {}
def p(r, b):
    if b == 0: return 0
    if r == 0: return 1
    if (r, b) not in memo:
        d = (r+b)*(r+b-1)
        x = r*(r-1)/d
        y = b*(b-1)/d
        memo[(r, b)] = (x * p(r-2, b) + (1 - x - y) * p(r, b - 1)) / (1 - y)
    return memo[(r, b)]

def solve(r, b):
    # avoid recursion depth exceeded
    for i in range(0, r+1, 2):
        for j in range(b+1):
            p(i, j)
    print("p(%d, %d) = %f" % (r, b, round(p(r, b), 10)))

if __name__ == "__main__":
    solve(2, 2)
    solve(10, 9)
    solve(34, 25)
    solve(24690, 12345)