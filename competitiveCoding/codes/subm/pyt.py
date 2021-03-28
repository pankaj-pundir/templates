D, I, S, C, R = map(int,input().split())
graph = {}
metadata = {}
frequencyOfStreet = {}
intersectionStreetsIncoming = {}

def addIntersectionSt(a,st):
    if a in intersectionStreetsIncoming:
        intersectionStreetsIncoming[a].append(st)
    else:
        intersectionStreetsIncoming[a] = [st]

def add(a,b):
    if a in graph:
        graph[a].append(b)
        # intersectionStreetsIncoming[b].append(name) 
    else:
        graph[a] = [b]

for i in range(S):
    a,b,name,tim = map(str, input().split())
    a,b,tim = int(a),int(b),int(tim)
    add(a,b)
    addIntersectionSt(b,name)
    # add(b,a)
    
    metadata[str(a)+'-'+str(b)] = (name,tim)
def addStreetCount(x):
    if x in frequencyOfStreet:
        frequencyOfStreet[x] += 1
    else:
        frequencyOfStreet[x] = 1

cars = []
for i in range(C):
    cars.append(input().split()[1:])
    for k in cars[-1]:
        addStreetCount(k)

ans = []
print(I)
for i in intersectionStreetsIncoming:

    li = intersectionStreetsIncoming[i]
    print(i)
    print(len(li))
    if len(li) == 1:
        # print(1)
        print(f"{li[0]} 1")
    else:
        for k in li:
            print(f"{k} 1")
    
    
# print(graph)
# print('*'*20)
# print(metadata)
# print('*'*20)
# print(cars)
# print('*'*20)
# print(frequencyOfStreet)
# print('*'*20)
# print(intersectionStreetsIncoming)