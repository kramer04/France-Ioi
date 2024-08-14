from math import *

nbHabitant = int(input())
fortune = [0] * nbHabitant
milieu = 0.0

for i in range(nbHabitant):
    fortune[i] = int(input())

fortune.sort()

if nbHabitant % 2 != 0:
    milieu = fortune[nbHabitant // 2]
else:
    milieu = (fortune[nbHabitant // 2 - 1] + fortune[nbHabitant // 2]) / 2

print(milieu)
