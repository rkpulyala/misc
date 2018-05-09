def answer(x, y):
    c = 0
    for i in range(1,x+1):
        c += i
    for i in range(2,y+1):
        c += x+i-2
    return str(c)

print(answer(3,2))
print(answer(5,10))
