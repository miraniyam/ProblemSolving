from sys import stdin
import copy

rawInput = stdin.readline().split()

R = int(rawInput[0])
C = int(rawInput[1])
T = int(rawInput[2])

A = []
for i in range(0, R):
    rawInput = list(map(int, stdin.readline().split()))
    A.append(rawInput)

for t in range(0, T):
    sumTable = []
    for i in range(0, R):
        sumTable.append([0]*C)

    # 1. 미세먼지 확산
    for i in range(0, R):
        for j in range(0, C):
            if A[i][j] > 0:
                value = A[i][j] // 5
                count = 0
                # 확산
                # 왼
                if j-1 >= 0:
                    if A[i][j-1] != -1:
                        sumTable[i][j-1] = sumTable[i][j-1] + value
                        count += 1
                # 오
                if j+1 < C:
                    if A[i][j+1] != -1:
                        sumTable[i][j+1] = sumTable[i][j+1] + value
                        count += 1
                # 위
                if i-1 >= 0:
                    if A[i-1][j] != -1:
                        sumTable[i-1][j] = sumTable[i-1][j] + value
                        count += 1
                # 아래
                if i+1 < R:
                    if A[i+1][j] != -1:
                        sumTable[i+1][j] = sumTable[i+1][j] + value
                        count += 1

                # 남은 미세먼지 양으로 초기화
                A[i][j] = A[i][j] - value * count

    # 확신 이후 미세먼지 초기화
    for i in range(0, R):
        for j in range(0, C):
            A[i][j] = A[i][j] + sumTable[i][j]

    At = copy.deepcopy(A)

    # 2. 공기 청정기 작동
    cnt = 0
    for i in range(0, R):
        if cnt > 1:
            break
        for j in range(0, C):
            if A[i][j] == -1:
                tempi = copy.deepcopy(i)
                tempj = copy.deepcopy(j) + 1
                At[tempi][tempj] = 0
                if cnt == 1:
                    # 시계
                    cnt += 1
                    while tempj < C - 1:
                        tempj += 1
                        At[tempi][tempj] = A[tempi][tempj-1]
                    while tempi < R - 1:
                        tempi += 1
                        At[tempi][tempj] = A[tempi-1][tempj]
                    while tempj > 0:
                        tempj -= 1
                        At[tempi][tempj] = A[tempi][tempj+1]
                    while tempi > i+1:
                        tempi -= 1
                        At[tempi][tempj] = A[tempi+1][tempj]
                elif cnt == 0:
                    # 반시계
                    cnt += 1
                    while tempj < C - 1:
                        tempj += 1
                        At[tempi][tempj] = A[tempi][tempj-1]
                    while tempi > 0:
                        tempi -= 1
                        At[tempi][tempj] = A[tempi+1][tempj]
                    while tempj > 0:
                        tempj -= 1
                        At[tempi][tempj] = A[tempi][tempj+1]
                    while tempi < i - 1:
                        tempi += 1
                        At[tempi][tempj] = A[tempi-1][tempj]
                else:
                    break
    A = copy.deepcopy(At)

result = 0
for i in A:
    result = result + sum(i)

print(result + 2)