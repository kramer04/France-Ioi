import sys
def empile(pile, date, indiceSommet):
    pile[indiceSommet] = date
    indiceSommet += 1
    return indiceSommet
def depile(pile, indiceSommet):
    indiceSommet -= 1
    return indiceSommet, pile[indiceSommet]
def videPile(indiceSommet):
    return indiceSommet == 0
def main():
    pile = [0] * 1000
    indiceSommet = 0
    minimum = 0
    nbOperation = int(input())
    for i in range(nbOperation):
        quantite, date = map(int, sys.stdin.readline().split())
        minimum = max(date, minimum)
        if quantite > 0:
            for j in range(quantite):
                indiceSommet = empile(pile, date, indiceSommet)
        else:
            for j in range(-quantite):
                indiceSommet, _ = depile(pile, indiceSommet)
    # print(pile[:indiceSommet])
    # print(minimum)
    while not videPile(indiceSommet):
        indiceSommet, date = depile(pile, indiceSommet)
        minimum = min(date, minimum)
    print(minimum)
main()
