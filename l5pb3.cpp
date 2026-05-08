#include <iostream>

using namespace std;

struct Punct { long long x, y; };

long long determinant (long long x1, long long x2, long long x3, long long y1, long long y2, long long y3) {
    return x2*y3 + x1*y2 + y1*x3 - x2*y1 - x3*y2 - y3*x1;
}

int main() {
    /// Declarari
    long long n, index_stang, index_drept, numar_puncte_citite;
    Punct puncte[200007], curent, punct1, punct2, punct3;

    /// Citeste numarul de puncte al poligonului
    cin >> n;
    index_stang = n;
    index_drept = n;

    /// Citeste primele doua puncte
    cin >> punct1.x >> punct1.y;
    cin >> punct2.x >> punct2.y;
    numar_puncte_citite = 2;

    /// Citeste alte puncte cat timp primele trei sunt coliniare
    do {
        cin >> punct3.x >> punct3.y;
        numar_puncte_citite++;
    } while (determinant(punct1.x, punct2.x, punct3.x, punct1.y, punct2.y, punct3.y) == 0);

    /// In caz de viraj stanga cu primele trei puncte
    if (determinant(punct1.x, punct2.x, punct3.x, punct1.y, punct2.y, punct3.y) > 0) {
        /// Ordinea punctelor este deja in sensul invers al acelor de ceasornic
        puncte[index_drept++] = punct3;
        puncte[index_drept++] = punct1;
        puncte[index_drept++] = punct2;
        puncte[index_drept++] = punct3;
    }

    /// In caz de viraj dreapta cu primele trei puncte
    if (determinant(punct1.x, punct2.x, punct3.x, punct1.y, punct2.y, punct3.y) < 0) {
        /// Ordinea punctelor este in sensul acelor de ceasornic, prin urmare, inversam
        puncte[index_drept++] = punct3;
        puncte[index_drept++] = punct2;
        puncte[index_drept++] = punct1;
        puncte[index_drept++] = punct3;
    }

    // cout << "\ndebug: vezi primele trei puncte, triughiul initial\n";
    // for (int i = index_stang; i < index_drept; i++) {
    //     cout << puncte[i].x << " " << puncte[i].y << "\n";
    // }

    /// Citeste restul punctelor
    for (int i = numar_puncte_citite; i < n; i++) {
        /// Pe input de mai jos avem:
        /// - Triughiul
        ///     -5 0
        ///     -1 1
        ///     0 3
        ///     -5 0
        /// - Inputul fiind
        ///     10
        ///     0 3
        ///     -1 1
        ///     -5 0
        ///     -2 -1
        ///     -4 -5
        ///     1 -2
        ///     5 -3
        ///     3 0
        ///     6 3
        ///     2 2
        /// Adica C, B, A, C
        /// Il citim pe D(-2,-1) si avem
        /// -   ACD viraj stanga
        /// -   DCB viraj dreapta
        /// Deoarece avem un viraj dreapta, il scoatem pe C de la inceputul listei
        cin >> curent.x >> curent.y;

        /// Daca punctul curent este in interior
        if (determinant(puncte[index_drept - 2].x, puncte[index_drept - 1].x, curent.x, puncte[index_drept - 2].y, puncte[index_drept - 1].y, curent.y) > 0 && determinant(curent.x, puncte[index_stang].x, puncte[index_stang + 1].x, curent.y, puncte[index_stang].y, puncte[index_stang + 1].y) > 0) {
            /// Nu se schimba nimic. Se citeste urmatorul punct
        } else {
            /// Scoate ultimul punct pana cand obtii neaparat un viraj stanga
            while (determinant(puncte[index_drept - 2].x, puncte[index_drept - 1].x, curent.x, puncte[index_drept - 2].y, puncte[index_drept - 1].y, curent.y) <= 0) {
                index_drept--;
            }
            /// Pune punctul curent la final
            puncte[index_drept++] = curent;

            /// Scoate primul punct pana cand obtii un viraj stanga
            while (determinant(curent.x, puncte[index_stang].x, puncte[index_stang + 1].x, curent.y, puncte[index_stang].y, puncte[index_stang + 1].y) <= 0) {
                index_stang++;
            }
            /// Pune punctul curent la inceput
            puncte[--index_stang] = curent;
        }
    }
    
    /// Afiseaza numarul de puncte si punctele
    cout << index_drept - index_stang - 1 << "\n";
    for (int i = index_stang; i < index_drept - 1; i++) {
        cout << puncte[i].x << " " << puncte[i].y << "\n";
    }
    
    return 0;
}
