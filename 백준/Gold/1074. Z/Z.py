import sys
input = sys.stdin.readline

def dnc(cur: int, cy: int, cx: int) -> int:
    # Base Case
    if cur == 1:
        return 2 * cy + cx

    # 현재 정사각형의 길이의 절반
    len = 1 << (cur - 1)

    # 왼쪽 dx = 0, 오른쪽 dx = 1
    # 위쪽 dy = 0, 아래쪽 dy = 1
    dy = cy // len
    dx = cx // len  

    # 현재 정사각형의 1/4의 크기에 위치를 곱해서 더함
    return dnc(cur - 1, cy % len, cx % len) + (2 * dy + dx) * len * len


n, m, k = map(int, input().split())
print(dnc(n, m, k))

