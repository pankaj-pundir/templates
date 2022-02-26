# def solve(arr,k):
#     arr = sorted(arr)

#     for i in arr:
#         if i >= k:
#             return "NO"

for _ in range(int(input())):
    h,v = map(int,input().split())
    if h==v:
        ans = "10"*(h+1)
    elif h < v:
        ans = "10"*(h+1)+"1"+"101"*(max(abs(h-v)-1,0))
    else:
        ans = "01"*(v+1)+"0"+"010"*(max(abs(h-v)-1,0))
    print(len(ans))
    print(ans)
        
    