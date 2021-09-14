# hacker cup 

from collections import Counter


MAXY_CONSTANT = 1e9+7
dp = {}


def floydWarshall(graph,V):
   
    """ dist[][] will be the output
       matrix that will finally
        have the shortest distances
        between every pair of vertices """
    """ initializing the solution matrix
    same as input graph matrix
    OR we can say that the initial
    values of shortest distances
    are based on shortest paths considering no
    intermediate vertices """
 
    dist = list(map(lambda i: list(map(lambda j: j, i)), graph))
 
    """ Add all vertices one by one
    to the set of intermediate
     vertices.
     ---> Before start of an iteration,
     we have shortest distances
     between all pairs of vertices
     such that the shortest
     distances consider only the
     vertices in the set
    {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a
      iteration, vertex no. k is
     added to the set of intermediate
     vertices and the
    set becomes {0, 1, 2, .. k}
    """
    for k in range(V):
 
        # pick all vertices as source one by one
        for i in range(V):
 
            # Pick all vertices as destination for the
            # above picked source
            for j in range(V):
 
                # If vertex k is on the shortest path from
                # i to j, then update the value of dist[i][j]
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]
                                 )
    return dist

def conversionPossible(start,end,dic,visited):
    # return min
    if (start not in dic.keys() ) or (start in visited):
        return -1

    if end in dic[start]:
        # print("found ",end,start)
        return 1
    # print("recursive ",start,end,visited)
    mini_local = MAXY_CONSTANT
    for i in dic[start]:

        val = conversionPossible(i,end,dic,visited+[start])
        
        if val != -1:
            mini_local = min(mini_local,val+1)

    if mini_local == MAXY_CONSTANT:
        return -1
    return mini_local

# use floyd warsel algo



def number_of_steps_to_generate(s,c,floyd,s_d):
    count  = 0
    # global dp
    for i in s:
        if i != c :
            # if str(i)+str(c) in dp:
            #     res = dp[str(i)+str(c)]
            # else:
            res = floyd[ord(i)-ord('a')][ord(c)-ord('a')] * s_d[i]
            # dp[str(i)+str(c)] = res
            # print("not matchin",i,c,res)
            if res != -1:
                count+=res
            else:
                return MAXY_CONSTANT
    # print(" conv possible ",c,count)
    return count

def run():
    s = input().lower()
    q = int(input())
    mapper = {}

    INF = 1e9+9
    # print("compressed string",s)
    floyd = [[INF for i in range(26)] for j in range(26)]

    mapper_ind = {}
    for cc in range(26):
        floyd[cc][cc] = 0

    dic_values = []
    for _ in range(q):
        s_temp = input().strip().lower()
        key = s_temp[0].lower()
        value = s_temp[1].lower()
        dic_values.append(value)
        floyd[ord(key)-ord('a')][ord(value)-ord('a')] = 1

        if key not in mapper:
            mapper[key] = [value]
        else:
            mapper[key].append(value)

    # print(dic_values)
    #  generate all possible values
    all_set = list(set(s) | set(dic_values))
    mini = MAXY_CONSTANT
    # print(all_set)
    global dp
    dp = {}

    s_d = Counter(s)
    # make string 
    # l_s = []

    s = ''.join(s_d.keys())
    
    dist = floydWarshall(floyd,26)
    # return 0
            


    for i in all_set:
        temp = number_of_steps_to_generate(s,i,dist,s_d)
        mini = min(mini,temp)
        # print(dp)

    if mini == MAXY_CONSTANT:
        return -1
    return mini
    


for _ in range(int(input())):
    # n,k = map(int,input().split())
    print(f"Case #{_+1}: {run()} ")