import sys
def crible_eratosthene(n):
    # Créer une liste de booléens initialisés à True
    # Indice de la liste représente le nombre
    primes = [True] * (n + 1)
    p = 2
    while p * p <= n:
        # Si primes[p] n'est pas modifié, alors c'est un nombre premier
        if primes[p]:
            # Mettre à jour tous les multiples de p pour False
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    # Collecter tous les nombres premiers
    return [p for p in range(2, n + 1) if primes[p]]
def main():
    n = int(sys.stdin.readline())
    primes = crible_eratosthene(n)
    sys.stdout.write("0\n1\n")
    sys.stdout.write("\n".join(map(str, primes)) + "\n")
main()
