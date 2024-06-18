import sys
def main():
    pal = sys.stdin.readline().rstrip()
    maxLongueur = 1
    longueurMot = len(pal)
    maxLongueur = 1
    i = 1
    while i <= longueurMot - maxLongueur // 2:
        # impair
        gauche = i - 1
        droite = i + 1
        while gauche >= 0 and droite < longueurMot and pal[gauche] == pal[droite]:
            gauche -= 1
            droite += 1
            # maxLongueur += 1
        maxLongueur = max(maxLongueur, droite - gauche - 1)
        # pair
        gauche = i - 1
        droite = i
        while gauche >= 0 and droite < longueurMot and pal[gauche] == pal[droite]:
            gauche -= 1
            droite += 1
            # maxLongueur += 1
        maxLongueur = max(maxLongueur, droite - gauche - 1)
        i += 1
    print(maxLongueur)
main()
