from sys import stdin
global white,blue
n = int(stdin.readline())
arr = [[0]*n for _ in range(n)]
for i in range(n):
    arr[i] = list(map(int,stdin.readline().split()))

white = 0
blue = 0

def color(x,y,space):
    global white,blue
    if space == 1:
        if arr[y][x] == 1:
            blue += 1
        else:
            white += 1
    else:
        count = 0
        for i in range(space):
            count += sum(arr[y+i][x:x+space])
        if count == 0:
            white += 1
        elif count == space**2:
            blue += 1
        else:
            color(x,y,space//2)
            color(x+space//2,y,space//2)
            color(x,y+space//2,space//2)
            color(x+space//2,y+space//2,space//2)
color(0,0,n)
print(white)
print(blue)