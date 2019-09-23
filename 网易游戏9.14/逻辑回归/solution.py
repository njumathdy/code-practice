import math

s = raw_input()

alpha = float(s.split(' ')[0])
lambd = float(s.split(' ')[1])
epoch = int(s.split(' ')[2])
N = int(s.split(' ')[3])
M = int(s.split(' ')[4])
L = int(s.split(' ')[5])

train_data = []
train_label = []
test = []
for _ in range(M):
    s = raw_input()
    data = [float(i) for i in s.split(' ')]
    data[-1] = int(data[-1])
    train_data.append(data[:-1])
    train_label.append(data[-1])

for _ in range(L):
    s = raw_input()
    data = [float(i) for i in s.split(' ')]
    data[-1] = int(data[-1])
    test.append(data)

theta0 = [1 for _ in range(N)]

def sigmoid(x, theta):
    res = 0
    for i in range(N):
        res += x[i] * theta[i]
    return 1 / (1+math.exp(-res))

def add(a, b):
    for i in range(len(a)):
        a[i] += b[i]
    return a;

def sub(a, b):
    return add(a, mul(b, -1))

def mul(a, b):
    for i in range(len(a)):
        a[i] = a[i] * b
    return a

def div(a, b):
    for i in range(len(a)):
        a[i] / b
    return a

def gradient_descent(theta):
    gd = [0 for _ in range(N)]
    for i in range(M):
        coef1 = train_label[i] * (1-sigmoid(train_data[i], theta))
        coef2 = (1 - train_label[i]) * sigmoid(train_data[i], theta)
        t1 = mul(train_data[i], coef1)
        t2 = mul(train_data[i], coef2)
        gd = add(gd, sub(t1, t2))
    gd = add(gd, mul(theta, lambd/M))

    theta = sub(theta, mul(gd, alpha))
    return theta

def train(theta):
    for _ in range(epoch):
        theta = gradient_descent(theta)

    return theta

def pred(theta):
    for i in range(L):
        if sigmoid(test[i], theta) > 0.5:
            y = 1
        else:
            y = 0
        print(y)

    
def main():
    theta = train(theta0)
    pred(theta)

main()



