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
pairs = int(lines[0])
maxTime = 0 # minimize this


smallest = 1e9
largest = 0
# find smallest and largest
for i in range(1, pairs + 1):
    cur = int(lines[i].split(' ')[1])
    if cur < smallest:
        smallest = cur
    if cur > largest:
        largest = cur


# longest time is first and last
maxTime = smallest + largest


print(maxTime)
writeAnswer('pairup', maxTime)