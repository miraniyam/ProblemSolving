from sys import stdin

inputString = stdin.readline().split()

N = int(inputString[0])
H = int(inputString[1])

caveS = [0] * H
caveJ = [0] * H

for i in range(0, N):
    inputString = int(stdin.readline())
    if i % 2 == 0:
        caveS[inputString-1] += 1
    else:
        caveJ[H-inputString] += 1

# Prefix Sum
caveST = [0] * H
caveST[H-1] = caveS[H-1]
for i in range(2, H+1):
    caveST[H-i] = caveST[H-i+1] + caveS[H-i]

caveJT = [0] * H
caveJT[0] = caveJ[0]
for i in range(1, H):
    caveJT[i] = caveJT[i-1] + caveJ[i]

result = []
resultIndex = [0]*(N+1)
for i in range(0, H):
    result.append(caveST[i] + caveJT[i])
    resultIndex[caveST[i] + caveJT[i]] += 1

minValue = min(result)
minIndex = resultIndex[minValue]

print(minValue, minIndex)