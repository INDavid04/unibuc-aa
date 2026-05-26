/// Intersectii de semiplane orizontale si verticale: https://cms.fmi.unibuc.ro/problem/l7pb3

#include <iostream>
#include <cmath>

using namespace std;

///////////////////
/// Rationament ///
///////////////////

/// Intersectia este un dreptunghi, adica avem patru puncte importante
/// xMinim = -INFINITY
/// xMaxim = +INFINITY
/// yMinim = -INFINITY
/// yMaxim = +INFINITY

/// Daca un interval este invalid (xMinim > xMaxim sau yMinim > yMaxim) atunci intersectia este vida, afisam VOID
/// Daca

//////////////////////
/// Exemplu (VOID) ///
//////////////////////

/// in
// 3
// 1 0 -1
// -1 0 2
// 0 1 3

/// out
// VOID

/// Avem trei semiplane
/// x - 1 <= 0
/// -x + 2 <= 0
/// y + 3 <= 0

/// Adica
/// x <= 1
/// x >= 2
/// y <= -3

/// xMinim = -INFINITY, 2
/// xMaxim = +INFINITY, 1
/// yMinim = -INFINITY
/// yMaxim = +INFINITY, -3

/// Intervalul [2,1] este invalid
/// Prin urmare intersectia este vida

///////////////////////////
/// Exemplu (UNBOUNDED) ///
///////////////////////////

/// in
// 3
// -1 0 1
// 1 0 -2
// 0 1 3

/// out
// UNBOUNDED

/// Avem trei semiplane
/// -x + 1 <= 0
/// x - 2 <= 0
/// y + 3 <= 0

/// Adica
/// x >= 1
/// x <= 2
/// y <= -3

/// xMinim = -INFINITY, 1
/// xMaxim = +INFINITY, 2
/// yMinim = -INFINITY
/// yMaxim = +INFINITY, -3

/// Deoarece intervalele sunt valide ([1,2] si (-INFINITY,-3]) si avem un interval nemarginit, afisam UNBOUNDED

/////////////////////////
/// Exemplu (BOUNDED) ///
/////////////////////////

/// in
// 4
// -1 0 1
// 1 0 -2
// 0 1 3
// 0 -2 -8

/// out
// BOUNDED

/// Avem
/// -x + 1 <= 0
/// x - 2 <= 0
/// y + 3 <= 0
/// -2y - 8 <= 0

/// Adica
/// x >= 1
/// x <= 2
/// y <= -3
/// y >= -4

/// xMinim = -INFINITY, 1
/// xMaxim = +INFINITY, 2
/// yMinim = -INFINITY, -4
/// yMaxim = +INFINITY, -3

/// Ambele intervale sunt valide, marginite, deci afisa BOUNDED

int main() {
    int n;
    double a, b, c;
    double xMinim = -INFINITY;
    double xMaxim = +INFINITY;
    double yMinim = -INFINITY;
    double yMaxim = +INFINITY;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;

        if (b == 0) {
            if (a < 0) {
                /// Avem ceva de forma ax >= -c
                if (-c / a > xMinim) {
                    xMinim = -c / a;
                }
            } else {
                /// Avem ceva de forma ax <= -c
                if (-c / a < xMaxim) {
                    xMaxim = -c / a;
                }
            }
        }

        if (a == 0) {
            if (b < 0) {
                /// Avem ceva de forma by >= -c
                if (-c / b > yMinim) {
                    yMinim = -c / b;
                }
            } else {
                /// Avem ceva de forma by <= -c
                if (-c / b < yMaxim) {
                    yMaxim = -c / b;
                }
            }
        }
    }

    if (xMinim <= xMaxim && yMinim <= yMaxim) {
        if (isinf(xMinim) || isinf(xMaxim) || isinf(yMinim) || isinf(yMaxim)) {
            cout << "UNBOUNDED\n";
        } else {
            cout << "BOUNDED\n";
        }
    } else {
        cout << "VOID\n";
    }

    return 0;
}
