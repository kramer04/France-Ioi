#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Fonction pour ajouter deux vecteurs de chiffres en base B
vector<int> add(const vector<int>& a, const vector<int>& b, int B) {
    int carry = 0;
    vector<int> result;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--];
        if (j >= 0) sum += b[j--];
        carry = sum / B;
        result.push_back(sum % B);
    }
    reverse(result.begin(), result.end());
    return result;
}
// Fonction pour convertir un vecteur de chiffres en base B en un entier en base 10
int to_decimal(const vector<int>& a, int B) {
    int result = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        result = result * B + a[i];
    }
    return result;
}
// Fonction pour convertir un entier en base 10 en un vecteur de chiffres en base B
vector<int> to_base(int n, int B) {
    vector<int> result;
    while (n > 0) {
        result.push_back(n % B);
        n /= B;
    }
    reverse(result.begin(), result.end());
    return result;
}
int main() {
    int B, N1, N2;
    cin >> B >> N1 >> N2;
    vector<int> a(N1), b(N2);
    for (int i = 0; i < N1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N2; i++) {
        cin >> b[i];
    }
    vector<int> c = add(a, b, B);
    int N3 = c.size();
    for (int i = 0; i < N3; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
