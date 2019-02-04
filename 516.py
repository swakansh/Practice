import math
while(True):
	inp = list(map(int, input().split(" ")))
	if(len(inp) == 1):	
		break
	num = 1
	for i in range(0, len(inp), 2):
		num = num * pow(inp[i], inp[i + 1])
	pr = []
	num = num - 1
	lim = int(math.sqrt(num))
	for i in range(2, lim + 1):
		ct = 0
		while(num % i == 0):
			num = num // i
			ct = ct + 1
		if ct != 0:
			pr.append(ct)
			pr.append(i)
	if num != 1:
		pr.append(1)
		pr.append(num)
	pr = pr[::-1]
	print(" ".join(list(map(str, pr))))