# pylint: disable=C0200


def read(filename):
    f = open(filename + '.in', 'r')
    lines = f.readlines()
    f.close()

    return lines



def writeAnswer(filename, answer):
    f = open(filename + '.out', 'w')
    f.write(str(answer))
    f.close()



def main():
    lines = read('helpcross')


    # init variables
    chickens = [[0, 0]] * int(lines[0].split(' ')[0])
    cows = [[0, 0, 0]] * int(lines[0].split(' ')[1])
    helped = 0


    # load arrays with data
    for i in range(len(chickens)):
        # 0: time, 1: not used/used
        chickens[i] = [int(lines[i + 1]), 0]

    for i in range(len(cows)):
        curRow = lines[i + 1 + len(chickens)].split(' ')
        # 0: start, 1: end, 2: range (end - start)
        cows[i] = [int(curRow[0]), int(curRow[1]), int(curRow[1]) - int(curRow[0])]


    # sort cows and chickens
    chickens.sort(key=lambda x:x[0])
    cows.sort(key=lambda x:x[2]) # sort by range


    # find cow/chicken matches
    for cow in cows:
        for chicken in chickens:
            # if match found and chicken has not been matched before
            if chicken[0] > cow[0] and chicken[0] < cow[1] and chicken[1] == 0:
                helped += 1
                # marked as helped
                chicken[1] = 1
                break # skip to the next cow


    # write answer to file
    print(chickens)
    print(cows)
    print('helped:', helped)

    writeAnswer('helpcross', helped)



main()