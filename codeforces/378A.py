from sys import stdin

raw_input = stdin.readline().split()
a = int(raw_input[0])
b = int(raw_input[1])

listA = [abs(a - i) for i in range(1, 7)]
listB = [abs(b - i) for i in range(1, 7)]

result = [0] * 3

for i in range(0, 6):
    if listA[i] < listB[i]:
        result[0] += 1
    elif listA[i] == listB[i]:
        result[1] += 1
    else:
        result[2] += 1

print(result[0], result[1], result[2])