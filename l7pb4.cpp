/// Pozitia unui punct fata de semiplane orizontale si verticale: https://cms.fmi.unibuc.ro/problem/l7pb4

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    /// Citeste numarul de semiplane
    int n;
    cin >> n;

    /// Citeste semiplanele
    double a, b, c;
    vector<double> liniiStanga, liniiDreapta, liniiSus, liniiJos;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        /// Clasifica liniile (stanga, dreapta, sus, jos)
        if (b == 0) {
            if (a > 0) {
                /// ax + c <= 0 i.e. x <= -c/a unde a > 0
                liniiDreapta.push_back(-c/a);
            } else {
                /// ax + c <= 0 i.e. x >= -c/a unde a < 0
                liniiStanga.push_back(-c/a);
            }
        } else if (a == 0) {
            if (b > 0) {
                /// by + c <= 0 i.e. y <= -c/b unde b > 0
                liniiSus.push_back(-c/b);
            } else {
                /// by + c <= 0 i.e. y >= -c/b unde b < 0
                liniiJos.push_back(-c/b);
            }
        }
    }

    /// Citeste numarul de puncte
    int m;
    cin >> m;

    /// Citeste punctele
    for (int i = 0; i < m; i++) {
        double xQ, yQ;
        cin >> xQ >> yQ;

        double aproapeStanga = -INFINITY, aproapeDreapta = +INFINITY, aproapeSus = +INFINITY, aproapeJos = -INFINITY;
        bool punctIlegal = false;

        /// Cauta cea mai aproape linie valida din partea stanga
        for (double linie : liniiStanga) {
            if (linie < xQ && linie > aproapeStanga) {
                aproapeStanga = linie;
            }
            if (linie >= xQ) {
                punctIlegal = true;
            }
        }

        /// Cauta cea mai apropiata linie valid din partea dreapta
        for (double linie : liniiDreapta) {
            if (linie > xQ && linie < aproapeDreapta) {
                aproapeDreapta = linie;
            }
            if (linie <= xQ) {
                punctIlegal = true;
            }
        }

        /// Cauta cea mai apropiata linie valida din partea de sus
        for (double linie : liniiSus) {
            if (linie > yQ && linie < aproapeSus) {
                aproapeSus = linie;
            }
            if (linie <= yQ) {
                punctIlegal = true;
            }
        }

        /// Cauta cea mai apropiata linie valida din partea de jos
        for (double linie : liniiJos) {
            if (linie < yQ && linie > aproapeJos) {
                aproapeJos = linie;
            }
            if (linie >= yQ) {
                punctIlegal = true;
            }
        }

        /// Daca dreptunghiul este nemarginit afisam no (i.e. nu am gasit o linie valida intr-o directie), altfel inseamna ca dreptunghiul este valid si ii calculam aria
        if (punctIlegal || isinf(aproapeStanga) || isinf(aproapeDreapta) || isinf(aproapeSus) || isinf(aproapeJos)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            printf("%.6f\n", (aproapeDreapta - aproapeStanga) * (aproapeSus - aproapeJos));
        }
    }
    
    return 0;
}
