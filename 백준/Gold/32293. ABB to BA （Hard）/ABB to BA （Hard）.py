import sys
input = sys.stdin.readline

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    s = input().rstrip()
    st = []

    for i in s:
        st.append(i)
        cnt = 0

        while len(st) >= 3 and st[-3] == 'A' and st[-2] == 'B' and st[-1] == 'B':
            for _ in range(3):
                st.pop()
            
            cnt += 1
            st.append('B')

        for _ in range(cnt):
            st.append('A')
        
    print(*st, sep = '')


