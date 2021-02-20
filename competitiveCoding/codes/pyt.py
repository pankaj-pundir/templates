def gcd(a,b):
    if a == 0:
        return b
    return gcd(b % a, a)
 
# Function to return LCM of two numbers
def lcm(a,b):
    return (a *b)/ gcd(a,b)

def check(s1,s2):
    mini = min(len(s1),len(s2))
    for i in range(mini):
        if s1[i] != s2[i]:
            return "-1"
    long_s,short_s = (s1,s2) if len(s1) >= len(s2) else (s2,s1)
    set_l = set(long_s)
    set_s = set(short_s)
    # print("set = ",set_l,set_s)
    # if len(long_s)%len(short_s) != 0 and (len(set_s)==2 or len(set_l)==2) :
    #     return "-1"
    pos1,pos2 = 0,0
    # print(long_s,short_s)
    count = 0

    while True:
        if long_s[pos1] != short_s[pos2]:
            return "-1"
        else:
            pos1 = (pos1+1)%len(long_s)
            if pos2 == 0:
                count += 1
            pos2 = (pos2+1)%len(short_s)

        if pos1 == pos2 == 0:
            return short_s*count

    # for i in range(mini,len(long_s)):
    #     if long_s[i] != short_s[pos]:
    #         return "-1"
    #     if pos ==0:
    #         count+=1
    #     pos +=1
    #     pos = pos% mini
    # # print(int(lcm(mini,len(long_s))))
    # if (len(set_s)==1 and len(set_l)==1):
    #     return short_s*int(lcm(mini,len(long_s))/mini)
    # return short_s*count

def gen():
    s1 = input()
    s2 = input()
    return check(s1,s2)
        




for _ in range(int(input())):
    print(gen())