def run():
    n = int(input())
    arr = list(map(int, input().split(' ')))
    if sum(arr)/n == sum(arr)//n:
        return 0
    return 1

for _ in range(int(input())):
    print(run())