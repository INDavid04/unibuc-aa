/// Punct in poligon convex: https://cms.fmi.unibuc.ro/problem/l6pb1

#include <iostream>

using namespace std;

struct Punct { long long x, y; };

long long determinant (Punct A, Punct B, Punct C) {
    /// Conform cursului
    /// | 1 xA yA |   | 1 xA    yA    |
    /// | 1 xB yB | ~ | 0 xB-xA yB-yA | = (xB-xA)(yC-yA) - (yB-yA)(xC-xA)
    /// | 1 xC yC |   | 0 xC-xA yC-yA |

    return (B.x - A.x)*(C.y - A.y) - (B.y - A.y)*(C.x - A.x);
}

int main() {
    /// Stim deja ca punctele sunt date in ordine trigonometrica
    /// Prin urmare:
    /// Daca pentru un punct:
    /// Toate virajele sunt la stanga => INSIDE
    /// Exista trei puncte coliniare => BOUNDARY
    /// Exista un viraj dreapta => OUTSIDE

    int n, m; /// nr varfuri date in ordine trigonometrica, nr puncte in plan
    Punct puncte_poligon[100007], puncte_plan[100007];

    /// Citeste punctele poligonului
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> puncte_poligon[i].x >> puncte_poligon[i].y;
    }

    /// Citeste punctele din plan a caror pozitie fata de poligon se doreste aflata
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> puncte_plan[i].x >> puncte_plan[i].y;
    }

    /// Afiseaza rezultatul
    for (int i = 0; i < m; i++) {
        int rezultat = 0; /// by default 0, adica inside, de altfel 1 adica outside si 2 adica boundary
        for (int j = 0; j < n; j++) {
            long long det = determinant(puncte_poligon[j], puncte_poligon[(j+1) % n], puncte_plan[i]);
            if (det < 0) {
                rezultat = 1; /// outside
                break;
            }
            if (det == 0) {
                rezultat = 2; /// boundary
                break;
            }
        }
        if (rezultat == 0) {
            cout << "INSIDE\n";
        } else if (rezultat == 1) {
            cout << "OUTSIDE\n";
        } else {
            cout << "BOUNDARY\n";
        }
    }

    return 0;
}
