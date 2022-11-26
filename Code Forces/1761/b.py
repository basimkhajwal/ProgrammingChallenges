for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    s = len(set(a))
    if s == 2:
        print(2+(n-2)//2)
    else:
        print(n)
