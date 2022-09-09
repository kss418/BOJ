from sys import stdin
from collections import deque
q = deque()
n = int(stdin.readline())

x1 = [0,0,-1,1]
y1 = [1,-1,0,0]

visited_n = [[0]*n for _ in range(n)]
visited_c = [[0]*n for _ in range(n)]
arr = [["0"] for _ in range(n)]

for i in range(n):
    arr[i] = stdin.readline()

def bfs_n(x,y):
    visited_n[x][y] = 1
    color = arr[x][y]
    q.append((x,y))
    while q:
        a,b = q.popleft()
        for i in range(4):
            curx = x1[i]+a
            cury = y1[i]+b
            if curx < 0 or cury < 0 or curx >= n or cury >= n or visited_n[curx][cury] == 1 or arr[curx][cury] != color:
                continue
            visited_n[curx][cury] = 1
            q.append((curx,cury))


def bfs_c(x,y):
    visited_c[x][y] = 1
    color = arr[x][y]
    q.append((x,y))
    while q:
        a,b = q.popleft()
        for i in range(4):
            curx = x1[i]+a
            cury = y1[i]+b
            if curx < 0 or cury < 0 or curx >= n or cury >= n or visited_c[curx][cury] == 1:
                continue
            if color == "R" or color == "G":
                if arr[curx][cury] == "R" or arr[curx][cury] == "G":
                    visited_c[curx][cury] = 1
                    q.append((curx,cury))
            else:
                if arr[curx][cury] == "B":
                    visited_c[curx][cury] = 1
                    q.append((curx,cury))

t = 0
c = 0

for i in range(n):
    for j in range(n):
        if visited_n[i][j] == 0:
            t += 1
            bfs_n(i,j)
        if visited_c[i][j] == 0:
            c += 1
            bfs_c(i,j)
            
print("%d %d"%(t,c))