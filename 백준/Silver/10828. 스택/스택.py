import sys

stack = []
n = int(input())

for _ in range(n):
    com = list(map(str, input().split())) # 명령어 입력
    if com[0] == "push":
        stack.append(int(com[1]))  # 스택에 데이터 삽입
    elif com[0] == "pop": 
        if len(stack): #스택에 데이터가 있으면
            print(stack.pop())  # pop 연산 및 마지막 데이터 출력
        else:
            print(-1) # -1 출력
    elif com[0] == "size": 
        print(len(stack))  # size 출력
    elif com[0] == "empty": 
        if(len(stack)): # 스택에 데이터가 있으면
            print(0) # 0 출력
        else: 
            print(1) # 1 출력
    elif com[0] == "top": 
        if (len(stack)): # 스택에 데이터가 있으면 
            print(stack[-1])  # top 연산
        else:
            print(-1) # -1 출력


