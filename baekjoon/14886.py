from sys import stdin
from sys import maxsize
from itertools import combinations, permutations

N = int(stdin.readline())
S = []
pool = [] # 경우의 수

for i in range(0, N):
    S.append(list(map(int, stdin.readline().split())))
    pool.append(i)

cases = list(combinations(pool, int(N/2)))
anticases = []
for i in cases:
    anticases.append(list(set(pool) - set(list(i))))

min = maxsize
for i in range(0, len(cases)):
    index1 = list(permutations(list(cases[i]), 2))
    value1 = 0
    for j in index1:
        temp = list(j)
        value1 = value1 + S[temp[0]][temp[1]]

    index2 = list(permutations(list(anticases[i]), 2))
    value2 = 0
    for j in index2:
        temp = list(j)
        value2 = value2 + S[temp[0]][temp[1]]

    if min > abs(value1 - value2):
        min = abs(value1 - value2)

print(min)