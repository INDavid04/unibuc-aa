/// Muchii ilegale: https://cms.fmi.unibuc.ro/problem/l7pb2

#include <iostream>

using namespace std;

int main() {
    /// Citeste varfurile
    long long xA, yA, xB, yB, xC, yC, xD, yD;
    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xC >> yC;
    cin >> xD >> yD;

    /// Calculeaza determinantul: inside (d > 0), outside (d < 0), boundary (d == 0)
    long long d = 0;

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

    if (d < 0) {
        cout << "AC: ILLEGAL\n";
    } else {
        cout << "AC: LEGAL\n";
    }

    /// Pentru a nu modifica prea mult in determinant, shiftam varfurile
    long long xPrimulA = xA, yPrimulA = yA;
    
    /// A devine B
    xA = xB;
    yA = yB;

    /// B devine C
    xB = xC;
    yB = yC;

    /// C devine D
    xC = xD;
    yC = yD;

    /// D devine A (cel initial)
    xD = xPrimulA;
    yD = yPrimulA;

    d -= xB*yC*(xD*xD+yD*yD) + xC*yD*(xB*xB+yB*yB) + xD*(xC*xC+yC*yC)*yB - (xB*xB+yB*yB)*yC*xD - (xC*xC+yC*yC)*yD*xB - (xD*xD+yD*yD)*xC*yB;
    d += xA*yC*(xD*xD+yD*yD) + xC*yD*(xA*xA+yA*yA) + xD*(xC*xC+yC*yC)*yA - (xA*xA+yA*yA)*yC*xD - (xC*xC+yC*yC)*yD*xA - (xD*xD+yD*yD)*xC*yA;
    d -= xA*yB*(xD*xD+yD*yD) + xB*yD*(xA*xA+yA*yA) + xD*(xB*xB+yB*yB)*yA - (xA*xA+yA*yA)*yB*xD - (xB*xB+yB*yB)*yD*xA - (xD*xD+yD*yD)*xB*yA;
    d += xA*yB*(xC*xC+yC*yC) + xB*yC*(xA*xA+yA*yA) + xC*(xB*xB+yB*yB)*yA - (xA*xA+yA*yA)*yB*xC - (xB*xB+yB*yB)*yC*xA - (xC*xC+yC*yC)*xB*yA;

    if (d < 0) {
        cout << "BD: ILLEGAL\n";
    } else {
        cout << "BD: LEGAL\n";
    }

    return 0;
}
