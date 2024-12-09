import sys
from array import array
def encoder_etat(x1, y1, x2, y2, col, lig):
    # Encodage compact de l'état en un entier unique
    return ((x1 * lig + y1) * col * lig) + (x2 * lig + y2)
def dfs_pile(col, lig, grille, visite):
    mouvements = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    stack = []
    x1_init, y1_init = 0, 0
    x2_init, y2_init = col - 1, lig - 1
    # Vérifier si les couleurs initiales sont les mêmes
    if grille[y1_init][x1_init] != grille[y2_init][x2_init]:
        print(0)
        return
    # Marquer l'état initial comme visité avant de l'empiler
    etat_init = encoder_etat(x1_init, y1_init, x2_init, y2_init, col, lig)
    visite[etat_init] = 1
    stack.append((x1_init, y1_init, x2_init, y2_init))
    while stack:
        x1, y1, x2, y2 = stack.pop()
        # Vérifier si nous avons atteint l'objectif
        if (x1 == x2 and y1 == y2) or visite[encoder_etat(x2, y2, x1, y1, col, lig)]:
            print(1)
            return
        # Plus besoin de vérifier et marquer l'état ici,
        # puisqu'il a déjà été marqué lors de l'empilement.
        # Générer les mouvements pour chaque pion
        for dx1, dy1 in mouvements:
            nx1, ny1 = x1 + dx1, y1 + dy1
            if 0 <= nx1 < col and 0 <= ny1 < lig:
                for dx2, dy2 in mouvements:
                    nx2, ny2 = x2 + dx2, y2 + dy2
                    if 0 <= nx2 < col and 0 <= ny2 < lig:
                        if grille[ny1][nx1] == grille[ny2][nx2]:
                            nouvel_etat = encoder_etat(nx1, ny1, nx2, ny2, col, lig)
                            # Avant d'empiler, on vérifie si l'état n'est pas déjà visité
                            if visite[nouvel_etat] == 0:
                                visite[nouvel_etat] = 1
                                stack.append((nx1, ny1, nx2, ny2))
    # Si aucun chemin n'a été trouvé
    print(0)
def main():
    sys.setrecursionlimit(1 << 25)
    col, lig = map(int, sys.stdin.readline().split())
    grille = [list(sys.stdin.readline().strip()) for _ in range(lig)]
    taille = col * lig * col * lig
    visite = array("B", [0]) * taille
    dfs_pile(col, lig, grille, visite)
if __name__ == "__main__":
    main()
