/// https://cms.fmi.unibuc.ro/problem/fractionalknapsack

///////////////
/// Exemplu ///
///////////////

/// in

// 3 5
// 7 12 15
// 2 3 5

/// out

// 19

/// Explicatie

/// 3 /// adica trei obiecte
/// 5 /// adica capacitate, greutate maxima de 5
/// 7 12 15 /// adica valorile obiectelor
/// 2 3 5 /// greutatile obiectelor

/// 7/2 = 3.5
/// 12/3 = 4
/// 15/5 = 3

/// (12,3), (7,2), (15,5)

/// 0 + 3 = 3 <= 5 => 0 + 12 = 12
/// 3 + 2 = 5 <= 5 => 12 + 7 = 19
/// 5 + 5 = 10 <= 5 fals si nu mai incape nicio fractiune

#include <iostream>

using namespace std;

int partition(float obiect[][3], int primul_index, int ultimul_index) {
    float aux, pivot = obiect[ultimul_index][1] / obiect[ultimul_index][2];
    int i = primul_index - 1;
    
    for (int j = primul_index; j < ultimul_index; j++) {
        if (obiect[j][0] > pivot) {
            i++;

            aux = obiect[i][0];
            obiect[i][0] = obiect[j][0];
            obiect[j][0] = aux;

            aux = obiect[i][1];
            obiect[i][1] = obiect[j][1];
            obiect[j][1] = aux;

            aux = obiect[i][2];
            obiect[i][2] = obiect[j][2];
            obiect[j][2] = aux;
        }
    }
    
    aux = obiect[i + 1][0];
    obiect[i + 1][0] = obiect[ultimul_index][0];
    obiect[ultimul_index][0] = aux;

    aux = obiect[i + 1][1];
    obiect[i + 1][1] = obiect[ultimul_index][1];
    obiect[ultimul_index][1] = aux;

    aux = obiect[i + 1][2];
    obiect[i + 1][2] = obiect[ultimul_index][2];
    obiect[ultimul_index][2] = aux;

    return i + 1;
}

void quicksort(float obiect[][3], int primul_index, int ultimul_index) {
    if (primul_index < ultimul_index) {
        int index_pivot = partition(obiect, primul_index, ultimul_index);
        quicksort(obiect, primul_index, index_pivot - 1);
        quicksort(obiect, index_pivot + 1, ultimul_index);
    }
}

int main() {
    int numar_obiecte, greutate_maxima;
    float obiect[1007][3]; /// 0 - raport, 1 - valoare, 2 - greutate
    
    cin >> numar_obiecte >> greutate_maxima;
    for (int i = 0; i < numar_obiecte; i++) {
        cin >> obiect[i][1];
    }

    for (int i = 0; i < numar_obiecte; i++) {
        cin >> obiect[i][2];
    }

    for (int i = 0; i < numar_obiecte; i++) {
        obiect[i][0] = obiect[i][1] / obiect[i][2];
    }

    quicksort(obiect, 0, numar_obiecte - 1);

    int i = 0, greutate_actuala = 0;
    float valoare_maxima = 0;
    while (greutate_actuala < greutate_maxima && i < numar_obiecte) {
        if (greutate_actuala + obiect[i][2] <= greutate_maxima) {
            valoare_maxima += obiect[i][1];
            greutate_actuala += obiect[i][2];
            i++;
        } else if (greutate_actuala < greutate_maxima) {
            valoare_maxima += obiect[i][0] * (greutate_maxima - greutate_actuala);
            greutate_actuala = greutate_maxima;
            i++;
        }
    }

    cout << valoare_maxima << "\n";

    return 0;
}
