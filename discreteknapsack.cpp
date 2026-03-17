/// https://cms.fmi.unibuc.ro/problem/discreteknapsack

#include <iostream>

using namespace std;

int partitionare(float obiect[][3], int stanga, int dreapta) {
    float temporar, pivot = obiect[dreapta][0];
    int i = stanga - 1;

    for (int j = stanga; j < dreapta; j++) {
        if (obiect[j][0] > pivot) {
            i++;

            temporar = obiect[i][0];
            obiect[i][0] = obiect[j][0];
            obiect[j][0] = temporar;

            temporar= obiect[i][1];
            obiect[i][1] = obiect[j][1];
            obiect[j][1] = temporar;

            temporar = obiect[i][2];
            obiect[i][2] = obiect[j][2];
            obiect[j][2] = temporar;
        }
    }

    temporar = obiect[i + 1][0];
    obiect[i + 1][0] = obiect[dreapta][0];
    obiect[dreapta][0] = temporar;

    temporar= obiect[i + 1][1];
    obiect[i + 1][1] = obiect[dreapta][1];
    obiect[dreapta][1] = temporar;

    temporar = obiect[i + 1][2];
    obiect[i + 1][2] = obiect[dreapta][2];
    obiect[dreapta][2] = temporar;

    return i + 1;
}

void quicksort(float obiect[][3], int stanga, int dreapta) {
    if (stanga < dreapta) {
        float pivot = partitionare(obiect, stanga, dreapta);
        quicksort(obiect, stanga, pivot - 1);
        quicksort(obiect, pivot + 1, dreapta);
    }
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
    for (int i = 0; i < numar_obiecte; i++) {
        obiect[i][0] = obiect[i][1] / obiect[i][2];
    }

    /// Sorteaza lista de obiecte dupa raportul valoare/greutate
    quicksort(obiect, 0, numar_obiecte - 1);

    /// Pune obiectele care incap
    int i = 0, suma = 0;
    while (i < numar_obiecte) {
        if (obiect[i][2] <= greutate_maxima) {
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
