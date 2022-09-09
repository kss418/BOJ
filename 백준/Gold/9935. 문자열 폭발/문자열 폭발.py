word = input()
expl = input()
arr = []
for i in word:
    arr.append(i)
    if expl[-1] == i and "".join(arr[-len(expl):]) == expl:
        del arr[-len(expl):]
if arr:
    print("".join(arr))
else:
    print("FRULA")
