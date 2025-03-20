import sys
input = sys.stdin.readline

def chk(s):
    st = []
    for i in s:
        if i == '(' or i == '[':
            st.append(i)
        else:
            if len(st) == 0:
                return False
            
            if i == ')' and st[-1] == '[':
                return False
            elif i == ']' and st[-1] == '(':
                return False
            st.pop()
    
    return len(st) == 0

s = input().rstrip()
if not chk(s):
    print(0)
    exit(0)

result = [0] * 31
cnt = 0

for i in s:
    if i == '(' or i == '[':
        cnt += 1
    elif i == ')':
        cnt -= 1
        result[cnt] += 2 * max(result[cnt + 1], 1)
        result[cnt + 1] = 0
    else:
        cnt -= 1
        result[cnt] += 3 * max(result[cnt + 1], 1)
        result[cnt + 1] = 0

print(result[0])