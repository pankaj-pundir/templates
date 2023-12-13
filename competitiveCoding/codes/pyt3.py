def remove_duplicate_multiple_of_2(arr):
    arr = sorted(arr)
    count = 1
    past = arr[0]
    res = []
    # print(arr)
    for i in range(1,len(arr)):
        if arr[i] == past:
            count += 1
        else:
            if count%2 ==1:
                res.append(past)
            past = arr[i]
            count = 1
    if count%2 ==1:
        res.append(past)
    return res
    
def apply_shift(flips,arr):
    for i in flips:
        for j in range(i-1,len(arr),i):
            arr[j] = arr[j] ^ 1
    return arr

def count_to_zero(arr,mapy):
    count = 0
    for i in range(len(arr)):
        if arr[i] ==1:
           arr = apply_shift([i+1],arr)
           count +=1
           if mapy.get("".join(list(map(str,arr))),-1) != -1:
               return count+mapy.get("".join(list(map(str,arr))))
    return count

def run():
    n = int(input())
    arr = [int(i) for i in input()]
    q = int(input())
    q_arr = []
    county = 0
    mapy = {}
    for i in range(q):
        # q_arr.append(int(input()))
        arr = apply_shift([int(input())],arr)
        keys = "".join(list(map(str,arr)))
        if mapy.get(keys,-1) == -1:
            count_ = count_to_zero([i for i in arr],mapy)
            mapy[keys] = count_
        # print(count_)
        county += mapy[keys]

    return county

for _ in range(int(input())):
    print(f"Case #{_+1}: {run()}")