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

void cautare_binara(Punct R, Pucnt puncte_poligon[], int nr_puncte_poligon) {
    /// Daca e la stanga primei laturi sau la dreapta ultimei laturi, e in afara
    long long det1 = determinant(puncte_poligon[0], puncte_poligon[1], R);
    long long det2 = determinant(puncte_poligon[0], puncte_poligon[n-1], R);
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

    for (int i = 0; i < m; i++) {
        cautare_binara();
    }

    return 0;
}
