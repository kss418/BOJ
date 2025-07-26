import sys
input = sys.stdin.readline



n = int(input())
mylist = [0]*n
for i in range(n):
    mylist[i] = int(input())
mylist.sort()
for j in range(n):
    print(mylist[j])