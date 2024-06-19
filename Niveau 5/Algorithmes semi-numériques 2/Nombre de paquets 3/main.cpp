#include <iostream>
#include <vector>

// Fonction pour calculer les coefficients binomiaux
unsigned long long binomialCoefficient(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k; // C(n, k) == C(n, n - k)

    unsigned long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }

    return result;
}

int main() {
    int N, P;
    std::cin >> N >> P;

    // Calculer le nombre de paquets différents
    unsigned long long result = binomialCoefficient(N + P - 1, P);

    std::cout << result << '\n';

    return 0;
}
