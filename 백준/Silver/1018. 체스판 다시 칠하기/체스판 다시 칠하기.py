from sys import stdin
a,b = map(int,stdin.readline().split())
board = ["0"*b]*a
for i in range(a):
    board[i] = stdin.readline()
count = []
for j in range(a-7):
    for k in range(b-7):
        check1 = 0
        check2 = 0
        for x in range(j,j+8):
            for y in range(k,k+8):
                if (x+y) % 2 == 0 and board[x][y] == "W":
                    check1 += 1
                elif (x+y) % 2 == 0 and board[x][y] == "B":
                    check2 += 1
                if (x+y) % 2 == 1 and board[x][y] == "B":
                    check1 += 1
                elif (x+y) % 2 == 1 and board[x][y] == "W":
                    check2 += 1
        count.append(min(check1,check2))
print(min(count))
