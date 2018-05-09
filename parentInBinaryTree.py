from math import *
from queue import *

def answer1(h, q):
    tree=list()
    mx = int(pow(2,h))-1

    post = (x for x in range(1,mx+1))

    treeq = Queue()
    treeq.put(list(post))

    for i in range(1,int(mx/2)+1):
        arr = treeq.get()
        #arrlen = len(list(arr))
        arrlen = len(arr)
        tree.append(arr[-1])
        treeq.put( arr[0:int((arrlen-1)/2)] )
        treeq.put( arr[int((arrlen-1)/2):arrlen-1])

    while not treeq.empty():
        n = treeq.get()
        tree.extend(n)

    #print(tree)

    r=list()

    for e in q:
        idx = tree.index(e)
        if idx is 0:
            r.append(-1)
        else:
            r.append(tree[int((idx-1)/2)])
    return r
    #print(r)

def answer2(h, q):
    mx = int(pow(2,h))-1

    r = list()
    for e in q:
        oldroot = -1
        root = mx
        start = 1
        end = mx-1
        while root > 0 and root is not e:
            oldroot = root
            if e <= int(root/2):
                root = int(root/2)
                end = root-1
            else:
                root = root-1
                start = int(root/2)+1
                end = root-1
        if root is e:
            r.append(oldroot)
    #print(r)
    return r

def answer_r3(q, r, root, start, end):
    if root <= 0:
        return
    if start is 0 or end is 0 or start >= end:
        return

    left = start+int((end-start+1)/2)-1
    #print("ENTER:", root, start, end, left)
    if left in q and left not in r:
        r[left] = root
    if end in q and end not in r:
        r[end] = root
    #print(r)
    if start+2 is root:
        return
    if len(q) is len(r):
        return
    answer_r(q, r, left, start, left-1)
    answer_r(q, r, root-1, left+1, root-2)


def answer3(h, q):
    mx = int(pow(2,h))-1
    r = dict()
    inset = set(q)
    if mx in inset:
        r[mx] = -1
    answer_r(inset, r, mx, 1, mx-1)
    return [r[e] for e in q]


def answer_i(h, n):
    offset = 0;
    root = int(pow(2,h))-1
    if n is root:
        return -1
    while root >= 3:
        right = root-1
        left = int(root/2)
        if n is right or n is left:
            return offset+root
        if n > left :
            offset += left
            n -= left
        root = left

def answer(h, q):
    return [answer_i(h, n) for n in q]

def answer(h, q):
    result = list()
    root = int(pow(2,h))-1
    while root >= 3 :
        right = root-1
        left = int(root/2)
        if n is right or n is left:
            return offset+root
        result = [x+root for i,x in result if q[i] is right or if q[i] is left]
        result = [x+left for i,x in result if q[i] is right or if q[i] is left]

        if n > left :
            offset += left
            n -= left
        root = left




print(answer(3, [7, 3, 5, 1]))
print(answer(5, [19, 14, 28]))

