from sys import stdin

n = int(stdin.readline())
mylist = [0]*1000001
mylist[1] = 1
mylist[2] = 2
if n>=3:
    for i in range(3,n+1):
        mylist[i] = (mylist[i-1]+mylist[i-2])%15746
print(mylist[n])
   