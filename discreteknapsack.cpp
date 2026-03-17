/// https://cms.fmi.unibuc.ro/problem/discreteknapsack

#include <iostream>

using namespace std;

int partitionare(float obiect[][3], int stanga, int dreapta) {

}

void quicksort(float obiect[][3], int stanga, int dreapta) {
    int st = stanga, dr = dreapta;
    float pivot = partitionare(obiect, st, dr);
    quicksort(obiect, stanga, pivot - 1);
    quicksort(pivot + 1, dreapta);
}

int main() {
    /// Citeste numarul de obiecte si greutatea maxima
    int numar_obiecte, greutate_maxima;
    cin >> numar_obiecte >> greutate_maxima;

    /// Initializeaza obiectul astfel:
    /// obiect[i][0] = raport; 
    /// obiect[i][1] = valoare;
    /// obiect[i][2] = greutate;
    float obiect[numar_obiecte][3]; 

    /// Citeste valorile
    int obiect_cu_valoare_maxima = -1;
    for (int i = 0; i < numar_obiecte; i++) {
        cin >> obiect[i][1];

        /// Retine obiectul cu valoare maxima
        if (obiect[i][1] > obiect_cu_valoare_maxima) {
            obiect_cu_valoare_maxima = obiect[i][1];
        }
    }

    /// Citeste greutatile
    for (int i = 0; i < numar_obiecte; i++) {
        cin >> obiect[i][2];
    }

    /// Calculeaza raportul valoare/greutate
    for (int = 0; i < numar_obiecte; i++) {
        obiect[i][0] = obiect[i][1] / obiect[i][2];
    }

    /// Sorteaza lista de obiecte dupa raportul valoare/greutate
    quicksort(&obiect, 0, numar_obiecte);

    /// Pune obiectele care incap
    bool incape = true;
    int i = 0, suma = 0;
    while (incape && i < numar_obiecte) {
        if (obiect[i][2] < greutate_maxima) {
            suma += obiect[i][1];
            greutate_maxima -= obiect[i][2];
        }
        i++;
    }

    if (suma > obiect_cu_valoare_maxima) {
        cout << suma;
    } else {
        cout << obiect_cu_valoare_maxima;
    }

    return 0;
}
