import random
query = random.randint(1, 100001)
print query
for i in range(query):
    x, y = (random.randint(1, 101), random.randint(1, 101))
    a = random.randint(1, 101)
    b = random.randint(1, 101)
    while(x + a > 101 or y + b > 101):
        a = random.randint(1, 101)
        b = random.randint(1, 101)
    print (x, y)
    print (x + a, y + b)
    print (x + a, y)
    print (x, y + b)