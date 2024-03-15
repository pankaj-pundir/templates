def bin_search(arr,val):
    l = 0
    r = len(arr)-1
    while l<=r:
        mid = l+(r-l)//2
        if arr[mid] == val:
            return mid
        elif arr[mid] < val:
            l = mid+1
        else:
            r = mid -1

    return max(l-1,0)

def run():
    li = []
    n = int(input())
    pt_li = []
    li_st = []

    for i in range(n):
        p1,p2 = map(int,input().split())
        pt_li.append((p1,p2))
        li.append(p2)
        li_st.append(p1)
    
    ans = 0
    li.sort()
    li_st.sort()
    print(li_st)
    print(li)
    for i1,i2 in pt_li:
        p1_st = bin_search(li_st,i1)
        p2_st = bin_search(li_st,i2) 

        p1_end = bin_search(li,i1)
        p2_end = bin_search(li,i2)
        print(p1_st,p2_st,p1_end,p2_end)
        ans += min((p2_st - p1_st) ,(p2_end - p1_end))
    
    print(ans)
    
       

for _ in range(int(input())):
    run()