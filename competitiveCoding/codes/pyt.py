def is_power_of_2(n):
    if n <= 0:
        return True
    # Count the number of set bits (1s) in the binary representation of n
    count = bin(n).count('1')
    # If there is only one set bit, it's a power of 2
    return count == 1

def count1(a,b):
    count = 0
    for a1,b1 in zip(a,b):
        val = a1^b1
        if val == 1:
            count +=1 
    return count

def find_mex(arr):
    n = len(arr)
    sumy = sum(arr)
    return n*(n+1)//2 - sumy

def solve(ve):
    
def run():
    a,b = map(int,input().split())
    # n = int(input())
    arr = list(map(int,input().split()))
    
    

    

for _ in range(int(input())):
    run()