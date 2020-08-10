MOD = 10**9+7

def fac(a):
    ans = 1
    for i in range(1,a+1):
        ans = (ans*i)%MOD
    return ans

def modInv(a):
    return pow(a,MOD-2,MOD)
def comb(a,b):
    return fac(a)*modInv(fac(b)*fac(a-b)%MOD)%MOD

def soln():
    n = int(input())
    # n,m = map(int,input().split())
    # li = []

    m = (n-2)*(n-1)
    kk = comb(n,n-3)
    print(m*kk % MOD)
    return 
    # k = n-2


# for i in range(int(input())):
soln()