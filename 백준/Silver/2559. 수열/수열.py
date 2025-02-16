from sys import stdin
n,k = map(int,stdin.readline().split())
arr = list(map(int,stdin.readline().split()))
sumlist = [-200*k]*(n-k+1)
sumlist[0] = 0
for i in range(k):
    sumlist[0] += arr[i]
for i in range(1,n-k+1):
        sumlist[i] = sumlist[i-1] - arr[i-1] + arr[i+k-1]
print(max(sumlist))