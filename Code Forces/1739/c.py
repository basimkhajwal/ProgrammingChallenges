import math

MOD = 998244353 

# -> a win, b win, draw
def solve(n):
    if n == 0:
        return 0, 0, 1
    if n == 2:
        return 1, 0, 1
    
    # k = n choose (n/2) ways
    # k/2 in which a gets `n`
    # (n-2) choose (n/2) ways

    ways = math.comb(n, n//2)

    a_gets_n = math.comb(n-1, n//2-1)

    # n and n-1 or n and n-2
    b_win_immed = 2 * math.comb(n-2, n//2-2)
    if n >= 6: b_win_immed -= math.comb(n-3,n//2-3) 


    a,b,d = solve(n-4)

    b_wins = (b_win_immed + b) % MOD
    a_wins = ((ways - b_wins - 1) % MOD + MOD) % MOD
    d = d

    return a_wins, b_wins, d

for t in range(int(input())):
    print(*solve(int(input())))
