#include <iostream>
#include <vector>
#include <algorithm>
struct Noeud
{
    long long minimum = 0;
    long long maximum = 0;
    // Transformation paresseuse : x -> coef * x + ajout
    long long coef = 1;
    long long ajout = 0;
};
class ArbreSegments
{
private:
    std::vector<Noeud> arbre;
    int taille;
    void appliquer(int indice, long long coef, long long ajout)
    {
        long long ancienMin = arbre[indice].minimum;
        long long ancienMax = arbre[indice].maximum;
        if (coef == 1)
        {
            arbre[indice].minimum = ancienMin + ajout;
            arbre[indice].maximum = ancienMax + ajout;
        }
        else if (coef == 0)
        {
            arbre[indice].minimum = ajout;
            arbre[indice].maximum = ajout;
        }
        else // coef == -1
        {
            arbre[indice].minimum = -ancienMax + ajout;
            arbre[indice].maximum = -ancienMin + ajout;
        }
        // Composition des transformations :
        // ancienne : x -> a*x + b
        // nouvelle : x -> coef*x + ajout
        // composée : x -> coef*(a*x + b) + ajout
        arbre[indice].coef = coef * arbre[indice].coef;
        arbre[indice].ajout = coef * arbre[indice].ajout + ajout;
    }
    void propager(int indice)
    {
        long long coef = arbre[indice].coef;
        long long ajout = arbre[indice].ajout;
        if (coef != 1 || ajout != 0)
        {
            appliquer(indice * 2, coef, ajout);
            appliquer(indice * 2 + 1, coef, ajout);
            arbre[indice].coef = 1;
            arbre[indice].ajout = 0;
        }
    }
    void modifier(int indice, int gauche, int droite, int reqGauche, int reqDroite,
                  long long coef, long long ajout)
    {
        if (reqDroite < gauche || droite < reqGauche)
        {
            return;
        }
        if (reqGauche <= gauche && droite <= reqDroite)
        {
            appliquer(indice, coef, ajout);
            return;
        }
        propager(indice);
        int milieu = (gauche + droite) / 2;
        modifier(indice * 2, gauche, milieu, reqGauche, reqDroite, coef, ajout);
        modifier(indice * 2 + 1, milieu + 1, droite, reqGauche, reqDroite, coef, ajout);
        arbre[indice].minimum = std::min(arbre[indice * 2].minimum,
                                         arbre[indice * 2 + 1].minimum);
        arbre[indice].maximum = std::max(arbre[indice * 2].maximum,
                                         arbre[indice * 2 + 1].maximum);
    }
    long long maximumIntervalle(int indice, int gauche, int droite, int reqGauche, int reqDroite)
    {
        if (reqDroite < gauche || droite < reqGauche)
        {
            // Valeur neutre pour un maximum
            return -4000000000000000000LL;
        }
        if (reqGauche <= gauche && droite <= reqDroite)
        {
            return arbre[indice].maximum;
        }
        propager(indice);
        int milieu = (gauche + droite) / 2;
        long long maxGauche = maximumIntervalle(indice * 2, gauche, milieu, reqGauche, reqDroite);
        long long maxDroite = maximumIntervalle(indice * 2 + 1, milieu + 1, droite, reqGauche, reqDroite);
        return std::max(maxGauche, maxDroite);
    }
public:
    ArbreSegments(int nbValeurs)
    {
        taille = nbValeurs;
        arbre.resize(4 * nbValeurs + 5);
    }
    void multiplier(int gauche, int droite, long long coef)
    {
        modifier(1, 0, taille - 1, gauche, droite, coef, 0);
    }
    void ajouter(int gauche, int droite, long long valeur)
    {
        modifier(1, 0, taille - 1, gauche, droite, 1, valeur);
    }
    long long maximum(int gauche, int droite)
    {
        return maximumIntervalle(1, 0, taille - 1, gauche, droite);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int nbValeurs;
    int nbRequetes;
    std::cin >> nbValeurs >> nbRequetes;
    ArbreSegments arbre(nbValeurs);
    for (int i = 0; i < nbRequetes; i++)
    {
        int type;
        int gauche;
        int droite;
        std::cin >> type >> gauche >> droite;
        if (type == 0)
        {
            long long coef;
            std::cin >> coef;
            arbre.multiplier(gauche, droite, coef);
        }
        else if (type == 1)
        {
            long long ajout;
            std::cin >> ajout;
            arbre.ajouter(gauche, droite, ajout);
        }
        else
        {
            std::cout << arbre.maximum(gauche, droite) << '\n';
        }
    }
    return 0;
}
