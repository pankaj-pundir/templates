def mod_inverse(a, m):
    # Calculate the modular inverse of a modulo m using the extended Euclidean algorithm.
    g, x, y = extended_gcd(a, m)
    if g != 1:
        raise ValueError("The modular inverse does not exist.")
    else:
        return x % m

def extended_gcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = extended_gcd(b % a, a)
        return (g, y - (b // a) * x, x)


class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.rank = [0] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            if self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            elif self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1

n,q = map(int,input().split())
cost = list(map(int,input().split()))

ds = DisjointSet(n)
for i in range(q):
    a, b = map(int,input().split())
    # print(a,b)
    ds.union(a-1, b-1)

# print(ds.parent)
count_map = {}

for i in ds.parent:
    count_map[i] = count_map.get(i,0)+1
total_mul = 1

# print(count_map)

for k in count_map:
    total_mul *= count_map[k]

ans = 0
modulus = 998244353

for ind,val in enumerate(cost): 
    ans += (val*(total_mul//count_map[ds.parent[ind]]) % modulus)
    # print(val,count_map[ds.parent[ind]],ind)

# print(ans)
# print(total_mul)
# # Example usage:
# n = 5  # Number of elements


# # Initially, each element is in its own set
# # ds.parent = [0, 1, 2, 3, 4]

#  # Union elements 0 and 1
# ds.union(2, 3)  # Union elements 2 and 3

# # After unions, ds.parent will be modified accordingly:
# # ds.parent = [0, 0, 2, 2, 4]

# # Check if two elements are in the same set
# print(ds.find(0) == ds.find(1))  # True
# print(ds.find(1) == ds.find(2))  # False
# print(ds.find(2) == ds.find(3))  # True
# print(ds.find(3) == ds.find(4))  # False



p = ans  # Replace with your value of p
q = total_mul   # Replace with your value of q


q_inverse = mod_inverse(q, modulus)
M = (p * q_inverse) % modulus
print(M)