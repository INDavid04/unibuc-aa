#include <iostream>

using namespace std;

int main() {
    /// Declara variabile
    long long nrTeste, xP, yP, xQ, yQ, xR, yR;
    char mesaj[100007][7];

    /// Citeste numarul de teste (acel t din cerinta)
    cin >> nrTeste;

    /// Citeste coordonatele si calculeaza fiecare determinant comparandu-l cu zero
    for (int contor = 0; contor < nrTeste; contor++) {
        cin >> xP >> yP >> xQ >> yQ >> xR >> yR;
        int determinant = 1*xQ*yR + xP*yQ*1 + yP*xR*1 - 1*xQ*yP - xR*yQ*1 - yR*xP*1;
        if (determinant > 0) {
            mesaj[contor][0] = 'L';
            mesaj[contor][1] = 'E';
            mesaj[contor][2] = 'F';
            mesaj[contor][3] = 'T';
            mesaj[contor][4] = '\0';
        } else if (determinant < 0) {
            mesaj[contor][0] = 'R';
            mesaj[contor][1] = 'I';
            mesaj[contor][2] = 'G';
            mesaj[contor][3] = 'H';
            mesaj[contor][4] = 'T';
            mesaj[contor][5] = '\0';
        } else {
            mesaj[contor][0] = 'T';
            mesaj[contor][1] = 'O';
            mesaj[contor][2] = 'U';
            mesaj[contor][3] = 'C';
            mesaj[contor][4] = 'H';
            mesaj[contor][5] = '\0';
        }
    }

    /// Afiseaza mesajele corespunzatoare
    for (int contor = 0; contor < nrTeste; contor++) {
        int pozitie_litera = 0;
        while(mesaj[contor][pozitie_litera] != '\0') {
            cout << mesaj[contor][pozitie_litera];
            pozitie_litera++;
        }
        cout << "\n";
    }

    return 0;
}
