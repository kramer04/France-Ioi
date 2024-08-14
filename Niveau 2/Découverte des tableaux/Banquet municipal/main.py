import sys
nbTotalPosition = 0
chgtPosition = 0
nbTotalPosition = int(input())
chgtPosition = int(input())
numero = [0] * nbTotalPosition
for loop in range(nbTotalPosition):
  p = int(input())
  numero[loop] = p
for id in range(chgtPosition):
  premier = int(input())
  deuxieme = int(input())
  first = numero[premier]
  numero[premier] = numero[deuxieme]
  numero[deuxieme] = first
for idPersonne in range(nbTotalPosition):
  print(numero[idPersonne])
