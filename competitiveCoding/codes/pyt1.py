import os
for x in ['a','b','c','d','e','f']:
    os.system(f"python pyt.py < inputs/{x}.txt > subm/{x}.txt")