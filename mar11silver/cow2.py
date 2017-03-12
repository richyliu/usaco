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




lines = read('cownomics')

numlines = int(lines[0].split(' ')[0])
numPos = int(lines[0].split(' ')[1])
spotty = []
plain = []


# loop through spotty positions
for i in range(numPos):
    genome = []
    for j in range(1, numlines + 1):
        if lines[j][i] == 'A' and 'A' not in genome:
            genome.append('A')
        elif lines[j][i] == 'C' and 'C' not in genome:
            genome.append('C')
        elif lines[j][i] == 'G' and 'G' not in genome:
            genome.append('G')
        elif lines[j][i] == 'T' and 'T' not in genome:
            genome.append('T')
    
    spotty.append(genome)


# loop through plain positions
for i in range(numPos):
    genome = []
    for j in range(numlines + 1, numlines * 2 + 1):
        if lines[j][i] == 'A' and 'A' not in genome:
            genome.append('A')
        elif lines[j][i] == 'C' and 'C' not in genome:
            genome.append('C')
        elif lines[j][i] == 'G' and 'G' not in genome:
            genome.append('G')
        elif lines[j][i] == 'T' and 'T' not in genome:
            genome.append('T')
    
    plain.append(genome)


print(spotty)
print(plain)
writeAnswer('cownomics', '22')