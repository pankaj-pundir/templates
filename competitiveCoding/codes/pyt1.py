def func(arr,l,r):
    if l == r:
        arr[l] = 0
        return 1
    miny = min(arr[l:r])
    # if miny == 0:
    #     return 0
    
    if miny > r-l+1:
        for i in range(l,r):
            arr[i] = 0
        return r-l+1
    
    for i in range(l,r):
        arr[i] -= miny
    return miny

def run():
    n = int(input())
    arr = list(map(int,input().split()))
    l = 0 
    r = n-1
    amount = 0
    if n == 1:
        print(1)
        return
    g_low = 0
    while max(arr) > 0:
        print("in loop",arr)
        l_ptr = g_low

        while l_ptr < len(arr) and arr[l_ptr] == 0:
            l_ptr +=1

        r_ptr = l_ptr
        while r_ptr < len(arr) and arr[r_ptr] != 0:
            r_ptr +=1
        print(f"trig {l_ptr} {r_ptr}")
        amount += func(arr,l_ptr,min(r_ptr,len(arr)))
        print(arr,amount)
        g_low = l_ptr

    print(amount)






for _ in range(int(input())):
    run()
    print("-================================================================")