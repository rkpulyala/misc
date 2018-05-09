def stairs1(stcase, nbricks):
    ## Rows are Max heights
    ## Cols are number of bricks
    ## Cell values are number of ways of building staircases
    for i in range(1,nbricks):
        stcase[i][1] = 1
        stcase[i][2] = 1

    for i in range(1,nbricks):
        for j in range(3,nbricks):
            for k in reversed(range(1, i)):
                stcase[i][j] += stcase[k][i-k+1]
    print(stcase)


def answer1(n):
    # your code here
    stcase = []
    for i in range(0,n+1):
        stcase.append([])
        for j in range(0,n+1):
            stcase[i].append(0)

    print(stcase)
    stairs(stcase, n+1)
    return stcase[n][n]

def stairs(memo, nbricks, maxheight):
    nstairs = memo[(nbricks,maxheight)]
    if nstairs is not -1:
        return nstairs
    if nbricks is 0:
        nstairs = 1
    elif nbricks < maxheight:
        nstairs = 0
    else:
        nstairs = stairs(memo, nbricks-maxheight, maxheight+1)+stairs(memo, nbricks, maxheight+1)
    memo[(nbricks,maxheight)] = nstairs
    return nstairs

def answer(n):
    stairs_memo = {}
    for i in range(0,n+2):
        for j in range(0,n+2):
            stairs_memo[(i,j)] = -1
    stairs_memo[(0,0)] = 0
    return stairs(stairs_memo, n,1)-1


print(answer(10))
