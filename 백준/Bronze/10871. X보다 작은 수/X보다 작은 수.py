a,b = map(int,input().split())
arr = list(map(int,input().split()))
for i in arr:
    if i < b:
        print(i,end = " ")