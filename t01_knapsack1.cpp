/// Irimia David - Grupa 241
/// Thursday, 2nd of April, 2026, 00:36-00:58, 22 minutes

//////////
/// IN ///
//////////

// 7
// 8 4 3 7 2 5 1
// 10

///////////
/// OUT ///
///////////

// 10

//////////////////
/// EXPLICATIE ///
//////////////////

/// Pentru sirul 8 4 3 7 2 5 1 de lungime 7 vrem sa calculam suma maxima care sa nu depaseasca valoare 10.
/// 8 <= 10 ? DA => 8
/// 4 <= 2 ? NU
/// 3 <= 2 ? NU
/// 7 <= 2 ? NU
/// 2 <= 2 ? Da => 10
/// 5 <= 0 ? NU
/// 1 <= 0 ? NU
/// Asadar, suma maxima care sa nu depaseasca 10 este chiar 10 in acest exemplu :)

#include <iostream>

using namespace std;

class Knapsack1 {
private:
    int sir_numere[101]; /// S
    int lungime_sir, limita_suma, suma_maxima, numar_maxim; /// n, K
protected:
public:
    void setLungimeSir() {
        cin >> lungime_sir;
    }

    void setSirNumere() {
        for (int i = 0; i < lungime_sir; i++) {
            cin >> sir_numere[i];
        }
    }

    void setLimitaSuma() {
        cin >> limita_suma;
    }

    void setSumaMaxima() {
        suma_maxima = 0;
    }

    void setNumarMaxim() {
        numar_maxim = 0;
        for (int i = 0; i < lungime_sir; i++) {
            if (sir_numere[i] > numar_maxim) {
                numar_maxim = sir_numere[i];
            }
        }
    }

    int getSumaMaxima() {
        for (int i = 0; i < lungime_sir; i++) {
            if (sir_numere[i] <= limita_suma) {
                limita_suma -= sir_numere[i];
                suma_maxima += sir_numere[i];
            }
        }

        if (suma_maxima > numar_maxim) {
            return suma_maxima;
        } else {
            return numar_maxim;
        }
    }
};

int main() {
    Knapsack1 k;
    k.setLungimeSir();
    k.setSirNumere();
    k.setLimitaSuma();
    k.setSumaMaxima();
    k.setNumarMaxim();

    cout << k.getSumaMaxima() << "\n";

    return 0;
}
