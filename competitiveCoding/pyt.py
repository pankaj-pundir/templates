def d2r(n):
	decimal,symbol = [],[]
	count = 1
	decimal.append(1);
	for i in range(1,26):
		if i%2!=0:
			count*=5
		else:
			count*=2
		decimal.append(count)
		symbol.append(chr(ord("A")+i))
	i = 0 
	while n:
		while n/decimal[i]:
			print(symbol[i],end='')
			n-=decimal[i]
		i+=1

print(d2r(int(input())))