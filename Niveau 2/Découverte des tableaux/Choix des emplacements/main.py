nbEmplacements = int(input())
marchand = [0] * nbEmplacements
for loop in range(nbEmplacements):
  e = int(input())
  marchand[e] = loop
for loop in range(nbEmplacements):
  print(marchand[loop])
