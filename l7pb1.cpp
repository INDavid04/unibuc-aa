/// Pozitia unui punct fata de cercul circumscris unui triunghi: https://cms.fmi.unibuc.ro/problem/l7pb1

#include <iostream>

using namespace std;

struct Punct { int x, y; };

int main() {
    /// Citeste coordonatele punctelor triunghiului
    long long xA, yA, xB, yB, xC, yC;
    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xC >> yC;

    /// Citeste numarul de puncte ale caror pozitii relative se doreste
    int m;
    cin >> m;

    /// Citeste punctele respective
    Punct P[100007];
    for (int i = 0; i < m; i++) {
        cin >> P[i].x >> P[i].y;
    }

    /// Afiseaza pozitiile (INSIDE, OUTSIDE, BOUNDARY)
    for (int i = 0; i < m; i++) {
        /// inside (d > 0), outside (d < 0), boundary (d == 0)
        long long d = 0; 
        long long xD = P[i].x;
        long long yD = P[i].y;

        /// Pentru A, B, C, D, determinantul este
        /// | xA yA xA*xA+yA*yA 1 |
        /// | xB yB xB*xB+yB*yB 1 |
        /// | xC yC xC*xC+yC*yC 1 |
        /// | xD yD xD*xD+yD*yD 1 |

        /// Dezvoltam dupa ultima coloana
        ///                | xB yB xB*xB+yB*yB |                  | xA yA xA*xA+yA*yA |                  | xA yA xA*xA+yA*yA |                  | xA yA xA*xA+yA*yA |
        /// 1*(-1)^(1+4) * | xC yC xC*xC+yC*yC | + 1*(-1)^(2+4) * | xC yC xC*xC+yC*yC | + 1*(-1)^(3+4) * | xB yB xB*xB+yB*yB | + 1*(-1)^(4+4) * | xB yB xB*xB+yB*yB |
        ///                | xD yD xD*xD+yD*yD |                  | xD yD xD*xD+yD*yD |                  | xD yD xD*xD+yD*yD |                  | xC yC xC*xC+yC*yC |
        
        /// Obtinem
        ///   | xB yB xB*xB+yB*yB |   | xA yA xA*xA+yA*yA |   | xA yA xA*xA+yA*yA |   | xA yA xA*xA+yA*yA |
        /// - | xC yC xC*xC+yC*yC | + | xC yC xC*xC+yC*yC | - | xB yB xB*xB+yB*yB | + | xB yB xB*xB+yB*yB |
        ///   | xD yD xD*xD+yD*yD |   | xD yD xD*xD+yD*yD |   | xD yD xD*xD+yD*yD |   | xC yC xC*xC+yC*yC |

        d -= xB*yC*(xD*xD+yD*yD) + xC*yD*(xB*xB+yB*yB) + xD*(xC*xC+yC*yC)*yB - (xB*xB+yB*yB)*yC*xD - (xC*xC+yC*yC)*yD*xB - (xD*xD+yD*yD)*xC*yB;
        d += xA*yC*(xD*xD+yD*yD) + xC*yD*(xA*xA+yA*yA) + xD*(xC*xC+yC*yC)*yA - (xA*xA+yA*yA)*yC*xD - (xC*xC+yC*yC)*yD*xA - (xD*xD+yD*yD)*xC*yA;
        d -= xA*yB*(xD*xD+yD*yD) + xB*yD*(xA*xA+yA*yA) + xD*(xB*xB+yB*yB)*yA - (xA*xA+yA*yA)*yB*xD - (xB*xB+yB*yB)*yD*xA - (xD*xD+yD*yD)*xB*yA;
        d += xA*yB*(xC*xC+yC*yC) + xB*yC*(xA*xA+yA*yA) + xC*(xB*xB+yB*yB)*yA - (xA*xA+yA*yA)*yB*xC - (xB*xB+yB*yB)*yC*xA - (xC*xC+yC*yC)*xB*yA;

        if (d > 0) {
            cout << "INSIDE\n";
        } else if (d < 0) {
            cout << "OUTSIDE\n";
        } else {
            cout << "BOUNDARY\n";
        }
    }

    return 0;
}
