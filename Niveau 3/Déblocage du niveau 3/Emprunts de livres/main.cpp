#include <iostream>
using namespace std;
int main() {
    int nbLivres, nbJours, nbClients;
    cin >> nbLivres >> nbJours;
    // Initialisation de l'état des livres (disponibles ou non)
    int duree_restante[nbLivres];
    for (int i = 0; i < nbLivres; i++) {
        duree_restante[i] = 0;
    }
    for (int iJour = 0; iJour < nbJours; iJour++) {
        cin >> nbClients;
        for (int iClient = 0; iClient < nbClients; iClient++) {
            int livre, duree;
            cin >> livre >> duree;
            // Vérifie si le livre est disponible
            if (duree_restante[livre] == 0) {
                // Emprunt du livre
                duree_restante[livre] = duree;
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
        for (int i = 0; i < nbLivres; i++) {
            if(duree_restante[i] > 0)
            duree_restante[i]--;
        }
    }
    return 0;
}
