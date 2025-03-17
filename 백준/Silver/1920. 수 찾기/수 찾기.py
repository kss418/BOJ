import sys
input = sys.stdin.readline

def binary_search(x, size):
    lo = 0
    hi = size - 1 # A의 크기가 size 이므로 hi = size - 1
    ret = -1 # A에 x가 존재하지 않을 경우 -1 반환

    while lo <= hi: # 시작점이 끝점보다 커지면 종료
        mid = (lo + hi) // 2 # 중간값
        if a[mid] == x: # 현재 값이 탐색하고 있는 값이면
            ret = mid # 정답은 mid
            break # while문 종료

        if a[mid] > x: # 현재 값이 탐색하고 있는 값보다 크면
            hi = mid - 1 # mid 이상의 인덱스에는 x가 없음
        else: # 현재 값이 탐색하고 있는 값보다 작으면
            lo = mid + 1 # mid 이하의 인덱스에는 x가 없음

    return ret

n = int(input())
a = list(map(int, input().split()))
a.sort() # 이분탐색을 사용하기 위해선 정렬 해야함

m = int(input())
x = list(map(int, input().split()))

for i in range(m):
    ret = binary_search(x[i], n) # 이분탐색 값
    if ret == -1: # -1 이면 A에 X가 없음
        print(0) 
    else: # 아니면 A에 X가 있음
        print(1)

