def pied(metres):
    return metres / 0.3048
def livre(grammes):
    return grammes * 0.002205
def fahrenheit(celsius):
    return 32 + 1.8 * celsius
nb = int(input())
for i in range(nb):
    valeur, unites = input().split()
    valeur = float(valeur)
    if unites == "m":
        print(pied(valeur), "p")
    elif unites == "g":
        print(livre(valeur), "l")
    elif unites == "c":
        print(fahrenheit(valeur), "f")
