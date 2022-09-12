n = int(input())
mylist = []
for i in range(n):
    a = int(input())
    if a == 0:
        mylist.pop()
    else:
        mylist.append(a)
print(sum(mylist))