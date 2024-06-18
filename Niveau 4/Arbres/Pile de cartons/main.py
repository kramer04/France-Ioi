import sys
# from sys import setrecursionlimit
# setrecursionlimit(1000000)
"""
def explorer(graphe, noeud):
    if noeud != 0:
        print("A", noeud)
    if len(graphe[noeud]) != 0:
        for voisin in graphe[noeud]:
            explorer(graphe, voisin)
    if noeud != 0:
        print("R", noeud)
"""
def explorer(graphe, noeud):
    for carton in graphe[noeud]:
        print("A", carton)
        explorer(graphe, carton)
        print("R", carton)
def main():
    nbCartons = int(sys.stdin.readline())
    nbCartons += 1
    opes = []
    index = 0
    for line in sys.stdin:
        # opes.append(list(map(int, line.split()[1:])))
        opes.append(tuple(map(int, line.split()[1:])))
        index += 1
        if index >= nbCartons:
            break
    explorer(opes, 0)
main()
