from collections import deque
word = input()
stack = deque(word)
cnt = 0
ppap = 1


while stack:
    cur = stack.popleft()
    if (cur == "P"):
        cnt += 1
    else:
        if (stack and cnt >= 2):
            cur = stack.popleft()
            if (cur == "P"):
                cnt -= 1
            else:
                ppap = 0
                break
        else:
            ppap = 0
            break
                
if (cnt == 1 and ppap == 1):
    print("PPAP")
else:
    print("NP")