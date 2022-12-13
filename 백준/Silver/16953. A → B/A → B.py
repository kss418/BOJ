a,b = map(int,input().split())
count = 1
while b != a:
    if  b == 1:
        count = -1
        break
    elif b% 10 == 1:
        b = (b-1)//10
        count += 1
    elif b % 2 == 0:
        b //= 2
        count += 1
    else:
        count = -1
        break
print(count)