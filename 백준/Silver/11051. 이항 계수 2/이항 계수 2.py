from sys import stdin
n,k = map(int,stdin.readline().split())
facn = 1
fack = 1
facnk = 1
for i in range(1,n+1):
    facn *= i
for i in range(1,k+1):
    fack *= i
for i in range(1,n-k+1):
    facnk *= i
result = facn//(fack*facnk)%10007
print(result)