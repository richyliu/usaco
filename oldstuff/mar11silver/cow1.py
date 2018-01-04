def read(filename):
    f = open(filename + '.in', 'r')
    lines = f.readlines()
    f.close()

    return lines


def writeAnswer(filename, answer):
    f = open(filename + '.out', 'w')
    f.write(str(answer))
    f.close()


def sort(array):
    less = []
    equal = []
    greater = []

    if len(array) > 1:
        pivot = array[0]
        for x in array:
            if x < pivot:
                less.append(x)
            if x == pivot:
                equal.append(x)
            if x > pivot:
                greater.append(x)
        return sort(less) + equal + sort(greater)
    else:
        return array


def select(L):
    if len(L) < 10:
        L.sort()
        return L[int(len(L)/2)]
    S = []
    lIndex = 0
    while lIndex+5 < len(L)-1:
        S.append(L[lIndex:lIndex+5])
        lIndex += 5
    S.append(L[lIndex:])
    Meds = []
    for subList in S:
        Meds.append(select(subList))
    L2 = select(Meds)
    L1 = L3 = []
    for i in L:
        if i < L2:
            L1.append(i)
        if i > L2:
            L3.append(i)
    if len(L) < len(L1):
        return select(L1)
    elif len(L) > len(L1) + 1:
        return select(L3)
    else:
        return L2




lines = read('pairup')


# init variables
dataLength = int(lines[0].split(' ')[0])
cows = []
maxTime = 0 # minimize this


smallest = 1e9
largest = 0
for i in range(1, dataLength + 1):
    curLine = lines[i].split(' ')
    cur = int(curLine[1])
    cows += [cur] * int(curLine[0])
    
    if cur < smallest:
        smallest = cur
    if cur > largest:
        largest = cur


# longest time could be center two or first and last
maxTime = max(select(cows) + select(cows[:-1]), cows[0] + cows[len(cows) - 1])


print(maxTime)
writeAnswer('pairup', maxTime)