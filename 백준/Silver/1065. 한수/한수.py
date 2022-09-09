from sys import stdin

n = int(stdin.readline())
count = 0
for i in range(1,n+1):
    k = str(i)
    check = 1
    if len(k) == 1 or len(k) == 2:
        count += 1
    else:
        diff = int(k[1]) - int(k[0])
        for j in range(1,len(k)-1):
            if diff != int(k[j+1]) - int(k[j]):
                check = 0
        if check == 1:
            count += 1

print(count)