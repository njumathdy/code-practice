s = raw_input()

n = int(s.split(' ')[0])
m = int(s.split(' ')[1])

sols = []

def dfs(a, b, temp):
    if a < b: return
    if b == 0 and a == 0:
        t = temp[::1]
        sols.append(t)
        # print(t)
        return
    if b == 0:
        return
    
    for i in range(1, a+1):
        temp.append(i)
        dfs(a-i, b-1, temp)
        temp.pop()

temp = []

dfs(n, m, temp)

n_order = 1
for i in range(1, n+1):
    n_order = n_order * i 

res = 0

def order(x):
    r = 1
    for i in range(1, x+1):
        r *= i 
    return r

# print(len(sols))

for l in sols:
    t = n_order
    for item in l:
        t = t / order(item)
    
    res = res + t

print(res)