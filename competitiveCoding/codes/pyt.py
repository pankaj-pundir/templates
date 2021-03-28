
for _ in range(int(input())):
    x,r,m= map(int,input().split())
    r*=60
    m*=60
    req = min(r,x)
    ans = req+2*(r-req)
    if ans <= m:
        print("YES")
    else:
        print("NO")