import sys
from collections import deque, defaultdict
sys.setrecursionlimit(10**7)
def main():
    n_intersections, n_sentiers = map(int, sys.stdin.readline().split())
    
    if n_sentiers == 0:
        print(-1)
        return
    
    # Initialiser la liste d'adjacence
    liste_adj = defaultdict(list)
    
    for _ in range(n_sentiers):
        debut, fin = map(int, sys.stdin.readline().split())
        liste_adj[debut].append(fin)
        liste_adj[fin].append(debut)
    
    # Vérifier si le graphe a un circuit eulérien
    for i in range(1, n_intersections + 1):
        if len(liste_adj[i]) % 2 == 1:
            print(-1)
            return
    
    def find_eulerian_circuit(start_node):
        circuit = []
        stack = [start_node]
        current_path = deque()
        
        while stack:
            u = stack[-1]
            if liste_adj[u]:
                v = liste_adj[u].pop()
                liste_adj[v].remove(u)
                stack.append(v)
            else:
                current_path.appendleft(stack.pop())
        
        return list(current_path)
    
    for i in range(1, n_intersections + 1):
        if liste_adj[i]:
            eulerian_circuit = find_eulerian_circuit(i)
            print(" ".join(map(str, eulerian_circuit)))
            return
    
    print(-1)
main()
