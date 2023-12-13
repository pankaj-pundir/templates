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

def bit_xor(a):
    t_xor = a[0]
    for i in range(1,   len(a)):
        t_xor ^= a[i]
    return t_xor

def bit_or(a):
    t_or = a[0]
    for i in range(1,len(a)):
        t_or |= a[i]
    return t_or
    
def count_one_bit(num1):
    # Initialize a count variable to track the number of bits
    count = 0

    # Iterate through the bits of num1 from right to left
    while num1 > 0:
        # Check if the rightmost bit is 1
        if num1 & 1 == 1:
            # Increment the count
            count += 1
        # Right shift num1 to examine the next bit
        num1 >>= 1
    return count

def or_operation_and_count_bits(num1, num2):
    # Perform bitwise OR operation
    print(f"num1 =  num2 ", num1, num2)
    result = num1 | num2
    c_bit = count_one_bit(num1=num1)
    res = bin(result)[2:]
    res = res[len(res)-c_bit]
    print(f"res {res}")
    return res

def run():
    s_cost,d_cost,total_cost = map(int,input().split())

    total_cheese,total_buns = 0,0
    if s > 0:
        total_cheese += s
        total_buns += 2*s
    if d > 0:
        total_cheese += 2*d
        total_buns += 2*d
    
    if k <= total_cheese and k+1 <= total_buns:
        return "YES"
    return "NO"


for _ in range(int(input())):
    print(f"Case #{_+1}: {run()}")