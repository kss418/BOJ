import math
n = int(input())
result = n

for i in range(2,int(math.sqrt(n))+1):
    if (n%i == 0):
        n /= i
        result = result * (1 - 1/i)
    
    while(n%i == 0):
        n /= i

    if (n == 1):
        break

if (n>1):
    result = result * (1 - 1/n)

print(int(result))