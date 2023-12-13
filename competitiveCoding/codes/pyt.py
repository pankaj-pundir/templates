
def run():
    n = int(input())
    arr = list(map(int,input().split()))
    arr_ind = [(val,ind) for ind,val  in enumerate(arr)]
    arr_ind.sort()
    cumm = [0 for i in range(n)]
    cumm[0] = arr_ind[0][0]

    for i in range(1,n):
        cumm[i] = cumm[i-1]+ arr_ind[i][0]
    # print(cumm)
    result = [0 for i in range(n)]

    for i in range(n-1,-1,-1):
        if i == n-1:
            result[i] = i
        else:
            if cumm[i] >= arr_ind[i+1][0]:
                result[i] = result[i+1]
            else:
                result[i] = i
    
    gen = [0 for i in range(n)]


    for i in range(n):
        gen[arr_ind[i][1]] = result[i]

    print(" ".join(list(map(str,gen))))             


    
        
for _ in range(int(input())):
    run()