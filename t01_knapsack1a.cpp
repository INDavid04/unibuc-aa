/// Irimia David - Grupa 241
/// Saturday, 4th of April, 2026, 15:38-15:50, 12 minutes

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

// | sir \ suma | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
// | 8          | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 8 | 8 | 8  |
// | 4          | 0 | 0 | 0 | 0 | 4 | 4 | 4 | 4 | 8 | 8 | 8  |
// | 3          | 0 | 0 | 0 | 3 | 4 | 4 | 4 | 7 | 8 | 8 | 8  |
// | 7          | 0 | 0 | 0 | 3 | 4 | 4 | 4 | 7 | 8 | 8 | 10 |
// | 2          | 0 | 0 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
// | 5          | 0 | 0 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
// | 1          | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |

#include <iostream>

using namespace std;

int main() {
    int lungime_sir, limita_suma, suma_maxima[101][101];
    
    /// Lungimea sirului
    cin >> lungime_sir;

    /// Numerele din sir
    for (int i = 1; i <= lungime_sir; i++) {
        cin >> suma_maxima[i][0];
    }

    /// Limita sumei din cerinta
    cin >> limita_suma;

    /// Sumele maxime
    for (int j = 0; j <= limita_suma; j++) {
        suma_maxima[0][j + 1] = j;
    }

    /// Prima linie
    for (int j = 1; j <= limita_suma; j++) {
        if (j < suma_maxima[1][0]) {
            suma_maxima[1][j] = 0;
        } else {
            suma_maxima[1][j] = suma_maxima[1][0];
        }
    }

    /// Restul tabelului
    for (int i = 2; i < lungime_sir; i++) {
        for (int j = 1; j <= limita_suma; j++) {
            // if (j < suma_maxima[i][0]) {
            //     suma_maxima[i][j] = suma_maxima[i-1][j];
            // } else if (suma_maxima[i][0] + suma_maxima[i-1][j-suma_maxima[i][0]] > suma_maxima[i-1][j]) {
            //     suma_maxima[i][j] = suma_maxima[i][0] + suma_maxima[i-1][j-suma_maxima[i][0]];
            // } else {
            //     suma_maxima[i][j] = suma_maxima[i-1][j];
            // }
            cout << suma_maxima[i][j] << " ";
        }
        cout << "\n";
    }

    /// Raspunsul, solutia problemei se afla in ultima celula din tabel
    cout << suma_maxima[lungime_sir-1][limita_suma];

    return 0;
}
