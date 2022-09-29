from sys import stdin
a, b = map(int,stdin.readline().split())
num = [0]*a
for i in range(a):
    num[i] = int(stdin.readline())

st = 1
en = max(num)
while en >= st:
    mid = (en+st)//2
    sum = 0
    for i in range(a):
        sum += num[i]//mid
    if sum >= b:
        st = mid + 1
    else:
        en = mid - 1
print(en)