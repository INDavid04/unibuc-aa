#include <iostream>

using namespace std;

int main() {
    /// Declara punctele
    long long nrPuncte, x1, y1, x2, y2, x3, y3, x0, y0, left = 0, right = 0, touch = 0;

    /// Citeste numarul de puncte
    cin >> nrPuncte;

    /// Citeste primele doua puncte
    cin >> x1 >> y1 >> x2 >> y2;
    
    /// Retine primul punct (e nevoie la ultimul pas de ultimul punct)
    x0 = x1;
    y0 = y1;

    /// Pornim de la doi intrucat primele doua puncte le-am citit deja (i=0 si i = 1)
    for (long long i = 2; i < nrPuncte; i++) {
        cin >> x3 >> y3;
        long long determinant = x2*y3 + x1*y2 + y1*x3 - x2*y1 - x3*y2 - y3*x1;
        if (determinant > 0) {
            left++;
        } else if (determinant < 0) {
            right++;
        } else {
            touch++;
        }

        /// Primul punct devine al doilea
        x1 = x2;
        y1 = y2;

        /// Al doilea punct devine al treilea
        x2 = x3;
        y2 = y3;
    }

    /// Al treilea punct devine primul punct, cel initial
    x3 = x0;
    y3 = y0;

    long long determinant = x2*y3 + x1*y2 + y1*x3 - x2*y1 - x3*y2 - y3*x1;
    if (determinant > 0) {
        left++;
    } else if (determinant < 0) {
        right++;
    } else {
        touch++;
    }

    cout << "\n\n" << left << " " << right << " " << touch << "\n";

    return 0;
}
