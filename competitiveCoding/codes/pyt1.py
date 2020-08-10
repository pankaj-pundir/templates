def maxCount(s,c):
    maxy = 0
    tcount = 0
    for i in range(len(s)):
        if s[i] == c:
            tcount += 1
            maxy = max(maxy,tcount)
        else:
            tcount = 0
    return maxy

def county(s,c):
    count = 0
    for i in range(len(s)):
        if s[i] == c:
            count+=1
    return count
import math
def minDig(a):
    if a <= 9:
        return 1
    
    return math.ceil(a/9)

def soln():
    s = input()
    p = input()
    alpha = [0] * 26
    for i in s:
        alpha[ord(i)-ord('a')] += 1
    for i in p:
        alpha[ord(i)-ord('a')] -= 1

    turn = 0
    ptr = 0
    nn = len(p)
    while ptr < nn:
        
        ptr +=1
        if p[ptr] == p[ptr-1]:
            continue
        if ord(p[ptr]) < ord(p[ptr-1]):
            turn = 1
            break
        if ord(p[ptr]) > ord(p[ptr-1]):
            turn = 0
            break
        
    for i in range(26):
        if turn ==1 and p[0] == chr(ord('a')+i):
            print(p,end='')
        if alpha[i] > 0:
            # print('s--',chr(ord('a')+i))
            out =  chr(ord('a')+i)* alpha[i]
            print(out,end='')
        if p[0] == chr(ord('a')+i) and turn == 0:
            print(p,end='')
    print()
        

for i in range(int(input())):
    soln()