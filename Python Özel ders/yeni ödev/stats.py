def avg(X):
    return sum(X) / len(X)

def cov(X, Y):
    meanx = avg(X)
    meany = avg(Y)
    
    return sum((x-meanx)*(y-meany) for x,y in zip(X,Y) / len(X) -1)

def var(X):
    meanx = avg(X)
    return sum((x-meanx) **2  for x in X) / (len(X) -1)

def make_model(data):
    X,Y = zip(*data)
    m = cov(X,Y) / var(X)
    b = avg(Y) - m * avg(X)
    return (b,m)

# simple test cases
assert(make_model([(0, 0), (1, 1), (2, 2)]) == (0.0, 1.0))
assert(make_model([(0, 0), (1, 2), (2, 4)]) == (0.0, 2.0))
assert(make_model([(0, 2), (1, 3), (2, 4)]) == (2.0, 1.0))
