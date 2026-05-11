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

void cautare_binara(Punct R, Punct puncte_poligon[], int nr_puncte_poligon) {
    /// Daca e la stanga primei laturi sau la dreapta ultimei laturi, e in afara
    if (determinant(puncte_poligon[0], puncte_poligon[1], R) < 0 || determinant(puncte_poligon[0], puncte_poligon[nr_puncte_poligon-1], R) > 0) {
        cout << "OUTSIDE\n";
        return;
    }
    
    /// Daca este chiar pe una din cele doua laturi
    if (determinant(puncte_poligon[0], puncte_poligon[1], R) == 0) {
        /// Verific sa fie pe segment, adica R sa fie intre celelalte doua puncte
        if (R.x >= min(puncte_poligon[0].x, puncte_poligon[1].x) && R.x <= max(puncte_poligon[0].x, puncte_poligon[1].x) && R.y >= min(puncte_poligon[0].y, puncte_poligon[1].y) && R.y <= max(puncte_poligon[0].y, puncte_poligon[1].y)) {
            cout << "BOUNDARY\n";
        } else {
            cout << "OUTSIDE\n";
            /// Se poate intampla sa fie pe o prelungire a unei dintre laturi, caz in care punctul este afara
        }
        return;
    }
    if (determinant(puncte_poligon[0], puncte_poligon[nr_puncte_poligon-1], R) == 0) {
        if (R.x >= min(puncte_poligon[0].x, puncte_poligon[nr_puncte_poligon-1].x) && R.x <= max(puncte_poligon[0].x, puncte_poligon[nr_puncte_poligon-1].x) && R.y >= min(puncte_poligon[0].y, puncte_poligon[nr_puncte_poligon-1].y) && R.y <= max(puncte_poligon[0].y, puncte_poligon[nr_puncte_poligon-1].y)) {
            cout << "BOUNDARY\n";
        } else {
            cout << "OUTSIDE\n";
        }
        return;
    }

    /// Cauta triughiul
    int dreapta = 1, stanga = nr_puncte_poligon - 1;
    while (dreapta + 1 < stanga) {
        int mijloc = (dreapta + stanga) / 2;
        if (determinant(puncte_poligon[0], puncte_poligon[mijloc], R) >= 0) {
            dreapta = mijloc; /// viraj stanga
        } else {
            stanga = mijloc; /// viraj dreapta
        }
    }

    /// Vezi pozitia punctului in triughiul final
    if (determinant(puncte_poligon[dreapta], puncte_poligon[stanga], R) < 0) {
        cout << "OUTSIDE\n";
    } else if (determinant(puncte_poligon[dreapta], puncte_poligon[stanga], R) > 0) {
        cout << "INSIDE\n";
    } else {
        /// Verific sa fie pe segment, adica R sa fie intre celelalte doua puncte
        if (R.x >= min(puncte_poligon[dreapta].x, puncte_poligon[stanga].x) && R.x <= max(puncte_poligon[dreapta].x, puncte_poligon[stanga].x) && R.y >= min(puncte_poligon[dreapta].y, puncte_poligon[stanga].y) && R.y <= max(puncte_poligon[dreapta].y, puncte_poligon[stanga].y)) {
            cout << "BOUNDARY\n";
        } else {
            cout << "OUTSIDE\n";
        }
    }
}

int main() {
    /// Stim deja ca punctele sunt date in ordine trigonometrica
    /// Prin urmare:
    /// Daca pentru un punct:
    /// Toate virajele sunt la stanga => INSIDE
    /// Exista trei puncte coliniare => BOUNDARY
    /// Exista un viraj dreapta => OUTSIDE
    /// Pentru complexitate O(mlogn) folosim cautare binara

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
        cautare_binara(puncte_plan[i], puncte_poligon, n);
    }

    return 0;
}
