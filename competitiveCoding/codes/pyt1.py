
for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    miny = arr[0]
    # 2 1
    # downward trend
    down_trend_idx = 0
    for i in range(n-1):
        if  arr[i] - arr[i+1]  > 0:
            down_trend_idx +=1
            miny = min(arr[i+1],miny)
        else:
            break
    # print(f"down_trend_idx {down_trend_idx}")
    if down_trend_idx == n-2:
        if arr[down_trend_idx+1] - arr[down_trend_idx] > 0:
            ans +=1
        # print(f"down_trend_ from here ")
        print(ans)
        continue
    
    # print(f"minu {miny}")
    if down_trend_idx == n-1:
        print(0)
        # print(f"down_trend_ from here 32324 ")
        continue

    ans +=1
    for i in range(down_trend_idx+1,n-1):
        if  arr[i] - arr[i+1]  > 0 and arr[i+1]>miny:
            ans +=1
        else:
            break
    print(ans)
    continue
