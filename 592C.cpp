# your code goes here
import math
t, w, b = map(int, input().split(" "))
lcm = w * b // math.gcd(w, b)
# print(t, w, b)
mi = min(w, b) - 1
# if mi + 1 > t:
# 	print("1/1")
# 	exit(0)
ans = 0
# stage 1
ans =  ans + min(mi, t)
# print(ans)
q = t // lcm
end = q * lcm
# stage 2
ans = ans + q
# print(ans)
# stage 3
if q > 0:
	ans = ans + (q - 1) * mi
	ans = ans + min(mi, t - end)
# print(ans)
g = math.gcd(ans, t)
ans = ans // g
t = t // g
print(str(ans) + "/" + str(t))