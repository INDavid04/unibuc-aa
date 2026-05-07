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
    index_stang = n - 1;
    index_drept = n;

    /// Citeste primele trei puncte
    cin >> punct1.x >> punct1.y;
    cin >> punct2.x >> punct2.y;
    cin >> punct3.x >> punct3.y;
    numar_puncte_citite = 3;

    /// In caz de coliniaritate a primelor puncte
    do {
        cin >> punct3.x >> punct3.y;
        numar_puncte_citite++;
    } while (determinant(punct1.x, punct2.x, punct3.x, punct1.y, punct2.y, punct3.y) == 0);

    /// In caz de viraj stanga cu primele trei puncte
    if (determinant(punct1.x, punct2.x, punct3.x, punct1.y, punct2.y, punct3.y) > 0) {
        /// Pune primul punct in dreapta
        puncte[index_drept].x = punct1.x;
        puncte[index_drept].y = punct1.y;
        index_drept++;

        /// Pune al doilea punct in dreapta
        puncte[index_drept].x = punct2.x;
        puncte[index_drept].y = punct2.y;
        index_drept++;

        /// Pune al treilea punct in dreapta
        puncte[index_drept].x = punct3.x;
        puncte[index_drept].y = punct3.y;
        index_drept++;

        /// Inchide triughiul cu al treilea punct in stanga (p3, p1, p2, p3)
        puncte[index_stang].x = punct3.x;
        puncte[index_stang].y = punct3.y;
        index_stang--;
    }

    /// In caz de viraj dreapta cu primele trei puncte
    if (determinant(punct1.x, punct2.x, punct3.x, punct1.y, punct2.y, punct3.y) < 0) {
        /// Pune primul punct in stanga
        puncte[index_stang].x = punct1.x;
        puncte[index_stang].y = punct1.y;
        index_stang--;

        /// Pune al doilea punct in stanga
        puncte[index_stang].x = punct2.x;
        puncte[index_stang].y = punct2.y;
        index_stang--;

        /// Pune al treilea punct in stanga
        puncte[index_stang].x = punct3.x;
        puncte[index_stang].y = punct3.y;
        index_stang--;

        /// Inchide triunghiul cu al treilea punct in dreapta (p3, p2, p1, p3)
        puncte[index_drept].x = punct3.x;
        puncte[index_drept].y = punct3.y;
        index_drept++;
    }

    /// Citeste restul punctelor
    for (int i = numar_puncte_citite; i < n; i++) {
        cin >> curent.x >> curent.y;
    }
    
    /// Afiseaza numarul de puncte si punctele
    cout << "\n" << index << "\n";
    for (int i = 0; i < index; i++) {
        cout << puncte[i].x << " " << puncte[i].y << "\n";
    }
    
    return 0;
}
