/// Pozitia unui punct fata de un poligon: https://cms.fmi.unibuc.ro/problem/l6pb2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Punct { long long x, y; };

/// Returneaza 0 daca sunt coliniare, < 0 la viraj dreapta si > 0 la viraj stanga
long long determinant(Punct A, Punct B, Punct C) {
    /// | 1 A.x A.y |   | 1 A.x     A.y     |
    /// | 1 B.x B.y | ~ | 0 B.x-A.x B.y-A.y | = (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x)
    /// | 1 C.x C.y |   | 0 C.x-A.x C.y-A.y |

    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}

/// Returneaza true daca P e pe segmentul AB, false altfel
bool ePeSegment(Punct A, Punct B, Punct P) {
    if (determinant(A, B, P) == 0 && P.x <= max(A.x, B.x) && P.x >= min(A.x, B.x) && P.y <= max(A.y, B.y) && P.y >= min(A.y, B.y)) {
        return true;
    } else {
        return false;
    }
}

/// Afiseaza pozitia punctului P fata de poligon
void afiseazaPozitia(const vector<Punct>& poligon, Punct P) {
    int n = poligon.size(), nr_intersectari = 0;

    for (int i = 0; i < n; i++) {
        Punct A = poligon[i];
        Punct B = poligon[(i + 1) % n];

        /// Verifica daca e pe margine
        if (ePeSegment(A, B, P)) {
            cout << "BOUNDARY\n";
            return;
        }

        /// Numara intersectarile cu raza orizontala (algoritmul ray casting)
        if (((A.y > P.y) != (B.y > P.y)) && (P.x < (double)(B.x - A.x) * (P.y - A.y) / (B.y - A.y) + A.x)) {
            nr_intersectari++;
        }
    }

    if (nr_intersectari % 2 == 1) {
        cout << "INSIDE\n";
    } else {
        cout << "OUTSIDE\n";
    }
}

int main() {
    /// Citeste punctele poligonului
    int n;
    cin >> n;
    vector<Punct> poligon(n);
    for (int i = 0; i < n; i++) {
        cin >> poligon[i].x >> poligon[i].y;
    }

    /// Citeste punctele a caror pozitie fata de poligon se doreste
    int m;
    cin >> m;
    vector<Punct> puncte(m);
    for (int i = 0; i < m; i++) {
        cin >> puncte[i].x >> puncte[i].y;
    }

    /// Afiseaza pozitia punctului fata de poligon
    for (int i = 0; i < m; i++) {
        afiseazaPozitia(poligon, puncte[i]);
    }

    return 0;
}
