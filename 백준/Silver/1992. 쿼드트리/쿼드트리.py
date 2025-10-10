import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

MAX = 66
INF = 10**12
n = 0
st = []

def dnc(cy, cx, sz):
    flag = True
    num = st[cy][cx]
    for i in range(cy, cy + sz):
        for j in range(cx, cx + sz):
            if st[i][j] != num:
                flag = False
    if flag:
        print(num, end = '')
        return

    print("(", end = '')
    nsz = sz // 2
    for i in range(2):
        for j in range(2):
            dnc(cy + i * nsz, cx + j * nsz, nsz)
    print(")", end = '')


n = int(input().strip())
st = [input().strip() for _ in range(n)]
dnc(0, 0, n)

