import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]
cnt = [0, 0, 0]

def dnc(cy, cx, sz):
    num = a[cy][cx]
    flag = True
    for i in range(cy, cy + sz):
        for j in range(cx, cx + sz):
            if a[i][j] != num:
                flag = False

    if flag:
        cnt[num + 1] += 1
        return

    nsz = sz // 3
    for i in range(3):
        for j in range(3):
            dnc(cy + i * nsz, cx + j * nsz, nsz)

dnc(0, 0, n)
print(cnt[0])
print(cnt[1])
print(cnt[2])
