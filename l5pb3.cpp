#include <iostream>

using namespace std;

struct Punct { long long x, y; };

int main() {
    long long nrVarfuri, indice = 0;
    Punct p[100007];
    Punct acoperireConvexa[10100007];

    cin >> nrVarfuri;

    for (int i = 0; i < nrVarfuri; i++) {
        cin >> p[i].x >> p[i].y;
    }

    acoperireConvexa[indice].x = p[indice].x;
    acoperireConvexa[indice].y = p[indice].y;
    indice++;
    acoperireConvexa[indice].x = p[indice].x;
    acoperireConvexa[indice].y = p[indice].y;
    indice++;

    for (int i = 2; i < nrVarfuri; i++) {
        long long determinant = p[i-1].x*p[i].y + p[i].x*p[i-2].y + p[i-1].y*p[i-2].x - p[i-2].y*p[i-1].x - p[i-1].y*p[i].x - p[i].y*p[i-2].x;
        if (determinant > 0) {
            acoperireConvexa[indice].x = p[i].x;
            acoperireConvexa[indice].y = p[i].y;
            indice++;
        }
    }

    cout << "\n" << indice << "\n";
    for (int i = 0; i < indice; i++) {
        cout << acoperireConvexa[i].x << " " << acoperireConvexa[i].y << "\n";
    }

    return 0;
}
