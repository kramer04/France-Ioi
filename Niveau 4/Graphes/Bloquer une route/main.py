from sys import setrecursionlimit, stdin, stdout

def arete_ordonnee(a, b):
    return (a, b) if a < b else (b, a)

def dfs(noeud, parent, niveau):
    global profondeur, bas, critiques, compteur
    profondeur[noeud] = bas[noeud] = compteur
    compteur += 1
    for voisin in aretes[noeud]:
        if profondeur[voisin] == -1:  # Si le voisin n'est pas visité
            dfs(voisin, noeud, niveau + 1)
            bas[noeud] = min(bas[noeud], bas[voisin])
            if bas[voisin] > profondeur[noeud]:
                critiques.append(arete_ordonnee(noeud + 1, voisin + 1))
        elif voisin != parent:  # Si le voisin est visité et ce n'est pas le parent
            bas[noeud] = min(bas[noeud], profondeur[voisin])

def main():
    global profondeur, bas, aretes, critiques, compteur
    setrecursionlimit(100000)
    N, A = map(int, stdin.readline().strip().split())
    aretes = [[] for _ in range(N)]
    profondeur = [-1] * N
    bas = [-1] * N
    critiques = []
    compteur = 0
    
    for _ in range(A):
        depart, arrivee = map(int, stdin.readline().strip().split())
        aretes[depart - 1].append(arrivee - 1)
        aretes[arrivee - 1].append(depart - 1)
    
    for i in range(N):
        if profondeur[i] == -1:
            dfs(i, -1, 0)
    
    critiques.sort(key=lambda x: (x[0], x[1]))
    
    stdout.write(str(len(critiques)) + "\n")
    for a, b in critiques:
        stdout.write(str(a) + " " + str(b) + "\n")

main()
