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
    lines = read('maxcross')


    # all crosslights, 0 for not broken, 1 for broken
    crosslights = [0] * int(lines[0].split(' ')[0])
    # number of crosslights in a row to reach
    row = int(lines[0].split(' ')[1])
    # what crosslights we should fix
    solutions = []
    # beginning of continous lights
    begin = 0
    # end of continous lights
    end = 1



    # load arrays with data
    for i in range(int(lines[0].split(' ')[2])):
        # 0: broken, 1: solution(fix)
        crosslights[int(lines[i + 1]) - 1] = 1


    # go to first working light
    for i, light in enumerate(crosslights):
        if light == 1:
            continue
        if light == 0:
            begin = i
            end = i + 1
            break
    print('begin:', begin, 'end:', end)


    # go to the next broken light
    for i in range(begin, len(crosslights)):
        if crosslights[i] == 0:
            continue
        if crosslights[i] == 1:
            end = i
            break
    print('begin:', begin, 'end:', end)


    # keep incrementing end until end - begin = row
    while end - begin < row:
        # if currently on a broken light, then we should fix it
        if crosslights[end] == 1:
            solutions.append(end + 1)
        end += 1
    print('begin:', begin, 'end:', end)



    # write answer to file
    # print(crosslights)
    print('fixed:', solutions)

    # writeAnswer('maxcross', '\n'.join(str(x) for x in solutions))



main()