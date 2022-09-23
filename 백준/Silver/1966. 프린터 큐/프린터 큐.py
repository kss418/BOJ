from sys import stdin
n = int(stdin.readline())
for i in range(n):
    a,b = map(int,stdin.readline().split())
    mylist = list(map(int,stdin.readline().split()))
    check = 0
    while True:
        if mylist[0] == max(mylist):
            check += 1
            if b == 0:
                print(check)
                break
            else:
                b -= 1
            mylist.pop(0)
        else:
            mylist.append(mylist.pop(0))
            if b == 0:
                b = len(mylist)-1
            else:
                b -= 1
