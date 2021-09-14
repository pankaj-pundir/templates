import math
import collections


def giveOption(dic,c):
    # print(dic)
    maxy = -1
    for i in dic:

        if i != c and maxy < dic[i]:
            maxy = dic[i]
            ch = i 

    dic[ch]-=1
    # var  = 
    if dic[ch] == 0:
        del dic[ch]
    # print("edited",dic)
    return ch
# 5
# start
# tttppp
# ryyppp
# pppyyr
# rrrryyyy

def generateAna(s,c):
    li = []
    for i in s:
        li.append(giveOption(c,i))
        print(li)
        print("dict",c)
    return ''.join(li)

for j in range(int(input())):
    s = input()
    l = len(s)
    c = collections.Counter(s)
    ans = None
    try:
        ans = generateAna(s,dict(c))
        print(f"Case #{j+1}: {ans}") 
    except:
        print(f"Case #{j+1}: IMPOSSIBLE") 
