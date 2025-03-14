n = int(input())
stack = []
a = []
result = [0] * n 

a = list(map(int, input().split()))

for i in range(n - 1, -1, -1):
    while len(stack) and stack[-1] <= a[i]:
        stack.pop()

    if(len(stack)):
        result[i] = stack[-1]
    else:
        result[i] = -1

    stack.append(a[i])

for i in range(n):
    print(result[i], end = ' ')