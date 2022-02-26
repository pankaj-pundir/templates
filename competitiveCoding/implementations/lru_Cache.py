# implementing LRU Cache

from functools import lru_cache

# @lru_cache this decorator can be used to store func output in lru

class LRU:
    def __init__(self,size) -> None:
        self.cache = []
        self.mapping = {}
        self.size = size # size of cache
    
    def put(self,key,value):
        if len(self.cache) > self.size:
            first = self.cache[0]
            self.cache.pop(0)
            del self.mapping[first['key']]


        self.mapping[key] ={}
        self.mapping[key]['value'] = value

        upd = {'key':key}
        self.mapping[key]['ref'] = upd 
        # python dosent make the copy so its takin by reference
        self.cache.append(self.mapping[key]['ref'])
        
    def get(self,key):

        return self.mapping[key]
            
