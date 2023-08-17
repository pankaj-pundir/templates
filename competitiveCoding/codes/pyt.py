
for _ in range(int(input())):
    arr = list(input())
    if "".join(arr) == "()":
        print("NO")
        continue
    # just flip the alternate sign
    cond = False
    for i in range(len(arr)-1):
        if arr[i] == arr[i+1]:
            cond = True
        
    if cond:
        res = "()"*len(arr)
    else:
        res = "("*len(arr) + ")"*len(arr)
    print("YES")
    print(res)       