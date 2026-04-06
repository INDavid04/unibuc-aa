/// Irimia David - Grupa 241
/// Saturday, 4th of April, 2026, 15:38-15:50, 12 minutes, attempt #1 a wrong one :)
/// Monday, 6h of April, 2026, 10:22-10:52, 30 minutes, attempt #2 a good one :)

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
    int limita_sir, limita_suma, suma_maxima[101][101];
    
    /// Sirul de numere
    cin >> limita_sir;
    for (int i = 1; i <= limita_sir; i++) {
        cin >> suma_maxima[i][0];
    }

    /// Limitele sumei
    cin >> limita_suma;
    for (int j = 1; j <= limita_suma + 1; j++) {
        suma_maxima[0][j] = j - 1;
    }

    /// Primul rand
    for (int j = 1; j <= limita_suma + 1; j++) {
        if (suma_maxima[0][j] < suma_maxima[1][0]) {
            suma_maxima[1][j] = 0;
        } else {
            suma_maxima[1][j] = suma_maxima[1][0];
        }
    }

    /// Restul randurilor
    for (int i = 2; i <= limita_sir; i++) {
        for (int j = 1; j <= limita_suma + 1; j++) {
            if (suma_maxima[0][j] >= suma_maxima[i][0]) {
                if (suma_maxima[i][0] + suma_maxima[i-1][j-suma_maxima[i][0]] > suma_maxima[i-1][j]) {
                    suma_maxima[i][j] = suma_maxima[i][0] + suma_maxima[i-1][j-suma_maxima[i][0]];
                } else {
                    suma_maxima[i][j] = suma_maxima[i - 1][j];
                }
            } else {
                suma_maxima[i][j] = suma_maxima[i - 1][j];
            }
        }
    }

    /// TEST: Afiseaza tabelul cu sumele maxime
    // for (int i = 0; i <= limita_sir; i++) {
    //     for (int j = 0; j <= limita_suma + 1; j++) {
    //         cout << suma_maxima[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << suma_maxima[limita_sir][limita_suma + 1] << "\n";

    return 0;
}
