import sys
def max_f(count, max_val):
    return count if count > max_val else max_val
def min_f(count, max_val):
    return count if count < max_val else max_val
def dfs(node, parent, adj, subtree_size):
    subtree_size[node] = 1  # initialisation
    for voisin in adj[node]:
        if voisin == parent:
            continue
        dfs(voisin, node, adj, subtree_size)
        subtree_size[node] += subtree_size[voisin]  # ajoute la taille du sous-arbre
def main():
    input = sys.stdin.readline
    n = int(input().strip())
    adj = [[] for _ in range(n)]
    
    for _ in range(n - 1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
    
    subtree_size = [0] * n
    max_deco = 0
    
    dfs(0, -1, adj, subtree_size)
    
    for i in range(n):
        for voisin in adj[i]:
            if subtree_size[voisin] < subtree_size[i]:
                taille1 = subtree_size[voisin]
                taille2 = n - taille1
                max_deco = max_f(max_deco, min_f(taille1, taille2))
    
    print(max_deco)
if __name__ == "__main__":
    sys.setrecursionlimit(200 * 1000)
    main()
