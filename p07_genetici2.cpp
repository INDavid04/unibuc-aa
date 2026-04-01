/// https://cms.fmi.unibuc.ro/problem/genetici2

//////////
/// IN ///
//////////

/// -1 4 -1 (a, b, c, i.e. coeficientii functiei f(x) = ax^2 + bx + c, cu a < 0) 
/// 3 (n, i.e. numarul de intervale, afisam n + 1 valori, adica respectivele capete)
/// 1 1.5 2.5 (x_1, ..., x_n, i.e. valoarea codificata de cromozomul i cu i de la 0 la n-1)

///////////
/// OUT ///
///////////

/// 0.000000 (capatul stang al primului interval)
/// 0.266666 (capatul drept al primului interval, capatul stang al celui de al doilea)
/// 0.633333 (capatul drept al celui de al doilea, capatul drept al celui de al treilea)
/// 1.000000 (capatul drept al celui de al treilea interval)

//////////////////
/// Explicatie ///
//////////////////

/// f(x) = ax^2 + bx + c = -x^2 + 4x - 1 (functia pe care vrem sa o maximizam)
/// f0 = f(x_0) = f(1) = -1 + 4 - 1 = 2
/// f1 = f(x_1) = f(1.5) = -2.25 + 6 - 1 = 2.75
/// f2 = f(x_2) = f(2.5) = -6.25 + 10 - 1 = 2.75
/// F = f1 + f2 + f3 = 2 + 2.75 + 2.75 = 7.5 (fitnessul total al populatiei)
/// p0 = 0 / 7.5 = 0
/// p1 = 2 / 7.5 = 0.26
/// p2 = (2 + 2.75) / 7.5 = 0.63
/// p3 = (2 + 2.75 + 2.75) / 7.5 = 1

#include <iostream>

using namespace std;

int main() {
    /// Coeficientii functiei
    int a, b, c;
    cin >> a >> b >> c;

    /// Numarul de intervale
    int n;
    cin >> n;

    /// Valorile codificate
    float x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    /// Valorile de fitness
    float f[n];
    for (int i = 0; i < n; i++) {
        f[i] = a * x[i] * x[i] + b * x[i] + c;
    }

    /// Fitnessul total
    float F = 0;
    for (int i = 0; i < n; i++) {
        F += f[i];
    }

    /// Sumele partiale
    float p[n + 1];
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        float numarator = 0;
        for (int j = 0; j < i; j++) {
            numarator += f[j];
        }
        p[i] = numarator / F;
    }
    p[n] = 1;

    /// Intervalele
    for (int i = 0; i < n + 1; i++) {
        cout << p[i] << "\n";
    }

    return 0;
}
