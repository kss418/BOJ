import sys
input = sys.stdin.readline

n = int(input())
origlist = list(map(int,input().split()))
changelist = []
for i in range(len(origlist)):
    changelist.append(origlist[i]/max(origlist)*100)
print(sum(changelist)/n)