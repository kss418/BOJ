n = int(input())

stack = []
result = []
use = 1


for i in range(n):
    x = int(input())
    while(use <= x):
        stack.append(use)
        use += 1
        result.append('+')
    
    if(len(stack) == 0 or stack[-1] != x):
        print("NO")
        exit(0)
    
    stack.pop()
    result.append('-')

for i in result:
    print(i)