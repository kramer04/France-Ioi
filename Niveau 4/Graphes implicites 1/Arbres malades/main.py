import sys
# Construction du graphe basé sur les arbres et leur rayon de contamination
def build_graph(arbres):
    n = len(arbres)
    graph = [[] for _ in range(n)]
    bidirect = [[] for _ in range(n)]
    # Remplissage du graphe en vérifiant la bidirectionnalité de la contamination
    for i in range(n):
        xA, yA, rA = arbres[i]
        for j in range(i + 1, n):
            xB, yB, rB = arbres[j]
            dist2 = (xA - xB) * (xA - xB) + (yA - yB) * (yA - yB)
            arbre2VersArbre1 = dist2 <= rB * rB
            if dist2 <= rA * rA:  # A peut contaminer B
                graph[i].append(j)
                if arbre2VersArbre1:
                    bidirect[i].append(j)
            if arbre2VersArbre1:  # B peut contaminer A
                graph[j].append(i)
    return graph, bidirect
# Fonction DFS pour propager la contamination à partir d'un arbre donné
def dfs(graph, start):
    n = len(graph)
    visited = [False] * n
    visited[start] = True
    stack = [start]  # Utiliser une pile pour le DFS
    count = 1  # Compter l'arbre lui-même
    while stack:
        u = stack.pop()  # Récupérer le dernier élément ajouté (LIFO)
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                stack.append(v)
                count += 1
    return count
def main():
    # Capture des données
    N, M = map(
        int, sys.stdin.readline().split()
    )  # N = nombre d'arbres, M = nombre de questions
    # Lire les arbres
    arbres = []
    for _ in range(N):
        x, y, r = map(int, sys.stdin.readline().split())
        arbres.append((x, y, r))
    # Construction du graphe
    graph, bidirect = build_graph(arbres)
    reponses = [-1] * N  # Initialisation à -1 pour marquer les non-calculés
    # Traiter chaque question
    for _ in range(M):
        q = int(sys.stdin.readline())
        if reponses[q] != -1:
            sys.stdout.write(
                str(reponses[q]) + "\n"
            )  # Imprimer immédiatement si déjà calculé
        else:
            # Calculer la réponse uniquement pour cet arbre avec DFS
            reponse = dfs(graph, q)
            reponses[q] = reponse  # Mémoriser uniquement pour cet arbre
            for a in bidirect[q]:
                reponses[a] = reponse
            sys.stdout.write(str(reponse) + "\n")  # Imprimer immédiatement la réponse
if __name__ == "__main__":
    main()
