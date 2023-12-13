def calc(d,cost,cs,cd):
    return (cost + d*(2*cs - cd))// cs


def burger(s,d):
    total_cheese,total_buns = 0,0
    if s > 0:
        total_cheese += s
        total_buns += 2*s
    if d > 0:
        total_cheese += 2*d
        total_buns += 2*d
    # print(s,d,total_cheese,total_buns)
    return min(total_cheese, total_buns-1)

def run():
    s_cost,d_cost,total_cost = map(int,input().split())

    total_cheese,total_buns = 0,0
    if total_cost < min(s_cost,d_cost):
        return 0
    if 2*s_cost > d_cost :
        # res = calc(total_cost//d_cost,total_cost,s_cost,d_cost)
        # if d_cost == 1:
        #     return res-1
        d_burger = total_cost//d_cost
        s_burger = (total_cost - d_burger*d_cost)//s_cost
        return burger(s_burger,d_burger)
    else:
        return burger(total_cost//s_cost,0)
    
for _ in range(int(input())):
    print(f"Case #{_+1}: {run()}")