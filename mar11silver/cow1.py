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




lines = read('pairup')


# init variables
dataLength = int(lines[0].split(' ')[0])
cows = []
maxTime = 0 # minimize this



for i in range(1, dataLength + 1):
    cur = int(lines[i].split(' ')[1])
    cows += [cur] * int(lines[i].split(' ')[0])
pairs = len(cows)
cows = sort(cows)


# longest time could be center two or first and last
maxTime = max(cows[pairs // 2 - 1] + cows[pairs // 2], cows[0] + cows[pairs - 1])


print(maxTime)
writeAnswer('pairup', maxTime)