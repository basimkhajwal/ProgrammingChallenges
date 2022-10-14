n = int(input())

i = 0
t = 0
double = False
switch = False
for a,b in zip(input(),input()):
    if a == '0' and b == '1' and (not double or i==1):
        if i != 0: switch = True
        else: switch = False
        i = 1
        t += 1
    elif a == '1' and b == '0' and (not double or i==0):
        if i != 1: switch = True
        else: switch = False
        i = 0
        t += 1
    elif a == '1' and b == '1': 
        if double or switch:
            t += 1
            double = False
            switch = False
        else:
            t += 2
            i = 1-i
            double = True
            switch = True

print(t)
