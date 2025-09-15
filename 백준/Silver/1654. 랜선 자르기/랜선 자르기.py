import sys


input = sys.stdin.read
lines = input().strip().splitlines()

K, N = map(int, lines[0].split())

numbers = [int(lines[i+1]) for i in range(K)]


front = 1
rear = 2**31 - 1
while True:
    if front >= rear:
        print(front)
        break
    mid = (front+rear+1) // 2
    result = 0
    for i in numbers:
        num = i // mid
        result+=num
    
    if result >= N:
        front = mid
    else:
        rear = mid-1