def prime_factors(n):
    factors = []
    divisor = 2

    while divisor <= n:
        if n % divisor == 0:
            factors.append(divisor)
            n //= divisor
        else:
            divisor += 1

    return factors


import math

def sieve_eratosthenes(limit):
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False
    primes = []

    for current in range(2, int(math.sqrt(limit)) + 1):
        if sieve[current]:
            primes.append(current)
            for multiple in range(current * current, limit + 1, current):
                sieve[multiple] = False

    for candidate in range(int(math.sqrt(limit)) + 1, limit + 1):
        if sieve[candidate]:
            primes.append(candidate)

    return primes

def prime_factors_with_precomputed_primes(n, primes):
    factors = []
    for prime in primes:
        while n % prime == 0:
            factors.append(prime)
            n //= prime
        if n == 1:
            break

    if n > 1:
        factors.append(n)

    return factors

# Precompute prime numbers up to a suitable limit (adjust as needed)
primes = sieve_eratosthenes(10000)

# Example usage:
# num = 56
# prime_factors = prime_factors_with_precomputed_primes(num, primes)
# print(f"Prime factors of {num}: {prime_factors}")


# def select_factors(factors):
#     ans = []
#     sumy = 0
#     for i in range(len(factors)):
#         if factors[i] >

def minimize_arr(factors,ones):
    total_removed_ones = -1
    pos = None
    for i in range(len(factors)):
        for j in range(len(factors)-1,i,-1):  
            if factors[i]*factors[j] - factors[i]-factors[j] > (41 - sum(factors)):
                # print(f" breaking {i} {j} ")
                continue

            removed_ones = factors[i]*factors[j] - factors[i]-factors[j]
            if removed_ones > total_removed_ones:
                # print(f" setting {i} {j} ")
                total_removed_ones = factors[i]*factors[j] - factors[i]-factors[j]
                pos = (i,j)
    if pos == None:
        return factors
    mul = factors[pos[0]]*factors[pos[1]]
    factors.append(mul)
    factors.pop(pos[1])
    factors.pop(pos[0])

    return sorted(factors)

# arr = [2, 2, 2, 9,26]

# res = minimize_arr(arr,0)
# print(res)

def run():
    n = int(input())
    factors = prime_factors_with_precomputed_primes(n,primes=primes)
    # factors = select_factors(factors=factors[::-1])
    sumy = sum(factors) 
    if sumy > 41:
        return -1
    if sumy == 41 and len(factors) <=100:
        return f"{len(factors)} {' '.join(list(map(str,factors)))}"
    
    req_ones = 41 - sumy
    # print(factors,req_ones)
    while True:
        factors_temp = minimize_arr([i for i in factors],req_ones)
        # print(factors,factors_temp,req_ones)
        if factors_temp == factors:
            break
        factors = factors_temp
        req_ones = 41 - sum(factors)
    # factors = minimize_arr(factors,req_ones) 
    # print(factors)
    

    req_ones = 41 - sum(factors) 
    if len(factors)+req_ones > 100:
        return -1
    return f"{len(factors)+req_ones} {' '.join(list(map(str,factors)))} {' '.join(['1' for i in range(req_ones)])}"



for _ in range(int(input())):
    print(f"Case #{_+1}: {run()}")