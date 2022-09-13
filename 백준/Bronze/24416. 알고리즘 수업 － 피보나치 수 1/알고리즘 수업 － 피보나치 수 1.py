from sys import stdin
global check1,check2

fiblist = [0]*45
fiblist[1] = 1
fiblist[2] = 1

def fib(n):
    for i in range(3,n+1):
        fiblist[i] = fiblist[i-1] + fiblist[i-2]
    return fiblist[n]
    


            
n = int(stdin.readline())


print("%d %d"%(fib(n),n-2))