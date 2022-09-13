from sys import stdin


n = int(stdin.readline())


for i in range(n):
    num = int(stdin.readline())
    if num < 2:
        fib0 = [1,0]
        fib1 = [0,1]
    else:
        fib0 = [0]*(num+1)
        fib1 = [0]*(num+1)
        fib0[0] = 1
        fib0[1] = 0
        fib1[0] = 0
        fib1[1] = 1
        for i in range(2,num+1):
            fib0[i] = fib0[i-1] + fib0[i-2]
            fib1[i] = fib1[i-1] + fib1[i-2]
    print("%d %d"%(fib0[num],fib1[num]))