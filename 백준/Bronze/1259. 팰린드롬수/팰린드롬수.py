while 1:
    n = int(input())
    if n == 0:
        break
    n = str(n)
    check = False
    for i in range(0, len(n)):
        if n[i] != n[len(n)-1-i]:
            check = True
    if check == True:
        print("no")
    else:
        print("yes")