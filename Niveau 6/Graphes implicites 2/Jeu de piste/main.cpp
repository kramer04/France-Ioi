#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
const int INF = 1e9;
struct EtatTemps
{
    int tempsP1;
    int tempsP2;
};
int idEtat(int derniereP1, int derniereP2, int base)
{
    return derniereP1 * base + derniereP2;
}
// Supprime les états inutiles.
// Si un état a tempsP1 <= autre.tempsP1 et tempsP2 <= autre.tempsP2,
// alors l'autre état ne pourra jamais donner une meilleure solution.
void filtrer(std::vector<EtatTemps>& etats)
{
    std::sort(etats.begin(), etats.end(), [](const EtatTemps& a, const EtatTemps& b)
    {
        if (a.tempsP1 != b.tempsP1)
        {
            return a.tempsP1 < b.tempsP1;
        }
        return a.tempsP2 < b.tempsP2;
    });
    std::vector<EtatTemps> gardes;
    int meilleurTempsP2 = INF;
    for (const EtatTemps& etat : etats)
    {
        if (etat.tempsP2 < meilleurTempsP2)
        {
            gardes.push_back(etat);
            meilleurTempsP2 = etat.tempsP2;
        }
    }
    etats.swap(gardes);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int nbEnigmes, nbChemins;
    std::cin >> nbEnigmes >> nbChemins;
    std::vector<std::vector<int>> dist(nbEnigmes + 1, std::vector<int>(nbEnigmes + 1, INF));
    for (int i = 1; i <= nbEnigmes; ++i)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < nbChemins; ++i)
    {
        int a, b, temps;
        std::cin >> a >> b >> temps;
        dist[a][b] = temps;
        dist[b][a] = temps;
    }
    // Plus courts chemins entre toutes les paires d'énigmes.
    for (int k = 1; k <= nbEnigmes; ++k)
    {
        for (int i = 1; i <= nbEnigmes; ++i)
        {
            for (int j = 1; j <= nbEnigmes; ++j)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int base = nbEnigmes + 1;
    int nbEtats = base * base;
    std::vector<std::vector<EtatTemps>> dp(nbEtats);
    std::vector<std::vector<EtatTemps>> suivant(nbEtats);
    std::vector<int> actifs;
    std::vector<int> actifsSuivants;
    std::vector<bool> estActif(nbEtats, false);
    std::vector<bool> estActifSuivant(nbEtats, false);
    int depart = idEtat(1, 1, base);
    dp[depart].push_back({0, 0});
    actifs.push_back(depart);
    estActif[depart] = true;
    for (int enigme = 2; enigme <= nbEnigmes; ++enigme)
    {
        for (int etat : actifs)
        {
            int derniereP1 = etat / base;
            int derniereP2 = etat % base;
            for (const EtatTemps& tempsEtat : dp[etat])
            {
                int tempsActuel = std::max(tempsEtat.tempsP1, tempsEtat.tempsP2);
                // Cas 1 : P1 résout l'énigme actuelle.
                {
                    int nouveauTempsP1 = std::max(
                        tempsActuel,
                        tempsEtat.tempsP1 + dist[derniereP1][enigme]
                    );
                    int nouvelEtat = idEtat(enigme, derniereP2, base);
                    suivant[nouvelEtat].push_back({
                        nouveauTempsP1,
                        tempsEtat.tempsP2
                    });
                    if (!estActifSuivant[nouvelEtat])
                    {
                        estActifSuivant[nouvelEtat] = true;
                        actifsSuivants.push_back(nouvelEtat);
                    }
                }
                // Cas 2 : P2 résout l'énigme actuelle.
                {
                    int nouveauTempsP2 = std::max(
                        tempsActuel,
                        tempsEtat.tempsP2 + dist[derniereP2][enigme]
                    );
                    int nouvelEtat = idEtat(derniereP1, enigme, base);
                    suivant[nouvelEtat].push_back({
                        tempsEtat.tempsP1,
                        nouveauTempsP2
                    });
                    if (!estActifSuivant[nouvelEtat])
                    {
                        estActifSuivant[nouvelEtat] = true;
                        actifsSuivants.push_back(nouvelEtat);
                    }
                }
            }
        }
        // On filtre les états dominés.
        for (int etat : actifsSuivants)
        {
            filtrer(suivant[etat]);
        }
        // Nettoyage de l'ancienne couche.
        for (int etat : actifs)
        {
            dp[etat].clear();
            estActif[etat] = false;
        }
        dp.swap(suivant);
        actifs.swap(actifsSuivants);
        estActif.swap(estActifSuivant);
        actifsSuivants.clear();
        for (int etat : actifs)
        {
            suivant[etat].clear();
            estActifSuivant[etat] = false;
        }
    }
    int reponse = INF;
    for (int etat : actifs)
    {
        for (const EtatTemps& tempsEtat : dp[etat])
        {
            int fin = std::max(tempsEtat.tempsP1, tempsEtat.tempsP2);
            reponse = std::min(reponse, fin);
        }
    }
    std::cout << reponse << '\n';
    return 0;
}
