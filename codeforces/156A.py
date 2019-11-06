from sys import stdin

first = stdin.readline().strip()
second = stdin.readline().strip()

minChange = 2001

first = '@' * (len(second) - 1) + first + '@' * (len(second) - 1)
diff = len(first) - len(second)

for i in range(0, diff + 1):
    line = '@' * i + second + '@' * (diff - i)
    result = 0
    for i in range(i, i + len(second)):
        if first[i] != line[i]:
            result += 1
    if minChange > result:
        minChange = result

print(minChange)


