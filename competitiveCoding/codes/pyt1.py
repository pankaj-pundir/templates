N = 30000+5
xor = 0
dp = []
dp.append(0)
for i in range(N):
    xor = xor ^ i
    dp.append(xor)
    # if i < 30:
    #     print(i+1,xor)

for i in range(int(input())):
    a,b = map(int,input().split())
    # print(a,b,end=" -> ")
    if a == 1:
        if b ==0 :
            print(1)
            continue
        if  b==1:
            print(3)
        else:
            print(2)
        continue

    count = a+1
    # print("exp",a,dp[a])
    if b == dp[a]:
        count = a
    elif dp[a] == 0 and a != b:
        count = a+1

    elif dp[a]==0 and a == b:
        count = a+2

    print(count)

    