#include <iostream>
using namespace std;
int main() {
    int nbLettres;
    cin >> nbLettres;
    for (int i = 0; i < 2 * nbLettres - 1; i++) {
        for (int j = 0; j < 2 * nbLettres - 1; j++) {
            if (i == 0 || i == 2 * nbLettres - 2 || j == 0 || j == 2 * nbLettres - 2) {
                cout << "a";
            } else if (i < nbLettres) {
                if (j < nbLettres) {
                    cout << (char)('a' + min(i,j));
                } else {
                    cout << (char)('a' + min(i,2*nbLettres-2-j));
                }
            } else {
                if (j < nbLettres) {
                    cout << (char)('a' + min(2*nbLettres-2-i,j));
                } else {
                    cout << (char)('a' + min(2*nbLettres-2-i,2*nbLettres-2-j));
                }
            }
        }
        cout << endl;
    }
    return 0;
}
