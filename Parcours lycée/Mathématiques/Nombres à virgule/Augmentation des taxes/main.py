from math import *
vatva = float(input())
ntva = float(input())
prix = float(input())
prix = prix / (1 + vatva / 100)
prix = prix * (1 + ntva / 100)
prix *= 100
prix = round(prix) / 100
print(prix)
