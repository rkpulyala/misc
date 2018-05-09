
def answer1(l):
    cnt = 0
    for i in range(0,len(l)):
        l2 = [n for n in l[i+1:len(l)+1] if n%l[i] == 0]
        for j in range(0,len(l2)):
            l3 = [n for n in l2[j+1:len(l2)+1] if n%l2[j] == 0]
            cnt += len(l3)
    return cnt

def answer2(l):
    cnt = 0
    for i in range(0,len(l)-2):
        for j in range(i+1,len(l)-1):
            if l[j]%l[i] is 0:
                for k in range(j+1,len(l)):
                    if l[k]%l[j] is 0:
                        #print(l[i],l[j],l[k])
                        cnt += 1
    return cnt

def answer3(l):
    cnt = 0
    ds = {}
    for i in reversed(range(0,len(l))):
        ds[i] = set([])
        for j in range(0,i):
            if l[i]%l[j] is 0:
                ds[i].add(j)

    #print(ds)
        
    for i,si in ds.items():
        if len(si) < 2:
            continue
        for d in si:
            if d in ds:
                #print(i, d, ds[d].intersection(si))
                cnt += len(ds[d].intersection(si))
    return cnt


def answer(l):
    cnt = 0
    cnt1 = [0]*len(l)
    cnt2 = [0]*len(l)
    for i in range(0,len(l)):
        for j in range(0,i):
            if l[i]%l[j] is 0:
                cnt1[i] += 1
                cnt2[i] += cnt1[j]

    print(cnt1, cnt2)

    return sum(cnt2)



print(answer([1, 2, 3, 4, 5, 6]))
print(answer([1, 2, 3, 4, 5, 12]))
print(answer([1, 1, 1]))
