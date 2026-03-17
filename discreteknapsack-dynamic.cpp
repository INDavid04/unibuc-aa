/// https://cms.fmi.unibuc.ro/problem/discreteknapsack

///////////////////////////
/// Dynamic programming ///
///////////////////////////

#include <iostream>

using namespace std;

int main() {
    /// Citeste numarul de obiecte si capacitatea maxima
    int numar_obiecte, capacitate_maxima;
    cin >> numar_obiecte >> capacitate_maxima;

    /// Incrementeaza pentru eficienta la urmatoarele calcule
    numar_obiecte++;
    capacitate_maxima++;

    /// Declara obiectele
    int valoare[numar_obiecte], greutate[numar_obiecte];

    /// Citeste valoarea obiectelor
    for (int i = 1; i < numar_obiecte; i++) {
        cin >> valoare[i];
    }

    /// Citeste greutatea obiectelor
    for (int i = 1; i < numar_obiecte; i++) {
        cin >> greutate[i];
    }

    /// Declara matricea subproblemelor
    int raspuns[numar_obiecte][capacitate_maxima];

    /// Initializeaza primul rand din matrice
    for (int i = 0; i < capacitate_maxima; i++) {
        raspuns[0][i] = 0;
    } 

    /// Initializeaza prima coloana din matrice
    for (int i = 0; i < numar_obiecte; i++) {
        raspuns[i][0] = 0;
    } 

    /// Construieste matricea subproblemelor
    for (int i = 1; i < numar_obiecte; i++) {
        for (int j = 1; j < capacitate_maxima; j++) {
            /// Daca obiectul incape
            if (greutate[i] <= j) {
                /// Si daca aduce profit
                if (valoare[i] + raspuns[i - 1][j - greutate[i]] > raspuns[i - 1][j]) {
                    raspuns[i][j] = valoare[i] + raspuns[i - 1][j - greutate[i]];
                } else {
                    raspuns[i][j] = raspuns[i - 1][j];
                }
            } else {
                raspuns[i][j] = raspuns[i - 1][j];
            }
        }
    }

    cout << raspuns[numar_obiecte - 1][capacitate_maxima - 1] << "\n";

    return 0;
}
