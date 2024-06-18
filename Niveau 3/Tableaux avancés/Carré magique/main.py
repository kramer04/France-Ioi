import sys
def controle(cm, verif, i, j, taille):
    if 1 <= cm[i][j] <= taille**2:
        if verif[cm[i][j]]:
            verif[cm[i][j]] = False
            return True
    return False
def somme(cm, nbCase):
    sommeMagique = nbCase * (nbCase * nbCase + 1) // 2
    sommeLigne, sommeColonne, sommeDiagonale1, sommediagonale2 = 0, 0, 0, 0
    tableau = [True] * (nbCase**2 + 1)
    for i in range(nbCase):
        sommeDiagonale1 += cm[i][i]
        sommediagonale2 += cm[i][nbCase - 1 - i]
        for j in range(nbCase):
            if controle(cm, tableau, i, j, nbCase):
                sommeLigne += cm[i][j]
                sommeColonne += cm[j][i]
            else:
                return False
        if sommeLigne != sommeMagique or sommeColonne != sommeMagique:
            return False
        sommeLigne, sommeColonne = 0, 0
    if sommeDiagonale1 != sommeMagique or sommediagonale2 != sommeMagique:
        return False
    return True
""" def afficher(cm, nbC):
    print("-----------------")
    for i in range(nbC):
        for j in range(nbC):
            print(cm[i][j], end=" ")
        print()
    print("-----------------") """
def main():
    nbCase = int(input())
    carreMagique = [
        list(map(int, sys.stdin.readline().rstrip().split())) for i in range(nbCase)
    ]
    # afficher(carreMagique, nbCase)
    if somme(carreMagique, nbCase):
        print("yes")
    else:
        print("no")
main()
