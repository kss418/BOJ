import sys
input = sys.stdin.readline
n = int(input().rstrip())
a = [int(input().rstrip()) for _ in range(n)]

st = []
result = 0

def comp():
    if len(st) <= 1:
        return
    
    top = st.pop()
    if st[-1][0] != top[0]:
        st.append(top)
        return

    num = st[-1][1] + top[1]
    st.pop()
    st.append((top[0], num))

for i in a:
    while len(st) and st[-1][0] < i:
        result += st[-1][1]
        st.pop()

    if len(st) == 0 or st[-1][0] != i:
        st.append((i, 1))
    else:
        num = st[-1][1] + 1
        st.pop()
        st.append((i, num))
        result += num - 1

    comp()

    if(len(st) >= 2):
        result += 1

print(result) 